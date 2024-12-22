# Makefile for Philo Project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra  -lpthread -g3 -fsanitize=thread

# Directories
SRC_DIR = /home/acharik/Desktop/Philo/src
BIN_DIR = /home/acharik/Desktop/Philo/bin

# Files
SRCS = $(SRC_DIR)/init.c $(SRC_DIR)/main.c $(SRC_DIR)/philo_utils.c $(SRC_DIR)/simulation.c $(SRC_DIR)/string_utils.c
OBJS = $(SRC_DIR)/init.o $(SRC_DIR)/main.o $(SRC_DIR)/philo_utils.o $(SRC_DIR)/simulation.o $(SRC_DIR)/string_utils.o
TARGET = $(BIN_DIR)/philo

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(SRC_DIR)/init.o: $(SRC_DIR)/init.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/init.c -o $(SRC_DIR)/init.o

$(SRC_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(SRC_DIR)/main.o

$(SRC_DIR)/philo_utils.o: $(SRC_DIR)/philo_utils.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/philo_utils.c -o $(SRC_DIR)/philo_utils.o

$(SRC_DIR)/simulation.o: $(SRC_DIR)/simulation.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/simulation.c -o $(SRC_DIR)/simulation.o

$(SRC_DIR)/string_utils.o: $(SRC_DIR)/string_utils.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/string_utils.c -o $(SRC_DIR)/string_utils.o

clean:
	rm -f $(SRC_DIR)/*.o

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean re
