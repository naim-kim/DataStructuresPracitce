CXX = g++
FLAGS = -ggdb -Wall -c

OBJS = contact.o main.o
TARGET = contact

all: $(TARGET) 

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

.cpp.o:
	$(CXX) $(FLAGS) -c $<

.PHONY: clean
clean:
	rm -f $(TARGET) *.o

contact.o: contact.h
main.o: contact.h
