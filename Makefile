# Compilador e flags
CC = gcc
CFLAGS = -Wall -Iinclude

# Diretórios
SRC_DIR = source
INC_DIR = include

# Nome do executável
TARGET = simulador_so

# Lista de arquivos fonte e objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=%.o)

# Regra padrão
all: $(TARGET)

# Como gerar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
	@rm -f $(OBJ)   # Apaga os .o após compilação

# Como compilar cada .c em .o
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o

# Executar o programa
run: $(TARGET)
	./$(TARGET)

# Garante que 'clean' e 'run' não sejam confundidos com arquivos
.PHONY: all clean run
