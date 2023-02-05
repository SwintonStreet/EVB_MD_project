EVB MD
======

This is a project to create a classical MD suite with support for
reactions via EVB support.

Build
=====

Build dependencies,

* cmake/ctest 3.16 or higher
* googletest 1.12.1
* ninja 1.10 - optional
* pre-commit 3.0.4 - optional

You can build with any generator you want, however ninja is suggested.

```
mkdir build
cmake -B build -GNinja .
cd build
ninja EVB_MD
```

After build the project, you can run the tests, use the following,

```
cd build
ninja tests
```
