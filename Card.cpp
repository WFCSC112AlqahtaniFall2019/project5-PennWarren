#include "Card.h"

//default constructor, will initialize to Ace of Clubs
Card::Card() {
    rank = 0;
    suit = 0;
    value = 0;
}

//rank and suit constructor
Card::Card(int cardRank, int cardSuit){
    //initialize rank and suit, and prevent them from being out of bounds
    if(cardRank < 0 || cardRank > 12){
        rank = 0;
    }
    else
        rank = cardRank;
    if(cardSuit < 0 || cardSuit > 3){
        suit = 0;
    }
    else
        suit = cardSuit;

    //formula to give every card a unique value
    value = (cardRank * 4) + suit;
}

//compares the value to determine which card is greater or lesser
bool Card::operator>(const Card& rhs) {
    return this->value > rhs.value;
}
bool Card::operator<(const Card &rhs) {
    return this->value < rhs.value;
}

//prints the name of the card
string Card::printCard(){
    return ranks[rank] + " of " + suits[suit];
}

