CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=machine_stack
DEPENDENCY2=machine_memory
DEPENDENCY3=machine_vm
DEPENDENCY4=machine_compiler
DEPENDENCY5=machine_code_segment
DEPENDENCY6=machine_executer

CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++11
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

SRC_DIR = ../../src/
INC_DIR = ../../inc/

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC_DIR}${DEPENDENCY2}.o \
		${SRC_DIR}${DEPENDENCY3}.o ${SRC_DIR}${DEPENDENCY4}.o ${SRC_DIR}${DEPENDENCY5}.o  ${SRC_DIR}${DEPENDENCY6}.o

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