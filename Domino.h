#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

struct Domino {
    int left, right;

    Domino(int a, int b);
    bool canAttach(int value) const;
};

struct DominoDealer {
    int n;
    vector<Domino> tiles;
    vector<Domino> hand;
    mt19937 gen;
    uniform_int_distribution<int> dist;

    void createDeck(int n);
};
