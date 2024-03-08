# the compiler to use
CC = gcc
# compiler flags
CFLAGS  = -g -Wall

# folders containing source files
DIRS = object types array
# all .c files in the folders
SOURCES = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.c)) main.c
# .o files will be created from .c files
OBJECTS = $(SOURCES:.c=.o)

# target executable
TARGET = main

all: $(TARGET)
	@echo Program has been compiled

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

# If any .o file depends on a .c file or a .h file,
# then the .o file should be recreated.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all move clean
