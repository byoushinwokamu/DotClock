project(DotClock)
cmake_minimum_required(VERSION 3.22)

add_executable(
	main
	main.c
	src/matrix.c
	src/graphic.c
	src/print_dot.c
)
target_include_directories(
	main
	PUBLIC inc
)