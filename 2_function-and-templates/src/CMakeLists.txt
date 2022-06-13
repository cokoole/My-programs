cmake_minimum_required(VERSION 3.21)

project("main" VERSION 0.1)

add_executable(main main.cpp ../include/Handler.inl ../include/OneParameter.h ../include/TwoParameter.h ../include/OneParameter.inl ../include/TwoParameter.inl ../include/Handler.h )
target_include_directories(main PUBLIC ${CMAKE_SOURCE_DIR}/include/)
