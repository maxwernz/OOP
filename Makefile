SRC_DIR = $(src)
BUILD_DIR = $(SRC_DIR)
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(SRC_DIR)/Test/*.cpp)
SFML_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = run
INCLUDE = -I include
LIB = -L lib
COMPILER_FLAGS = -std=c++14 -Wall -O0
GTEST = -lgtest -lgtest_main -pthread
SFML = -lsfml-graphics -lsfml-window -lsfml-system -pthread
LINKER =

all:
	$(CC) $(COMPILER_FLAGS) $(LINKER) $(INCLUDE) $(LIB) $(SRC_FILES) -o $(BUILD_DIR)/run

gtest:
	$(CC) $(COMPILER_FLAGS) $(GTEST) $(LINKER) $(INCLUDE) $(LIB) $(TEST_FILES) -o $(BUILD_DIR)/Test/gtest

sfml:
	$(CC) $(COMPILER_FLAGS) $(LINKER) $(INCLUDE) $(LIB) $(SFML_FILES) -o $(BUILD_DIR)/run $(SFML)
