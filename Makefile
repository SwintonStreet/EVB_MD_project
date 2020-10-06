include makefile.include

.DELETE_ON_ERROR:
.NOTPARALLEL:
.PHONY: all           \
        $(EXECUTABLE) \
        clang         \
        debug         \
        clang-tidy    \
        clang-format  \
        unitTest      \
        compileTests  \
        cppCheck      \
        clean         \
        cleaner

default: all

all:
	@echo "Starting compilation"
	@echo "===================="
	@mkdir -p $(BUILDDIR) $(TARGETDIR)
	@find $(RESDIR)/ -type f | xargs -I {} cp {} $(TARGETDIR)
	$(MAKE) -f makefile.parallel objects
	@echo ""
	@echo "Objects done, now linking the program"
	@echo "====================================="
	$(CC) $(LDFLAGS) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	@echo "Compulation finished!"

# add the debug options!
debug: CFLAGS += -g
debug: all

# build with clang
clang: CC := clang++
clang: all

# build with clang-tidy
clang-tidy: CC := clang-tidy
clang-tidy:
	$(MAKE) -f makefile.parallel clang-tidy

# build with clang-format
clang-format: CC := clang-format
clang-format:
	$(MAKE) -f makefile.parallel clang-format

# compile and run tests
unitTest: compileTests $(RUN_TESTS)

# compile tests
compileTests:
	@echo "Starting test compilation"
	@echo "========================="
	$(MAKE) -f makefile.parallel tests
	@echo "Running tests"
	@echo "============="

# run the cppChecker
cppCheck:
	@echo "Running cppCheck now"
	./cppCheck.sh

# run tests
%.test:
	$(TESTSDIR)/$@
	@rm $(TESTSDIR)/$@

clean:
	@echo "Cleaning"
	@$(RM) -rf $(BUILDDIR)

cleaner: clean
	@echo "Further cleaning"
	@$(RM) -rf $(TARGETDIR)

# export all variables set at the top layer
export

# Some notes about makefiles
# $@ left side of the :
# $^ right side of the :
# $< is the first term on the right of :
# $(SOURCE:.cc=.o) is a rule for the variable SOURCES
# to convert .cc to .o files and apply the rule defined
# by .cc.o

# DO NOT DELETE THIS LINE
