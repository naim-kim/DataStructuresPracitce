CXX = g++
FLAGS = -ggdb -Wall -c

OBJS = calc.o main.o 
TARGET = calc

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

.cpp.o:
	$(CXX) $(FLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) *.o

calc.o: calc.h stack.h
main.o: calc.h 
