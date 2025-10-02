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
    box.clear();
    for(int i = 0; i <=n; i++){
        for(int j = i; j <=n; j++){
            box.emplace_back(i, j);
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
int DominoDealer::findTileForLeftSide(std::vector<Domino>& chain) {
    if(chain.empty()) return -1;

    int leftValue = chain.front().left;
    for (size_t i = 0; i < box.size(); ++i) {
        if (box[i].canAttach(leftValue)) return i;
    }
    return -1;
}

int DominoDealer::findTileForRightSide(std::vector<Domino>& chain) {
    if(chain.empty()) return -1;
    
    int rightValue = chain.back().right;
    for (size_t i = 0; i < box.size(); ++i) {
        if (box[i].canAttach(rightValue)) return i;
    }
    return -1;
}

bool DominoDealer::canAttachToLeftSide(const vector<Domino> &chain, const Domino &tile){
    if(chain.empty()) return true;

    int leftValue = chain.front().left;
    return tile.canAttach(leftValue);
}

bool DominoDealer::canAttachToRightSide(const vector<Domino> &chain, const Domino &tile){
    if(chain.empty()) return true;

    int leftValue = chain.back().right;
    return tile.canAttach(leftValue);
}

void DominoDealer::attachTileToLeftSide(vector<Domino> &box, vector<Domino> &chain, int leftValue, int index) {
    Domino tile = box[index];

    if (tile.right == leftValue) {
        std::swap(tile.left, tile.right);
    }

    chain.insert(chain.begin(), tile);
    box.erase(box.begin() + index);
}

void DominoDealer::attachTileToRightSide(vector<Domino> &box, vector<Domino> &chain, int rightValue, int index) {
    Domino tile = box[index];

    if (tile.left == rightValue) {
        std::swap(tile.left, tile.right);
    }

    chain.emplace_back(tile);
    box.erase(box.begin() + index);
}
int DominoDealer::operator()() {
        vector<Domino> chain;

        if(box.empty()) return 0;

        Domino first = pullRandomTile(box);
        chain.push_back(first);
        bool attached = true;
        while(attached && !box.empty()){
            attached = false;

            int leftIndex = findTileForLeftSide(chain);
            if(leftIndex != -1){
                attachTileToLeftSide(box, chain, chain.front().left, leftIndex);
                attached = true;
            }

            int rightIndex = findTileForRightSide(chain);
            if(rightIndex != -1){
                attachTileToRightSide(box, chain, chain.back().right, rightIndex);
                attached = true;
            }
        }
        return chain.size();
}