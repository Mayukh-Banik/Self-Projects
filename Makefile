# Compiler
CC := gcc
# Compiler flags
CFLAGS := -Wall -Wextra -Iinclude -Wno-unused-parameter -IC

# Debug flags
DBGFLAGS := -g

# Directories
SRCDIR := src
INCDIR := include
BINDIR := bin

# Source filesa
SRCS := $(wildcard $(SRCDIR)/*.c)
# Object files
OBJS := $(patsubst $(SRCDIR)/%.c,$(BINDIR)/%.o,$(SRCS))

# Executable
EXECUTABLE := $(BINDIR)/Executable.out

.PHONY: all clean debug

all: $(EXECUTABLE)

debug: CFLAGS += $(DBGFLAGS)
debug: all

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BINDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BINDIR)
