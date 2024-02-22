CC = gcc
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
TARGET = uno
SRC = main.c card.c game.c player.c gui.c 
OBJ = $(SRC:.c=.o)

UNAME_S:= $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	# For macOS, use Homebrew's SDL2 installation
	SDL2_PATH = /opt/homebrew/Cellar/sdl2/2.30.0
	CFLAGS += -I$(SDL2_PATH)/include
	LDFLAGS += -L$(SDL2_PATH)/lib/ -lSDL2
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Dependency tracking for headers
%.o: %.c $(wildcard *.h)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)