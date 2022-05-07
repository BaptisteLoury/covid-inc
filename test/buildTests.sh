
cwd='.'

g++ -g test/NCursesTests.cpp src/model/Virus.cpp src/model/Severity.cpp src/utils/Timer.cpp -I$cwd/include -L$cwd/lib -lncurses -o launchTest
