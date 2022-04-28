
cwd='.'

g++ -g test/NCursesTests.cpp -I$cwd/include -L$cwd/lib -lncurses -o launchTest
