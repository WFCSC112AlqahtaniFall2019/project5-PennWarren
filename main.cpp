#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    srand(time(nullptr));
    bool play, invalid, guessedHigher;
    int nWin = 0, nLoss = 0;
    string response;

    //Create draw pile and discard pile
    Deck game;
    Deck discard;

    //Populate and shuffle draw pile
    game.createDeck();
    game.shuffle();

    //Each turn, both players draw a Card object
    Card compValue, userValue;

    cout << "Welcome to Blind Man's Bluff\n" << endl;
    play = true;
    while(play) {
        // assign values to computer and user cards
        compValue = game.drawCard();
        userValue = game.drawCard();

        // get user's bet
        cout << "Computer's value is " << compValue.printCard() << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
            }
        }

        // determine outcome
        if((compValue < userValue && guessedHigher) || (compValue > userValue && !guessedHigher)) {
            cout << "\nGreat! You're right:" << endl;
            nWin++;
        } else {
            cout << "\nSorry, you're wrong:" << endl;
            nLoss++;
        }

        // print card
        cout << "\tyour value is " << userValue.printCard() << endl;

        // add each card to the discard pile, end the game when the discard pile is full (and thus the draw pile is empty)
        if(!discard.placeCard(compValue) || !discard.placeCard(userValue)){
            cout << "The deck is empty.\n" << endl;
            break;
        }

        // ask user to play again
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)\n" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << " (W-L)" << endl;

    return 0;

}