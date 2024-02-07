#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "card.h"
#define MAX_CARDS 60

void storeCards(struct carte pioche []) {
    FILE *file = fopen("all_cartes.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(file, " %c %d %d", &pioche [i].couleur, &pioche [i].nombre, &pioche [i].special) == 3) {
        i++;
    }

    fclose(file);
}

int main(){
    struct carte pioche [MAX_CARDS];
    storeCards(pioche );

    
    for (int j = 0; j < MAX_CARDS; j++) {
        printf("Card %d: %c %d %d\n", j+1, pioche [j].couleur, pioche [j].nombre, pioche [j].special);
    }

    return 0;
}