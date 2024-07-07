# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -O2

# Source directory and wildcard to find all .cpp files
SRC_DIR = .
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object directory
OBJ_DIR = obj
# Object files (automatically generated from SRCS)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Executable name
EXEC = chess

# Default target
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Rule to compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC)
	rm -rf $(OBJ_DIR)

# Ensure obj directory exists
$(shell mkdir -p $(OBJ_DIR))

.PHONY: all clean
