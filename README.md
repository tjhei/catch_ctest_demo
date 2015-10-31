# Catch CTest demo

This is a simple demo that generates a cmake target "setup_tests" that will
generate individual ctest tests for each
[Catch](https://github.com/philsquared/Catch) unittest in the current
executable. Using this approach, the running of the tests is relegated to
CTest. Advantages of this approach:

 - better integration with ctest and tools like cdash
 - parallel executiong of tests using ```ctest -j```

## To try:
```
  cmake .
  make setup_tests
  ctest -j8
```

## Notes:

  - CTest test names can not contain spaces so we are replacing them with
    underscores.
  - We problably need to sanitize other special characters in the test names.
  - It would be a good idea to put the test discovery into a CMake function
    that takes the executable name as a parameter.
