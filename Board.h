//
// Created by Leddon Zwack on 8/10/24.
//

#ifndef CHESSENGINE_BOARD_H
#define CHESSENGINE_BOARD_H

#include <cstdint>
#include <iostream>

class Board {
public:
    uint64_t whitePawns;
    uint64_t blackPawns;
    uint64_t whiteKnights;
    uint64_t blackKnights;
    uint64_t whiteBishops;
    uint64_t blackBishops;
    uint64_t whiteRooks;
    uint64_t blackRooks;
    uint64_t whiteQueens;
    uint64_t blackQueens;
    uint64_t whiteKing;
    uint64_t blackKing;

    Board();            // Constructor to initialize the board
    void initialize();  // Method to set up the initial position
    void print() const; // Method to print the bitboards

private:
    void printBitboard(uint64_t bitboard) const; // Helper function to print a bitboard
};

#endif //CHESSENGINE_BOARD_H
