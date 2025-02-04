# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CustomProductSystem_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CustomProductSystem_autogen.dir\\ParseCache.txt"
  "CustomProductSystem_autogen"
  )
endif()
