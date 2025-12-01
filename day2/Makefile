CXX ?= g++
CXXFLAGS ?= -std=c++23 -Wall -Wextra -Wpedantic -O2
TARGET := day2
SRCS := main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

debug: CXXFLAGS := -std=c++23 -Wall -Wextra -Wpedantic -g -O0
debug: clean $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
	rm -rf build

.PHONY: all debug run clean
