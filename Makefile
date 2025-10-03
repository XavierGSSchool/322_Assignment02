# Directories
INC_DIR := INC_DIR
SRC_DIR := SRC_DIR
OBJ_DIR := OBJ_DIR
BIN_DIR := BIN_DIR

# Compiler
CC := gcc
CFLAGS := -g -Wall -std=c99 -pedantic -I $(INC_DIR)
LFLAG := -g

# Target and objects
TARGET := $(BIN_DIR)/main.exe
OBJS := $(OBJ_DIR)/main.o $(OBJ_DIR)/math_ops.o

RM := -rm -f

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(LFLAG) $(OBJ_DIR)/main.o $(OBJ_DIR)/math_ops.o -o $(TARGET)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/math_ops.o: $(SRC_DIR)/math_ops.c $(INC_DIR)/math_ops.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/math_ops.c -o $(OBJ_DIR)/math_ops.o

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	$(RM) $(OBJ_DIR)/*.o $(TARGET)