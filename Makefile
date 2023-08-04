main:
	g++ -std=c++14 -Werror -Wuninitialized -o test-unit/test src/*.cpp
	test-unit/test

test:
	g++ -std=c++14 -Werror -Wuninitialized -o test-unit/test src/*.cpp test-unit/test.cpp
	test-unit/test

test_v:
	g++ -std=c++14 -Werror -Wuninitialized -o test-unit/test src/*.cpp test-unit/test.cpp
	valgrind -s --leak-check=yes test-unit/test

test_d:
	g++ -std=c++14 -Werror -Wuninitialized -o -g test-unit/test src/*.cpp test-unit/test.cpp
	gdb test-unit/test
