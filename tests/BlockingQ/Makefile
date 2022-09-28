CXX = g++
CC = $(CXX)

#dependencies:
DEPENDENCY1=BlockingQueue
DEPENDENCY2=Semaphore


CPPFLAGS = -I$(INC_DIR)
CPPFLAGS += -MMD -MP

# c language
CFLAGS = -g10

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

LDFLAGS+= -pthread


SRC_DIR = ../../src/
INC_DIR = ../../inc/

TARGET = utest
OBJS = utest.o ${SRC_DIR}${DEPENDENCY1}.o ${SRC_DIR}${DEPENDENCY2}.o
OBJSD = ${SRC_DIR}${DEPENDENCY1}.d ${SRC_DIR}${DEPENDENCY2}.d

all: $(TARGET)

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

vala: all
	${VALG} ./$(TARGET)

utest.o: utest.cpp

clean:
	@$(RM) $(TARGET) $(OBJS) $(OBJSD)

.PHONY: all check clean

DEPENDS = $(OBJS:%.o=%.d)

-include ${DEPENDS}