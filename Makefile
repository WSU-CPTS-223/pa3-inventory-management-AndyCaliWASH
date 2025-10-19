CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

TARGET = main

SOURCE = $(wildcard *.cpp)

$(TARGET): $(SOURCE) 
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(TARGET)

clean: 
	rm -f $(TARGET) 



