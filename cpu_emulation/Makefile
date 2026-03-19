CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = executables/executeMe
SRCS = main.cpp cpu.cpp

all:
	mkdir -p executables
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -rf executables
