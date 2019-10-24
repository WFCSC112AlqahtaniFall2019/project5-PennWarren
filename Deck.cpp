#include "Deck.h"

//Initial Constructor
Deck::Deck() {
    arraySize = 52;
    cardsLeft = 0;
    cards = new Card[arraySize];
}

//Copy Constructor
Deck::Deck(const Deck& d) {
    arraySize = d.arraySize;
    cardsLeft = d.cardsLeft;
    cards = new Card[arraySize];
    for(int i = 0; i < 52; i++){
        cards[i] = d.cards[i];
    }
}

//Copy Assignment Operator
Deck &Deck::operator=(const Deck &rhs) {
    Deck temp(rhs); //copy constructor temp
    swap(cards, temp.cards); //built-in swap
    return *this;

    //should I add more swaps for other variables?
}

//Populates a deck with every card in a standard 52-card deck
void Deck::createDeck() {
    cardsLeft = 52;
    int cIndex = 0;
    for(int i=0; i < 4; i++){
        for(int j=0; j < 13; j++){
            cards[cIndex] = Card(j,i);
            cIndex++;
        }
    }
}

//Shuffles the deck
void Deck::shuffle() {
    for(int i = 0; i < cardsLeft * cardsLeft; i++){
        swap(cards[rand() % cardsLeft], cards[rand() % cardsLeft]);
    }
}

//Draws a card and removes it from the deck (using indices)
Card Deck::drawCard() {
    cardsLeft--;
    return cards[cardsLeft];
}

//Place a card in the deck, returns false if the deck is full
bool Deck::placeCard(Card c) {
    if(cardsLeft < 51){
        cards[cardsLeft] = c;
        cardsLeft++;
        return true;
    } else
        return false;
}

//Destructor that deletes cards array
Deck::~Deck() {
    delete [] cards;
}