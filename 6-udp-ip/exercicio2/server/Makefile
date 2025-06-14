# Configurações do servidor
TARGET = tcp_server
TARGET_SOURCES = tcpserver.c echoserver.c
BINDIR = ./bin
FLAGS = -O2 -Wall -Werror
LIBS =
INCLUDE = -I. -I./include/
CC = gcc

# Regra padrão (compila e instala no diretório bin)
all: install

install: $(TARGET)
	@mkdir -p $(BINDIR)
	@mv $(TARGET) $(BINDIR)

$(TARGET): $(TARGET_SOURCES:.c=.o)
	$(CC) $(FLAGS) $(INCLUDE) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c -o $@ $<

# Limpeza
clean:
	@rm -rf *.o *.d

distclean: clean
	@rm -f $(TARGET)
	@rm -rf $(BINDIR)

.PHONY: all install clean distclean