#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "card.h"


int main(){
    storeCards(pioche);

    
    for (int j = 0; j < MAX_CARDS; j++) {
        printf("Card %d: %c %d %d\n", j+1, pioche [j].couleur, pioche [j].nombre, pioche [j].special);
    }

    return 0;
}