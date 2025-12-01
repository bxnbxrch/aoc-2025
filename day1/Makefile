CC = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic
TARGET = day1
SRCS = main.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
