CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=shape
DEPENDENCY2=ball
DEPENDENCY3=rectangle
DEPENDENCY4=level
DEPENDENCY5=screen
DEPENDENCY6=game
DEPENDENCY7=paddle
DEPENDENCY8=breakableBrick
DEPENDENCY9=gameExecuter

CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++11
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = ../src/
INC_DIR = ../inc/

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC_DIR}${DEPENDENCY2}.o ${SRC_DIR}${DEPENDENCY3}.o \
	${SRC_DIR}${DEPENDENCY4}.o ${SRC_DIR}${DEPENDENCY5}.o ${SRC_DIR}${DEPENDENCY6}.o ${SRC_DIR}${DEPENDENCY7}.o \
	${SRC_DIR}${DEPENDENCY8}.o ${SRC_DIR}${DEPENDENCY9}.o

all: $(TARGET)

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

utest.o: utest.cpp

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean

DEPENDS = $(OBJS:%.o=%.d)

-include ${DEPENDS}