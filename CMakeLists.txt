cmake_minimum_required(VERSION 3.13)

project(main VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-fPIC -Wpedantic -Wno-deprecated-declarations -O3")

# to add a new Tool define source path here
file(GLOB_RECURSE SRC_FILES 
   ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp 
   ${CMAKE_CURRENT_SOURCE_DIR}/UserTools/Factory/*.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/UserTools/MyFirstTool/*.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/UserTools/SlowControl/*.cpp
)
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC $ENV{TOOLDAQ_INCDIR})

# to add a new Tool define include path here
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/UserTools/MyFirstTool)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/UserTools/SlowControl)

add_library(ToolDAQChain SHARED IMPORTED)
set_target_properties(ToolDAQChain PROPERTIES
   IMPORTED_LOCATION "$ENV{TOOLDAQ_LIBDIR}/libToolDAQChain.so"
   INTERFACE_INCLUDE_DIRECTORIES "$ENV{TOOLDAQ_INCDIR}"
)

add_library(Store SHARED IMPORTED)
set_target_properties(Store PROPERTIES
   IMPORTED_LOCATION "$ENV{TOOLDAQ_LIBDIR}/libStore.so"
   INTERFACE_INCLUDE_DIRECTORIES "$ENV{TOOLDAQ_INCDIR}"
)

add_library(DataModel SHARED IMPORTED)
set_target_properties(DataModel PROPERTIES
   IMPORTED_LOCATION "$ENV{TOOLDAQ_LIBDIR}/libDataModel.so"
   INTERFACE_INCLUDE_DIRECTORIES "$ENV{TOOLDAQ_INCDIR}"
)

target_link_libraries(${PROJECT_NAME} PUBLIC ToolDAQChain)
target_link_libraries(${PROJECT_NAME} PUBLIC Store)
target_link_libraries(${PROJECT_NAME} PUBLIC DataModel)

find_package(ZeroMQ REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC zmq)

find_package(Boost REQUIRED COMPONENTS serialization)
target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC ${Boost_SERIALIZATION_LIBRARY})
