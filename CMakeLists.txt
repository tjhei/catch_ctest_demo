cmake_minimum_required (VERSION 2.8.11)

project(catch_test)
add_executable (catch_test main.cc)

enable_testing()

add_custom_target( setup_tests
	COMMAND catch_test --list-test-names-only >testlist || true
	COMMAND ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR}
	DEPENDS catch_test
	)

IF(EXISTS testlist)
file(STRINGS testlist tests)
FOREACH(test ${tests})
	string(REPLACE " " "_" testname ${test})
	MESSAGE("adding test ${testname}")
	add_test( ${testname} catch_test ${test})
ENDFOREACH()
ELSE()
MESSAGE(" please run 'make setup_tests' to discover unit tests")
ENDIF()

#add_test( testname ./catch_test )
