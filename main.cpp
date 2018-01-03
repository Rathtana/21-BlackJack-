#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "PlayBlackjack.h"


void outputPlayerBalance(int betAmount, const Player &player) {
    cout << "Player Bet: " << betAmount << ", Remaining Chips: " << player.getTotalChip()<< endl;
}

void outputPlayerCardValue(int playerCardValue,const Player &player) {
    cout << endl << player.getUsername() << "'s card: " <<playerCardValue << endl;
}

void outputDealerCard(int value) {
    Card card = value;
    cout << "Dealer's card: " << value << endl;
}

int main() {
      int betAmount;
      int playerCardValue;;
      int dealerCardValue;
      bool playOrExit = true;

      gameIntro();
      Player player = creatingUser();
      pressEnterToStart();
      Deck::createADeck();
      Deck::shuffle();

    bool addOrExit;
    int chipAmount;
    do {
        if (player.getTotalChip() == 0) {
            cout << endl << "1. Add more Chip, 2. Exit game: ";
            cin >> addOrExit;
            if (addOrExit) {
                cout << "Enter amount: ";
                cin >> chipAmount;
                while(true) {
                    if(player.addToChip(chipAmount)) {
                        break;
                    }
                    cout << "Invalid Amount! " << endl;
                    cout << "Enter amount again: ";
                    cin >> chipAmount;
                }
            }

        }
        cout << endl << player << endl;
        betAmount = playerBet(player);
        playerCardValue = Deck::getCardFromDeck().getCardValue() +
                          Deck::getCardFromDeck().getCardValue();

        outputPlayerBalance(betAmount, player);
        outputPlayerCardValue(playerCardValue, player);

        dealerCardValue = Deck::getCardFromDeck().getCardValue();

        cout << "Dealer: " << dealerCardValue << ", --" << endl;

        int choice = 0;
        cout << endl << "1. Hit, 2. Stay, 3. Double: ";
        do {
            if (choice != 2)
                cin >> choice;

            switch (choice) {
                case 1:
                    //give another card
                    playerCardValue += Deck::getCardFromDeck().getCardValue();
                    outputPlayerCardValue(playerCardValue, player);
                    if (!checkForValidScore(playerCardValue))
                        //end round you lost
                        //leave while loop
                        choice = 0;
                    else {
                        cout << endl << "1. Hit, 2. Stay: ";
                    }


                    break;
                case 2:
                    //give the dealer a card
                    while (dealerCardValue < 16) {
                        dealerCardValue += Deck::getCardFromDeck().getCardValue();
                        cout << endl;
                        outputDealerCard(dealerCardValue);
                        if (!checkForValidScore(dealerCardValue))
                            //Player win
                            choice = 4;
                    }
                    choice = -1;

                    break;
                case 3:
                    if (player.subtractFromChip(betAmount)) {
                        playerCardValue += Deck::getCardFromDeck().getCardValue();
                        betAmount *= 2;
                        cout << endl;
                        outputPlayerBalance(betAmount, player);
                        outputPlayerCardValue(playerCardValue, player);
                        choice = 2;
                    } else {
                        cout << "Not enough chip to double!" << endl;
                        cout << endl << "1. Hit, 2. Stay: ";
                        choice = 1;
                    }

                    break;
            }
        } while (choice == 1 || choice == 2);

        //transfer money
        if (dealerCardValue <= 21 && playerCardValue <= 21) {
            if (dealerCardValue > playerCardValue) {
                cout << endl << "~~~~~~Dealer Win!~~~~~~" << endl;
            } else if (dealerCardValue == playerCardValue) {
                player.addToChip(betAmount);
                cout << "Game is tied!" << endl;
            } else {
                //add money to player
                player.addToChip(betAmount * 2);
                cout << endl << "~~~~~~Player Win!~~~~~~" << endl;
            }
        } else if (playerCardValue > 21)
            cout << endl << "~~~~~~Dealer Win!~~~~~~" << endl;
        else {
            player.addToChip(betAmount * 2);
            cout << endl << "~~~~~~Player Win!~~~~~~" << endl;
        }
        //reset for next game
        betAmount = 0;

        cout << endl << "Press 1 to Continue, 0 to exit the game: ";
        cin >> playOrExit;
    }
    while (playOrExit);

    return 0;
}