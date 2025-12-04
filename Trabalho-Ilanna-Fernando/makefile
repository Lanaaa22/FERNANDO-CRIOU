# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Source files

# Default target (compile and run)
all: compile run

# Explicit compile target (produces the target program)
compile: $(TARGET)
SRCS = main.c funcoes/system.c funcoes/auxiliares.c funcoes/consultar_time.c funcoes/consultar_partida.c funcoes/imprimir_classificacao.c TADs/tad_time.c TADs/tad_partida.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = programa

# Phony targets
.PHONY: all compile run clean

# Run the executable (COMANDO CORRIGIDO PARA LINUX)
run: $(TARGET)
	./$(TARGET)


# Clean up (COMANDO CORRIGIDO PARA LINUX)
clean:
	rm -f $(OBJS) $(TARGET)


# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
