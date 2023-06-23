# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -Wall -Wextra -Iinclude -Wno-unused-parameter -Wpedantic -Werror -ldl -lgtest -lgtest_main -lpthread

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
EXECUTABLE := $(BINDIR)/Tensor.out

.PHONY: all clean debug

all: $(EXECUTABLE)

debug: CXXFLAGS += $(DBGFLAGS)
debug: all

$(EXECUTABLE): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $^ -o $@ $(CXXFLAGS)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf $(BINDIR)