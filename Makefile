CC:=g++
CC_VER_FLAG=-std=c++17
CFLAGS=-Werror                \
       -Wall                  \
       -Wextra                \
       -Wshadow               \
       -Wreorder              \
       -Wpedantic             \
       -Wimplicit-fallthrough \
       -Wempty-body           \
       -Wwrite-strings        \
       -Wno-parentheses       \
       -Warray-bounds         \
       -Weffc++               \
       $(CC_VER_FLAG)
CTESTFLAGS=-pthread
LDFLAGS=

TARGET     := EVB_MD
DEPEXT     := d
OBJEXT     := o
SRCEXT     := cc
SRCDIR     := src
BUILDDIR   := obj
RESDIR     := res
TARGETDIR  := bin
TESTSDIR   := tests
EXECUTABLE = $(TARGETDIR)/$(TARGET)

# To have multiple file locations you need to give the path to these
INCLUDE=$(patsubst %,-I./%,$(shell find $(SRCDIR) -mindepth 1 \
                                                  -type d     \
                                                  -not -name '*test*'))
INCLUDE_TEST=$(patsubst %,-I./%,$(shell find $(SRCDIR) -mindepth 1 -type d ))
SOURCES := $(shell find $(SRCDIR) -name "*$(SRCEXT)" | grep -v 'test' | sort)
SOURCES_TEST := $(shell find $(SRCDIR) -name "*$(SRCEXT)" | grep 'test' | \
                        sort | sed 's/\.cc/\.test/g')
RUN_TESTS := $(SOURCES_TEST:.test=.runTest)
OBJECTS=$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
OBJECTS_CLANG_TIDY=$(shell echo $(OBJECTS) | \
                           sed 's/\.o\(\s\?\)/.clangtidy\1/g' )
OBJECTS_CLANG_FORMAT=$(shell echo $(OBJECTS) | \
                             sed 's/\.o\(\s\?\)/.clangformat\1/g' )

# test compliation options
TEST_EXTRA_FLAGS = /usr/lib/libgtest.a -lm

default: all

all: startEcho $(EXECUTABLE)

# add the debug options!
debug: CFLAGS += -g
debug: all

.DELETE_ON_ERROR:

# build with clang
clang: CC := clang++
clang: all

# build with clang-tidy
clang-tidy: CC := clang-tidy
clang-tidy: $(OBJECTS_CLANG_TIDY)

# build with clang-format
clang-format: CC := clang-format
clang-format: $(OBJECTS_CLANG_FORMAT)

# run tests
unitTest: | startTestEcho $(SOURCES_TEST) $(RUN_TESTS)

# run the cppChecker
cppCheck:
	@echo "Running cppCheck now"
	./cppCheck.sh

printVar:
	@echo "Folders"
	@echo $(INCLUDE_TEST) | tr ' ' '\n'
	@echo "Sources"
	@echo $(SOURCES_TEST) | tr ' ' '\n'

startEcho:
	@echo "Starting compilation"
	@echo "===================="
	@mkdir -p $(BUILDDIR) $(TARGETDIR)
	@find $(RESDIR)/ -type f | xargs -I {} cp {} $(TARGETDIR)

startTestEcho: |
	@echo "Starting test compilation\n=========================" ; \
	 mkdir -p $(TESTSDIR)

objectsDone:
	@echo ""
	@echo "Objects done, now for the program!"
	@echo "=================================="

$(EXECUTABLE): $(OBJECTS) objectsDone
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	@echo "Compulation finished!"

#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

# needs hard tab :/ use <C-V><Tab> in insert mode
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@echo "Compiling $<"
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE)  -c $< -o $@
	@$(CC) $(CFLAGS) $(INCLUDE) -MM $(SRCDIR)/$*.$(SRCEXT) \
           > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp \
         > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | \
     sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp


# for clang-tidy
$(BUILDDIR)/%.clangtidy: $(SRCDIR)/%.$(SRCEXT)
	@echo $<
	$(CC) $< -checks=performance-*,readability-*,google-* -- $(CC_VER_FLAG) $(INCLUDE)

# for clang-format
$(BUILDDIR)/%.clangformat: $(SRCDIR)/%.$(SRCEXT)
	@echo $<
	$(CC) --verbose --Werror -i $<


# compiling tests
$(SRCDIR)/%.test: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(CTESTFLAGS) $(INCLUDE_TEST) $< $(TEST_EXTRA_FLAGS) \
          -o $(TESTSDIR)/$(notdir $@)

# run tests
$(SRCDIR)/%.runTest: $(SRCDIR)/%.test
	$(TESTSDIR)/$(notdir $<)
	@rm $(TESTSDIR)/$(notdir $<)

clean:
	@echo "Cleaning"
	@$(RM) -rf $(BUILDDIR)

cleaner: clean
	@echo "Further cleaning"
	@$(RM) -rf $(TARGETDIR)

# Some notes about makefiles
# $@ left side of the :
# $^ right side of the :
# $< is the first term on the right of :
# $(SOURCE:.cc=.o) is a rule for the variable SOURCES
# to convert .cc to .o files and apply the rule defined
# by .cc.o

# DO NOT DELETE THIS LINE
