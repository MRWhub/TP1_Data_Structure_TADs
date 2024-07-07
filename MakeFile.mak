
# Compilador
CC = gcc

# Flags de compila��o
CFLAGS = -Wall -g


# Arquivos fonte
SRCS = main.c exam.c patient.c sleep.c


# Arquivos objeto
OBJS = $(SRCS:.c=.o)

# Arquivo de sa�da
TARGET = exam

# Regra para garantir que o makefile � o alvo padr�o
.PHONY: all compile run clean

# Default target (compile and run)
all: compile run

# Explicit compile target (produces the target program)
compile: $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Limpeza dos arquivos objeto e do execut�vel
clean:
	rm -f $(OBJS) $(TARGET)


# Regra para compilar arquivos .c em arquivos .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra padr�o para compilar o programa
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
