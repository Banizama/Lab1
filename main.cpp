#include <iostream>
#include <iostream>
#include "Domino.cpp"
#include <vector>
#include <algorithm>
#include <random>
int main() {
    DominoDealer dealer;
    dealer.createDeck(6);
    for(const auto& tile : dealer.tiles) {
        std::cout << "[" << tile.left << "|" << tile.right << "] ";
    }
    std::cout << std::endl;
    
    return 0;
}