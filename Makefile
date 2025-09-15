CC = gcc
CFLAGS = -g -Wall -std=c99 -pedantic -Iinclude

SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin
OBJ_DIR = obj

APP_OBJS   = $(OBJ_DIR)/main.o $(OBJ_DIR)/math_ops.o
TEST_OBJS  = $(OBJ_DIR)/tests.o $(OBJ_DIR)/math_ops.o $(OBJ_DIR)/unity.o

APP_TARGET  = $(BIN_DIR)/main.exe
TEST_TARGET = $(BIN_DIR)/tests.exe

.PHONY: all app test clean

all: app test

app: $(APP_TARGET)
test: $(TEST_TARGET)

$(APP_TARGET): $(APP_OBJS)
	$(CC) $(APP_OBJS) -o $@

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $@

# Compile main.c
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c 
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile math_ops.c (previously  had code.c and code2.c)
$(OBJ_DIR)/math_ops.o: $(SRC_DIR)/math_ops.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile tests.c
$(OBJ_DIR)/tests.o: $(TEST_DIR)/tests.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile unity.c
$(OBJ_DIR)/unity.o: $(TEST_DIR)/unity.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*.exe