#ifndef BLINDMANSBLUFF_CARD_H
#define BLINDMANSBLUFF_CARD_H
#include <string>
using namespace std;

// ranks are ordered Ace-low and Queen-high
const string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","King","Queen"};
// suits are ordered alphabetically
const string suits[] = {"Clubs","Diamonds","Hearts","Spades"};

class Card {
public:
    //Constructors
    Card();
    Card(int cardRank, int cardSuit);

    //Overloaded Operators
    bool operator >(const Card& rhs);
    bool operator <(const Card& rhs);

    //Functions
    string printCard();

private:
    //Member Variables
    int rank;
    int suit;
    int value;
};



#endif //BLINDMANSBLUFF_CARD_H
