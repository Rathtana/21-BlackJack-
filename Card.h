//
// Created by Rathtana Duong on 10/17/17.
//

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <iostream>
using namespace std;

class Card {
public:
    enum CardSuit {
        SPADE,
        CLUB,
        DIAMOND,
        HEART

    };
    enum CardRank {
        TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING, ACE
    };
private:
    CardRank rank;
    CardSuit suit;

public:
    Card(int suit=0, int rank=0);
    void setSuitandValue(int suit, int rank);
    int getCardValue() const;
    char getCardSuit() const;
    string getCardSymbol() const;
    void swap(Card &other);
    friend std::ostream& operator<<(std::ostream &out, const Card &card);

};


#endif //BLACKJACK_CARD_H
