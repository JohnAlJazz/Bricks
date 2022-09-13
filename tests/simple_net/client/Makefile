CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=Socket
DEPENDENCY2=client


CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3


SRC_DIR = ../../../src/
INC_DIR = ../../../inc/

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC_DIR}${DEPENDENCY2}.o

all: $(TARGET)

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

vala: all
	${VALG} ./$(TARGET)

utest.o: utest.cpp

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean

DEPENDS = $(OBJS:%.o=%.d)

-include ${DEPENDS}