CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=code_bf
DEPENDENCY2=data_bf
DEPENDENCY3=vm_bf

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
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC_DIR}${DEPENDENCY2}.o ${SRC_DIR}${DEPENDENCY3}.o

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