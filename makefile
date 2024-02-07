CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = card.c game.c gui.c main.c network.c player.c
OBJ = $(SRC:.c=.o)
HDR = card.h game.h gui.h network.h player.h
EXE = uno

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXE)

