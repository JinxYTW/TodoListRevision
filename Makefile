# The Makefile must be in the root directory of the project where the source files are located.
#
# Usage (in a terminal in the root directory of the project):
# make			# Compile and link all .cpp files
# make clean	# Clean up the build directory


# Compiler and linker - Use g++ on Linux, Windows and clang++ on Mac OS X
CXX        = clang++
# Compiler options - Wall for all warnings, std=c++17 for C++17
CXXFLAGS   = -Wall  -std=c++17
# Dependency flags - Include .d files generated by the compiler
DEPFLAGS   = -MMD
# Linker flags - No flags
LDFLAGS    =
# Build directory
BUILDIR    = build
# Source files - All .cpp files required to build the executable
# Replace the following list (file1.cpp, ...) by your cpp files to compile
SRC_FILES  = date.cpp todolist.cpp main.cpp 
# Object files - All .o files generated from the source files
OBJ_FILES  = $(patsubst %.cpp, $(BUILDIR)/%.o, $(SRC_FILES))
# Executable - The name of the executable into the bin directory
BINDIR	   = bin
# Target - The path to the executable
TARGET     = $(BINDIR)/app
# Dependencies - All .d files generated by the compiler
DEPS	   = $(OBJ_FILES:.o=.d)

all: $(TARGET)
	
# Link object files to executable into the bin directory
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJ_FILES)

# Compile source files to object files into the build directory
$(BUILDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

# Clean up the build directory
clean:
	rm -rf $(BUILDIR)
	rm -rf $(BINDIR)

# Include the dependencies generated by the compiler
-include $(DEPS)

# Phony targets
.PHONY: all clean