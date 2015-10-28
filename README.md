# catch_ctest_demo

simple demo that generates a cmake target "setup_tests" that will generate
individual ctest tests for each catch unittest in the current executable. To try:
```
  cmake .
  make setup_tests
  ctest -j8
```
