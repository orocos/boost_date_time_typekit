orocos_typekit(boost_date_time_transport_corba boostDateTimeCorbaTransport.cpp)
target_link_libraries(boost_date_time_transport_corba ${OROCOS-RTT_CORBA_LIBRARIES})

install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/include/orocos/${PROJECT_NAME}/transports/corba/
  DESTINATION include/orocos/${PROJECT_NAME}/transports/corba/
)
