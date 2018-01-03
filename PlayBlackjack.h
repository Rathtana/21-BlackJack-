//
// Created by Rathtana Duong on 11/2/17.
//

#ifndef BLACKJACK_PLAYBLACKJACK_H
#define BLACKJACK_PLAYBLACKJACK_H

#include <iostream>
#include "player.h"

 using namespace std;

void startGame(Player &player);
void pressEnterToStart();
void playerBalance(Player &player);


void gameIntro() {
    cout << "\t\t________________________________" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|     Welcome to BlackJack     |" << endl;
    cout << "\t\t|______________________________|" << endl;
    cout << endl;

}

Player creatingUser() {

    string user;
    string password;

    cout << "Enter a Username: ";
    cin >> user;

    while (true) {
        cout << "Enter a password: ";
        cin >> password;
        if (password.size() >= 8)
            break;
        cout << "Password must be at least 8 characters long" << endl;
        cout << endl;

    }
    cout << endl;
    cout << "User Created!" << endl;

    return  Player(user, 25000, password);

}
int playerBet(Player &player) {
    
    int amount;
    cout << "Place your Bet: ";

    while(true) {
        cin >> amount;
        if (amount <= player.getTotalChip()) {
            break;
        }
        cout << "You don't have enough for that amount!" << endl;
        cout << "Place your Bet again: ";
    }
    cout << endl;
    player.subtractFromChip(amount);

    return amount;

}
void pressEnterToStart() {

    int c;

    //clearing the input stream
    while ((c = getchar()) != '\n' && c != EOF) {
        getchar();
    }

    cout << "Press Enter to Start the Game";
    //waiting for user to press Enter
    getchar();
}
bool checkForValidScore(int value) {

    return (value <= 21);
}

#endif //BLACKJACK_PLAYBLACKJACK_H
