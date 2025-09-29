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
        for(int j = i; j <=n; j++){
            tiles.emplace_back(i, j);
        }
    }
}
Domino DominoDealer::pullRandomTile(vector<Domino> &box) {
    if(box.empty()) throw runtime_error("No tiles left to pull");

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, box.size() - 1);
    int randomIndex = dist(gen);
    Domino tile = box[randomIndex];
    box.erase(box.begin() + randomIndex);
    return tile;
}
int DominoDealer::findTileForLeftSide(vector<Domino> &box, Domino tile){
    for(size_t i = 0; i < box.size();i++){
        if(box[i].left == tile.left or box[i].right == tile.left){
            return i;
        }
    }
    return -1;
}

int DominoDealer::findTileForRightSide(vector<Domino> &box, Domino tile){
    for(size_t i = 0; i < box.size();i++){
        if(box[i].left == tile.right or box[i].right == tile.right){
            return i;
        }
    }
    return -1;
}

// int DominoDealer::findTile(vector<Domino> &box, Domino domino) {
//     for (size_t i = 0; i < box.size(); i++) {
//         if (box[i].left == value || box[i].right == value) {
//             return i;
//         }
//     }
//     return -1; 
// }


// void DominoDealer::attachTileToLeftSide(vector<Domino> &box, vector<Domino> &chain, int leftValue){
//     Domino tile = box
// }