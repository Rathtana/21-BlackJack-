//
// Created by Rathtana Duong on 10/23/17.
//

#include "Player.h"

Player::Player(string username, int chip, string password) {
    this-> username = username;
    this-> password = password;
    this-> chip = chip;
}
int Player::getTotalChip() const {
    return this->chip;

}
string Player::getUsername() const {
    return this->username;
}

bool Player::addToChip(int amount) {
    if(amount > 0) {
        this->chip += amount;
        return true;
    }
    return false;
}
bool Player::subtractFromChip(int amount) {
    if(amount > 0 && amount <= chip) {
        this->chip -= amount;
        return true;
    }
    return false;

}

ostream& operator<<(std::ostream &out, const Player &player){
    return out << player.username + "'s Chip: $" << player.chip << endl;
}

