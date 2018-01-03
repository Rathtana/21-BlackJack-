//
// Created by Rathtana Duong on 10/23/17.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <iostream>
using namespace std;

class Player {
private:
    string username;
    string password = "";
    int chip;

public:
    Player(string username, int chip, string password = "");
    int getTotalChip() const;
    string getUsername() const;
    bool addToChip(int amount);
    bool subtractFromChip(int amount);

    friend ostream& operator<<(std::ostream &out, const Player &player);

    //ostream& operator<<(std::ostream &out, const Player &player);

};

#endif //BLACKJACK_PLAYER_H
