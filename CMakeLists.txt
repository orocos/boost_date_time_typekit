cmake_minimum_required(VERSION 2.8.3)

project(boost_date_time_typekit)

# Defines the orocos_* cmake macros. See that file for additional
# documentation.
find_package(OROCOS-RTT REQUIRED)
include(${OROCOS-RTT_USE_FILE_PATH}/UseOROCOS-RTT.cmake)

find_package(Boost REQUIRED COMPONENTS date_time)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

orocos_typekit(${PROJECT_NAME}
  src/boostDateTimeTypekit.cpp
  src/boostDateTimeTypekitSpecialValues.cpp
  src/boostDateTimeTypekitPtime.cpp
  src/boostDateTimeTypekitTimeDuration.cpp
  )

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

install(
  FILES src/boostDateTimeTypekitTypes.hpp
  DESTINATION include/orocos/boost_date_time_typekit/typekit
  RENAME Types.hpp
)

orocos_generate_package()
