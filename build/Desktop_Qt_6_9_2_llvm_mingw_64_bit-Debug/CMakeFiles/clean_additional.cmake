# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LLM-RPG_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LLM-RPG_autogen.dir\\ParseCache.txt"
  "LLM-RPG_autogen"
  )
endif()
