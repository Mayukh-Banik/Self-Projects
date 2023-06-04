# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -Wall -Wextra -Iinclude -Wno-unused-parameter -Wpedantic -Werror

# Debug flags
DBGFLAGS := -g

# Directories
SRCDIR := src
INCDIR := include
BINDIR := bin

# Source files
SRCS := $(wildcard $(SRCDIR)/*.cpp)
# Object files
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SRCS))

# Executable
EXECUTABLE := $(BINDIR)/Run.out

.PHONY: all clean debug

all: $(EXECUTABLE)

debug: CXXFLAGS += $(DBGFLAGS)
debug: all

$(EXECUTABLE): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BINDIR)

