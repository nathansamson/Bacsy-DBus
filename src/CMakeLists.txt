set(BACSY_DBUS_SOURCES main
                       BacsyClient
                       BacsyServer)

find_package(DBusCpp REQUIRED)
include_directories(${DBUSCPP_INCLUDE_DIR})

find_package(Bacsy REQUIRED)
include_directories(${BACSY_INCLUDE_DIRS})

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/bacsy-glue.h
    COMMAND dbusxx-xml2cpp ${CMAKE_CURRENT_SOURCE_DIR}/bacsy-introspect.xml
            --adaptor=${CMAKE_CURRENT_BINARY_DIR}/bacsy-glue.h
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/bacsy-introspect.xml
)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(bacsy-dbus ${BACSY_DBUS_SOURCES}
                          ${CMAKE_CURRENT_BINARY_DIR}/bacsy-glue.h)
target_link_libraries(bacsy-dbus ${DBUSCPP_LIBRARIES} ${BACSY_LIBRARIES})
