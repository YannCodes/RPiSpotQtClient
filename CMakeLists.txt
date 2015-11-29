cmake_minimum_required(VERSION 2.6)
project(rpispotqtclient)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(RPiSpotQtClient_SRCS RPiSpotQtClient.cpp main.cpp)

qt4_automoc(${RPiSpotQtClient_SRCS})
add_executable(rpispotqtclient ${RPiSpotQtClient_SRCS})
target_link_libraries(rpispotqtclient ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTNETWORK_LIBRARY})

install(TARGETS rpispotqtclient RUNTIME DESTINATION bin)
