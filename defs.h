//
// Created by Leddon Zwack on 8/10/24.
//

#ifndef CHESSENGINE_DEFS_H
#define CHESSENGINE_DEFS_H

#include <cstdlib>
#include <iostream>


#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if (!(n)) {       \
    std::cerr << #n << " - Failed"; \
    std::cerr << " On " << __DATE__; \
    std::cerr << " At " << __TIME__; \
    std::cerr << " In File " << __FILE__; \
    std::cerr << " At Line " << __LINE__ << std::endl; \
    std::exit(1); \
}
#endif


typedef unsigned long long U64;

#define NAME "Main 1.0"
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048

#define START_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };
enum { WHITE, BLACK, BOTH };
enum {
    A1 = 21, B1, C1, DI, El, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ, OFFBOARD
};

enum { FALSE, TRUE };

enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 };

// Current board status and move made
typedef struct {
    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    U64 posKey;

} S_UNDO;


typedef struct {
    int pieces[BRD_SQ_NUM]; // Board representation
    U64 pawns[3]; // White, black or both

    int KingSq[2];

    int side;
    int enPas;
    int fiftyMove;

    int ply; // Total moves
    int hisPly; // Half moves made so far

    int castlePerm;

    U64 posKey; // Unique key for the current position on the board

    int pceNum[13]; // Piece types (13 total)
    int bigPce[3]; // All not pawns
    int majPce[3]; // Major pieces
    int minPce[3]; // Minor pieces

    S_UNDO history[MAXGAMEMOVES];

    // Piece list
    int pList[13][10];

} S_BOARD;

/* MACROS */
#define FR2SQ(f,r) ( (21 + (f) ) + ( (r) * 10 ) )
#define SQ64(sq120) (Sq120ToSq64[(sq120)])
#define SQ120(sq64) (Sq64ToSq120[(sq64)])
#define POP(b) PopBit(b)
#define CNT(b) CountBits(b)
#define CLRBIT(bb,sq) ( (bb) &= ClearMask [(sq)] )
#define SETBIT(bb,sq) ( (bb) |= SetMask[(sq)] )

/* GLOBALS */

// 120 <--> 64
extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];

extern U64 SetMask[64];
extern U64 ClearMask[64];

extern U64 PieceKeys[13][120];
extern U64 SideKey;
extern U64 CastleKeys[16];


/* FUNCTIONS */

// init.c
extern void AllInit();

// bitboards.c
extern void PrintBitBoard(U64 bb);
extern int PopBit(U64 *bb);
extern int CountBits(U64 b);

// hashkeys.c
extern U64 GeneratePosKey(const S_BOARD *pos);

// boards.c
extern void ResetBoard(S_BOARD *pos);


#endif //CHESSENGINE_DEFS_H
