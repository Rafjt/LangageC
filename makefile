CC = gcc
LDFLAGS = -lSDL2
TARGET = uno
SRC = main.c card.c game.c player.c gui.c network.c  # Add other source files here
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

