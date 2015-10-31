CMAKE_MINIMUM_REQUIRED (VERSION 2.8.11)

PROJECT(catch_test)
ADD_EXECUTABLE(catch_test main.cc)

ENABLE_TESTING()

ADD_CUSTOM_TARGET(setup_tests
	COMMAND catch_test --list-test-names-only >testlist || true
	COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}
	DEPENDS catch_test
	)

IF(EXISTS testlist)
  FILE(STRINGS testlist tests)
  FOREACH(test ${tests})
    STRING(REPLACE " " "_" testname ${test})
    MESSAGE("adding test ${testname}")
    ADD_TEST( ${testname} catch_test ${test})
  ENDFOREACH()
ELSE()
  MESSAGE(" please run 'make setup_tests' to discover unit tests")
ENDIF()
