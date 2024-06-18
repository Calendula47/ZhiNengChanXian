# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ZhiNengChanXian_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ZhiNengChanXian_autogen.dir\\ParseCache.txt"
  "ZhiNengChanXian_autogen"
  )
endif()
