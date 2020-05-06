#!/bin/bash
#

cppcheck --enable=all --inconclusive --std=posix ./src 2> cppCheck.output
