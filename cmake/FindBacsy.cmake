# Written by Nathan Samson <nathansamson@gmail.com>, 2011
#
# License: Public domain.
#
# Defines
#
#  BACSY_INCLUDE_DIRS
#     which contains the include directory for bacsy/
#
#  BACSY_LIBRARIES
#     which contains the library directory for libbacsy
#

find_path(BACSY_INCLUDE_DIR bacsy/BacsyServer.h
                 PATH_SUFFIXES include1)

find_library(BACSY_LIBRARY bacsy
                 PATH_SUFFIXES lib)

find_package(Poco REQUIRED COMPONENTS Util Net)
find_package(rsync REQUIRED)
message("${RSYNC_LIBRARIES}")


set(BACSY_INCLUDE_DIRS ${BACSY_INCLUDE_DIR} ${POCO_INCLUDE_DIRS} ${RSYNC_INCLUDE_DIRS})
set(BACSY_LIBRARIES ${BACSY_LIBRARY} ${POCO_LIBRARIES} ${RSYNC_LIBRARIES})

message(${BACSY_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Bacsy DEFAULT_MSG
                                        BACSY_LIBRARIES
                                        BACSY_INCLUDE_DIRS)
