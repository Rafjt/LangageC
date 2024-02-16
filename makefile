CC = gcc
LDFLAGS = -lSDL2
TARGET = uno
SRC = main.c card.c game.c player.c gui.c network.c  
OBJ = $(SRC:.c=.o)

UNAME_S:= $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
    LDFLAGS = -L/opt/homebrew/Cellar/sdl2/2.30.0/lib/ -lSDL2
else
    LDFLAGS = -lSDL2
endif

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

