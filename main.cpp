#include <iostream>
#include "Domino.cpp"
#include <vector>
#include <algorithm>
#include <random>
int main() {
    DominoDealer dealer;
    dealer.createDeck(8);
    for(const auto& tile : dealer.tiles) {
        std::cout << "[" << tile.left << "|" << tile.right << "] ";
    }
    std::cout << std::endl;
    Domino tile1 = dealer.DominoDealer::pullRandomTile(dealer.tiles);
    std::cout << "[" << tile1.left << "|" << tile1.right << "] ";

}
