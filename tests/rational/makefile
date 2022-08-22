CXX = g++
CC = $(CXX)
VALG=valgrind --leak-check=yes --track-origins=yes

CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++11 -pedantic
CXXFLAGS += -Wall -Werror

LDFLAGS =
LDLIBS =

INC_DIR = ../../inc
SRC_DIR = ../../src

TARGET = utest
OBJS = utest.o $(SRC_DIR)/rational.o

all: $(TARGET)

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

#check memory leaks
vala: all
	${VALG} ./$(TARGET)

clean:
	@$(RM) $(TARGET) $(TARGET).o $(OBJS)

.PHONY: all check clean

utest.o: utest.cpp $(INC_DIR)/mu_test.h $(INC_DIR)/rational.hpp
rational.o: $(SRC_DIR)/rational.cpp $(INC_DIR)/rational.hpp