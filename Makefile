CC=g++
CFLAGS=-Wall                  \
       -Wextra                \
       -Wshadow               \
       -Wreorder              \
       -Wpedantic             \
       -Wimplicit-fallthrough \
       -Wempty-body           \
       -Werror                \
       -std=c++17
LDFLAGS=

TARGET     := EVB_MD
DEPEXT     := d
OBJEXT     := o
SRCEXT     := cc
SRCDIR     := src
BUILDDIR   := obj
RESDIR     := res
TARGETDIR  := bin
EXECUTABLE = $(TARGETDIR)/$(TARGET)

# To have multiple file locations you need to give the path to these
INCLUDE=$(patsubst %,-I./%,$(shell find $(SRCDIR) -mindepth 1 -type d))
SOURCES := $(shell find $(SRCDIR) -name "*$(SRCEXT)"| sort)
OBJECTS=$(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))
#OBJECTSCLEAN := $(shell echo $(SOURCES) | sed 's/\s/\n/g' | sed 's|^.*\(/[^/]*\)$(SRCEXT)$$|$(BUILDDIR)\1$(OBJEXT)|g' | awk 1 ORS=' ' )


default: all


all: startEcho $(SOURCES)  $(EXECUTABLE)

# add the debug options!
debug: CFLAGS += -g
debug: all


startEcho:
	@echo "Starting compilation"
	@echo "===================="
	@mkdir -p $(BUILDDIR) $(TARGETDIR)
	@find $(RESDIR)/ -type f | xargs -I {} cp {} $(TARGETDIR)

objectsDone:
	@echo ""
	@echo "Objects done, now for the program!"
	@echo "=================================="

$(EXECUTABLE): $(OBJECTS) objectsDone
	$(CC) $(CFLAGS) $(OBJECTS) \
    -o $(EXECUTABLE)
	@echo "Compulation finished!"

#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

# needs hard tab :/ use <C-V><Tab> in insert mode
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE)  -c $< -o $@
	@$(CC) $(CFLAGS) $(INCLUDE) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp


clean:
	@$(RM) -rf $(BUILDDIR)

cleaner: clean
	@$(RM) -rf $(TARGETDIR)

# Some notes about makefiles
# $@ left side of the :
# $^ right side of the :
# $< is the first term on the right of :
# $(SOURCE:.cc=.o) is a rule for the variable SOURCES
# to convery .cc to .o files and apply the rule defined
# by .cc.o



# DO NOT DELETE THIS LINE
