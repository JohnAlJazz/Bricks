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
OBJS = utest.o $(SRC_DIR)/algebra.o

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

utest.o: utest.cpp $(INC_DIR)/mu_test.h $(INC_DIR)/algebra.hpp
algebra.o: $(SRC_DIR)/algebra.cpp $(INC_DIR)/algebra.hpp