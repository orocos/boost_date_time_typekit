find_package(Boost REQUIRED COMPONENTS unit_test_framework)

if(ENABLE_CORBA AND OROCOS-RTT_CORBA_FOUND)
  orocos_executable(test_corba_transport test_corba_transport.cpp)
  target_link_libraries(test_corba_transport
    ${OROCOS-RTT_CORBA_LIBRARIES}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARIES}
  )
  add_test(NAME test_corba_transport COMMAND test_corba_transport)
  set_tests_properties(test_corba_transport
    PROPERTIES ENVIRONMENT RTT_COMPONENT_PATH=${ORO_TYPEKIT_OUTPUT_DIRECTORY}/../..
  )
endif()
