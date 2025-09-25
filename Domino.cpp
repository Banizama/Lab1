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
