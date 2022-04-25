
cwd='.'

g++ -g $(find $cwd/src -name *.cpp) -I$cwd/include -L$cwd/lib -lncurses -o $cwd/launch
