TARGET = launch

CC = g++ -g

OUTDIR = ./bin
SUBDIR = core view controller model utils
DIR_OBJ = ./obj

INCS = $(wildcard *.hpp $(foreach fd, $(addprefix include/, $(SUBDIR)), $(fd)/*.hpp))
SRCS = $(wildcard *.cpp $(foreach fd, $(addprefix src/, $(SUBDIR)), $(fd)/*.cpp))
#OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:cpp=o)) # obj/xxx.o obj/folder/xxx .o
OBJS = $(SRCS:src/%.cpp=obj/%.o)
INC_DIRS = $(addprefix -Iinclude/, $(SUBDIR))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) -I./include -L./lib -lncurses

$(DIR_OBJ)/%.o: src/%.cpp $(INCS)
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS) $(INC_DIRS)  -I./include -L./lib -lncurses
