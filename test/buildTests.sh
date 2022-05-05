
cwd='.'

g++ -g test/NCursesTests.cpp src/utils/Timer.cpp -I$cwd/include -L$cwd/lib -lncurses -o launchTest
