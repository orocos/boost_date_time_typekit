cmake_minimum_required(VERSION 2.8.3)

project(boost_date_time_typekit)

# Defines the orocos_* cmake macros. See that file for additional
# documentation.
find_package(OROCOS-RTT REQUIRED)
include(${OROCOS-RTT_USE_FILE_PATH}/UseOROCOS-RTT.cmake)

find_package(Boost REQUIRED COMPONENTS date_time)

include_directories(
  include/orocos
  ${Boost_INCLUDE_DIRS}
)

link_directories(
  include/orocos
  ${Boost_LIBRARY_DIRS}
)

orocos_typekit(${PROJECT_NAME}
  src/boostDateTimeTypekit.cpp
  src/boostDateTimeTypekitSpecialValues.cpp
  src/boostDateTimeTypekitPtime.cpp
  src/boostDateTimeTypekitTimeDuration.cpp
  )

target_link_libraries(
  ${PROJECT_NAME} 
  ${Boost_LIBRARIES}
)

install(
  FILES include/orocos/${PROJECT_NAME}/typekit/Types.hpp
  DESTINATION include/orocos/${PROJECT_NAME}/typekit
  RENAME Types.hpp
)

if(ENABLE_CORBA AND OROCOS-RTT_CORBA_FOUND)
  add_subdirectory(src/corba)
endif()

orocos_generate_package()

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(test)
endif()
