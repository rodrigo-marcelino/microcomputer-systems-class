# Diretórios
SRC_DIR := src
BIN_DIR := bin
INC_DIR := include

# Compilador e flags
CC := gcc
CFLAGS := -Wall -I$(INC_DIR)

# Encontra todos os arquivos .c em src
SRC := $(wildcard $(SRC_DIR)/*.c)

# Para cada arquivo .c, define o executável em bin/ com mesmo nome sem extensão
TARGETS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(SRC))

# Regra padrão: compila todos os executáveis
all: $(TARGETS)

# Como compilar cada executável individualmente
$(BIN_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $@

# Limpar arquivos executáveis
clean:
	rm -rf $(BIN_DIR)/*

.PHONY: all clean
