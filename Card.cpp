//
// Created by Rathtana Duong on 10/17/17.
//

#include "Card.h"

/**
 * Constructor takes in an integer and convert it to enum types to
 * to initialize the instance variables
 *
 * @param cardRank
 * @param cardSuit
 */
Card::Card(int suit, int rank) {
    setSuitandValue(suit, rank);
    //cout  <<"card object created" << endl;
}
void Card::setSuitandValue(int suit, int rank) {
    this->suit = static_cast<CardSuit>(suit);
    this->rank = static_cast<CardRank>(rank);
}
/**
 * Getter that return the card Value
 *
 * @return cardValue
 */
int Card::getCardValue() const {

    switch(rank) {
        case TWO: return 2;
        case THREE: return 3;
        case FOUR: return 4;
        case FIVE: return 5;
        case SIX: return 6;
        case SEVEN: return 7;
        case EIGHT: return 8;
        case NINE: return 9;
        case TEN: case JACK: case QUEEN: case KING:
            return 10;
        case ACE: return 11;

        default: return 0; //no valid rank of the card
    }
}
/**
 * Getter that return the suit of the card
 *
 * @return suit
 */
char Card::getCardSuit() const {

    switch (suit) {
        case SPADE: return 'S';
        case CLUB: return 'C';
        case DIAMOND: return 'D';
        case HEART: return 'H';

        default: return 0; //no valid suit
    }
}
/**
 * A getter that return the symbol of the card
 *
 * @return cardSymbol
 */
string Card::getCardSymbol() const {

    if (rank < 9) {
        int cardValue = getCardValue();

        return to_string(cardValue);
    }
    else {
        switch(rank) {
            case JACK: return "J";
            case QUEEN: return "Q";
            case KING: return "K";
            case ACE: return "A";
        }
    }
    return "";
}

void Card::swap(Card &other) {
    int suitTemp = this->suit;
    int rankTemp = this->rank;

    *this = other;
    other.setSuitandValue(suitTemp,rankTemp);

}
/**
 * Overloading << operator to output a representation of the card
 * @param out
 * @param card
 * @return ostream &out
 */
ostream& operator<<(std::ostream &out, const Card &card) {
    if(card.rank < 9)
        return out << card.getCardSuit() << "_" << card.getCardValue();
    else
        return out << card.getCardSuit()<< "_" << card.getCardSymbol();
}
