CXX = g++
CC = $(CXX)
VALG=valgrind --leak-check=yes --track-origins=yes

CPPFLAGS = -I$(INC_DIR)
# c language
CFLAGS = -g3

# c++ language
CXXFLAGS = -std=c++11
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3

LDFLAGS =
LDLIBS =

SRC_DIR = ../../src/
INC_DIR = ../../inc/

TARGET = utest
OBJS = utest.o $(SRC_DIR)${DEPENDENCY1}.o

#dependencies:
DEPENDENCY1=gray_image

all: $(TARGET)

$(TARGET): $(OBJS)

check: $(TARGET)
	./$(TARGET) -v

#check memory leaks
vala: all
	${VALG} ./$(TARGET)

utest.o: utest.cpp $(INC_DIR)mu_test.h $(INC_DIR)${DEPENDENCY1}.hpp
${DEPENDENCY1}.o: $(SRC_DIR)${DEPENDENCY1}.cpp $(INC_DIR)${DEPENDENCY1}.hpp

clean:
	@$(RM) $(TARGET) $(OBJS)

.PHONY: all check clean