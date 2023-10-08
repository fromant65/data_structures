# Define the C compiler to use
CC = gcc

# Define any directories containing header files
INCLUDES = -I./nodes -I./linked_list -I./stack -I./tree

# Define the source file directories
DIRS = nodes linked_list stack tree

# Use wildcard to get all C files in the defined directories
SRCS = $(wildcard $(addsuffix /*.c, $(DIRS))) main.c

# Define the object files 
OBJS = $(SRCS:.c=.o)

# Define the executable file 
MAIN = main

.PHONY: clean main

all: $(MAIN)
	@echo Program has been compiled

$(OBJS): %.o: %.c
	$(CC) -c $< -o $@

$(MAIN): $(OBJS) 
	$(CC) $(OBJS) -o $(MAIN)
