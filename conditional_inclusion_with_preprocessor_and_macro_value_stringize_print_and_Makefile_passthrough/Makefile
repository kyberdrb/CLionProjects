CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = my_program

# Source files
SRCS = main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

DEBUG_MODE=

# Default rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	echo "DEBUG_MODE=${DEBUG_MODE}"
	$(CXX) $(CXXFLAGS) -DDEBUG_MODE=$(DEBUG_MODE) -c -o $@ $<

# Clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)

