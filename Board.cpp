//
// Created by Leddon Zwack on 8/10/24.
//

#include "Board.h"

Board::Board() {
    initialize();
}

// Initialize the board with the standard chess starting positions
void Board::initialize() {
    whitePawns = 0x000000000000FF00;   // Row 2
    blackPawns = 0x00FF000000000000;   // Row 7
    whiteKnights = 0x0000000000000042; // Positions b1 and g1
    blackKnights = 0x4200000000000000; // Positions b8 and g8
    whiteBishops = 0x0000000000000024; // Positions c1 and f1
    blackBishops = 0x2400000000000000; // Positions c8 and f8
    whiteRooks = 0x0000000000000081;   // Positions a1 and h1
    blackRooks = 0x8100000000000000;   // Positions a8 and h8
    whiteQueens = 0x0000000000000008;  // Position d1
    blackQueens = 0x1000000000000000;  // Position d8
    whiteKing = 0x0000000000000010;    // Position e1
    blackKing = 0x0800000000000000;    // Position e8
}

// Print the board by showing bitboards for each piece
void Board::print() const {
    std::cout << "White Pawns:\n";
    printBitboard(whitePawns);
    std::cout << "Black Pawns:\n";
    printBitboard(blackPawns);
    std::cout << "White Knights:\n";
    printBitboard(whiteKnights);
    std::cout << "Black Knights:\n";
    printBitboard(blackKnights);
    std::cout << "White Bishops:\n";
    printBitboard(whiteBishops);
    std::cout << "Black Bishops:\n";
    printBitboard(blackBishops);
    std::cout << "White Rooks:\n";
    printBitboard(whiteRooks);
    std::cout << "Black Rooks:\n";
    printBitboard(blackRooks);
    std::cout << "White Queens:\n";
    printBitboard(whiteQueens);
    std::cout << "Black Queens:\n";
    printBitboard(blackQueens);
    std::cout << "White King:\n";
    printBitboard(whiteKing);
    std::cout << "Black King:\n";
    printBitboard(blackKing);
}

// Method to generate white pawn moves
uint64_t Board::generateWhitePawnMoves() const {
    uint64_t singlePush = (whitePawns << 8) & ~0xFF00000000000000; // Single square push
    uint64_t doublePush = ((singlePush & 0x0000FF0000000000) << 8) & ~0xFF00000000000000; // Double square push from starting position
    uint64_t leftCapture = (whitePawns << 7) & ~0x8080808080808080; // Capture to the left
    uint64_t rightCapture = (whitePawns << 9) & ~0x0101010101010101; // Capture to the right

    // Combine all possible moves into one bitboard
    return singlePush | doublePush | leftCapture | rightCapture;
}

// Helper function to print a bitboard in 8x8 format
void Board::printBitboard(uint64_t bitboard) const {
    std::bitset<64> bits(bitboard);
    for (int i = 7; i >= 0; --i) { // Print from row 8 to 1
        for (int j = 0; j < 8; ++j) { // Print columns a to h
            std::cout << bits[i * 8 + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
