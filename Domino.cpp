#include <iostream>
#include "Domino.h"
#include <vector>
#include <algorithm>
#include <random>

Domino::Domino(int a, int b){
    if(a <= b){
        left = a;
        right = b;
    }
    else {
        left = b;
        right = a;
    }
}
bool Domino::canAttach(int value) const {
        return left == value || right == value;
}

void DominoDealer::createDeck(int n) {
    tiles.clear();
    for(int i = 0; i <=n; i++){
        for(int j = i; j <-n; j++){
            tiles.emplace_back(i, j);
        }
    }
}
Domino DominoDealer::pullRandomTile(vector<Domino> &box) {
    if(box.empty()) throw runtime_error("No tiles left to pull");
    uniform_int_distribution<int> dist(0, box.size() - 1);
    int randomIndex = dist(gen);
    Domino tile = box[randomIndex];
    box.erase(box.begin() + randomIndex);
    return tile;
}
int DominoDealer::findTileForLeftSide(vector<Domino> &box, int leftValue){
    for(size_t i = 0; i < box.size();i++){
        if(box[i].left == leftValue or box[i].right == leftValue){
            return i;
        }
    }
}

int DominoDealer::findTileForRightSide(vector<Domino> &box, int rightValue){
    for(size_t i = 0; i < box.size();i++){
        if(box[i].left == rightValue or box[i].right == rightValue){
            return i;
        }
    }
}
