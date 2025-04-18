# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -O2 -std=c++11
LDFLAGS = 

# Source files
SOURCES = tb.cpp my_top.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
EXECUTABLE = object_detection

# Header files (for dependency tracking)
HEADERS = image.h proto.h headers.h hardware_modules.h

# Default target
all: $(EXECUTABLE)

# Link object files to create executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

# Phony targets
.PHONY: all clean