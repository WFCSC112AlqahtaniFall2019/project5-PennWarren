#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"
#include <string>
using namespace std;

class Deck {
public:
    //Constructors
    Deck();
    Deck(const Deck& d);

    //Copy Assignment Operator
    Deck& operator= (const Deck& rhs);

    //Destructor
    ~Deck();

    //Functions
    void createDeck();
    void shuffle();
    Card drawCard();
    bool placeCard(Card c);

private:
    //Member Variables
    Card* cards;
    int arraySize;
    int cardsLeft;
};


#endif //BLINDMANSBLUFF_DECK_H
