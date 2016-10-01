cmake_minimum_required (VERSION 2.8)
project (dvo)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost COMPONENTS system filesystem program_options REQUIRED)

include_directories( "${Boost_INCLUDE_DIR}" )
#link_directories( "${Boost_LIBRARIES}" )

if(FALSE)
foreach(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
   if(${flag_var} MATCHES "/MD")
      string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
   endif(${flag_var} MATCHES "/MD")
endforeach(flag_var)
endif()

add_executable(
  dvo
  "./pch.cpp"
  "./dvo.cpp"
  "./base.cpp"
  "./component.cpp"
  "./workspace.cpp"
  "./appl.cpp"
)
target_link_libraries( dvo ${Boost_LIBRARIES} )
