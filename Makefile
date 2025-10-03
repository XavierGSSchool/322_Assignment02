# Directories to include headers, SRC, OBJ and BIN
INC_DIR := INC_DIR
SRC_DIR := SRC_DIR
OBJ_DIR := OBJ_DIR
BIN_DIR := BIN_DIR

# Compiler settings
CC := gcc
CFLAGS := -g -Wall -std=c99 -pedantic -I $(INC_DIR) # complier flags
LFLAGS := -g # linker flag

# Target and objects
TARGET := $(BIN_DIR)/main.exe #$(SCR_DIR)/main.ex
OBJS := $(OBJ_DIR)/main.o $(OBJ_DIR)/math_ops.o

RM := -rm -f

.PHONY: all clean check-shell


# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS) | $(BIN_DIR) #order-only prerequisite
	$(CC) $(LFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/math_ops.o -o $(TARGET)

# Compile main.c -> main.o
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

# Compile math_ops.c -> math_ops.o
$(OBJ_DIR)/math_ops.o: $(SRC_DIR)/math_ops.c $(INC_DIR)/math_ops.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/math_ops.c -o $(OBJ_DIR)/math_ops.o

# Ensure OBJ_DIR exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Ensure BIN_DIR exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean 
clean:
	$(RM) $(OBJ_DIR)/*.o $(TARGET)