# Compiler
CC = g++

# Compiler flags
CFLAGS = -O2 -Wall

# Target
TARGET = out
TARGET_PATH = ./test/test

all: $(TARGET)

$(TARGET): $(TARGET_PATH).cpp
			$(CC) $(CFLAGS) $(TARGET_PATH).cpp -o $(TARGET)

run:
			./$(TARGET)

clean:
			$(RM) $(TARGET)