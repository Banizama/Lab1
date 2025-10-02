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

class DominoDealer {
    int n;
    vector<Domino> box;
    vector<Domino> chain;
    uniform_int_distribution<int> dist;

    void createDeck(int n);
    Domino pullRandomTile(vector<Domino> &box);
    int findTileForLeftSide(vector<Domino> &chain);
    int findTileForRightSide(vector<Domino> &chain);
    bool canAttachToLeftSide(const vector<Domino> &chain, const Domino &tile);
    bool canAttachToRightSide(const vector<Domino> &chain, const Domino &tile);
    void attachTileToLeftSide(vector<Domino> &box, vector<Domino> &chain, int leftValue, int index);
    void attachTileToRightSide(vector<Domino> &box, vector<Domino> &chain, int rightValue, int index);
public:
    int operator()();
};
