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
    uniform_int_distribution<int> dist;

    void createDeck(int n);
    Domino pullRandomTile(vector<Domino> &box);
    int findTileForLeftSide(vector<Domino> &box, Domino tile);
    int findTileForRightSide(vector<Domino> &box, Domino tile);
    int findTile(vector<Domino> &box, int value);
//     void attachTileToLeftSide(vector<Domino> &box, vector<Domino> &chain, int leftValue);
//     void attachTileToRightSide(vector<Domino> &box, vector<Domino> &chain, int rightValue);
};
