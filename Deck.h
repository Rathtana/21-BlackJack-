//
// Created by Rathtana Duong on 10/19/17.
//

#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <ctime>
#include <cstdlib>

#include "Card.h"


using namespace std;

int indexPos = 0;

class Deck {

private:
    //ONlY DECLARE! MUST DEFINE OUTSIDE OF CLASS
    static Card deck[52];


public:
    Deck() = delete;

    static void createADeck() {
        int index = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                deck[index].setSuitandValue(i,j);
                index++;
            }
        }
    }
    static void printDeck() {
        for(int i=0; i<52; i++) {
            cout << deck[i] << endl;
        }
    }
    static void shuffle() {
        //setting initial seed value.
        //time(0) will be using the change in current time to generate
        //a different number every time you run the program.
        srand((unsigned)time(0));

        for(int i=0; i<52; i++) {
            deck[i].swap((deck[rand() % 52])); //rand() % 52 generate from 0 - 51
        }

    }
    static Card& getCardFromDeck() {
        if(indexPos == 51) {
            shuffle();
            indexPos = 0;
        }

        return deck[indexPos++];
    }
};

//DEFINING THE ARRAY insdie the class
Card Deck::deck[52];


#endif //BLACKJACK_DECK_H
