CC=gcc
CFLAGS=-I.

DEPS = lista.h
OBJ = main.o lista.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Here's a breakdown of what's happening in this Makefile:

# CC is the C compiler to use, gcc in this case.
# CFLAGS are the options passed to the gcc command. -I. tells gcc to look in the current directory (.) 
# for header files.
# DEPS is a list of header files that your .c files depend on.
# OBJ is a list of object files that need to be linked to create the final executable. 
# The .o files are created from .c files with the same name. So, main.c is compiled to main.o, 
# and lista.c is compiled to lista.o.
# The %.o: %.c $(DEPS) line is a rule that tells make how to build .o files from .c files. 
# The % is a wildcard that matches any file name. So, this rule says that any .o file depends on a .c file 
# with the same name and the header files in DEPS. The command that follows ($(CC) -c -o $@ $< $(CFLAGS)) 
# is run to create the .o file from the .c file. The $@ and $< are automatic variables in make: $@ is the 
# name of the target of the rule (the .o file), and $< is the name of the first prerequisite of the rule 
# (the .c file).
# The main: $(OBJ) line is a rule that tells make how to link the object files in OBJ to create the final 
# executable, main. The command that follows ($(CC) -o $@ $^ $(CFLAGS)) is run to link the object files. 
# Here, $@ is the name of the target (main), and $^ is the list of prerequisites (OBJ).
# To compile your project with this Makefile, you can run the make command in the terminal, 
# in the directory containing the Makefile. This will create an executable called main