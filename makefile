# Compiler
CC = g++
# Compiler flags
CFLAGS = -Wall -O2
# Linker flags
LDFLAGS = -static-libgcc -static-libstdc++ -Wl,-subsystem,console

# Source directory and wildcard to find all .cpp files
SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)

# Object directory
OBJ_DIR = obj
# Object files (automatically generated from SRCS)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Executable name
EXEC = chess

# Default target
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

# Rule to compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all clean
