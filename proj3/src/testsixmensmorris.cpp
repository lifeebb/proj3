#include <gtest/gtest.h> 	  			 	 
#include "SixMensMorrisBoard.h"

TEST(SixMensMorrisBoardTest, DefaultBoardTest){
    // Needs to test that default board is correct
    CSixMensMorrisBoard board;
    std::string a=">RU:6 RC:0  WU:6 WC:0\no---------o---------o      0---1---2\n|         |         |      | 3-4-5 |\n|         |         |      6-7   8-9\n|    o----o----o    |      | A-B-C |\n|    |         |    |      D---E---F\n|    |         |    |        LEGEND\no----o         o----o\n|    |         |    |\n|    |         |    |\n|    o----o----o    |\n|         |         |\n|         |         |\no---------o---------o\n";
    EXPECT_EQ(board.ToString(),a);
    EXPECT_EQ(board.PlayerTurn(), 'R');
    EXPECT_EQ(board.UnplacedPieces('R'), 6);
    EXPECT_EQ(board.UnplacedPieces('W'), 6);
    EXPECT_EQ(board.PlayerAtPosition(0), 'o');
    EXPECT_EQ(board.GameOver(), false);
}

TEST(SixMensMorrisBoardTest, SetBoardTest){
    // Needs to test that setting board is correct
    //https://stackoverflow.com/questions/44960672/why-cant-i-make-an-int-array-using-const-int-same-as-const-char
    static const int unplaced[]={5, 5};
    const int *list=unplaced;
    const char *a="RWoooooooooooooo";
    const char *h="Rooooooooooooooo";
    std::string d=">RU:5 RC:0  WU:5 WC:0\nR---------W---------o      0---1---2\n|         |         |      | 3-4-5 |\n|         |         |      6-7   8-9\n|    o----o----o    |      | A-B-C |\n|    |         |    |      D---E---F\n|    |         |    |        LEGEND\no----o         o----o\n|    |         |    |\n|    |         |    |\n|    o----o----o    |\n|         |         |\n|         |         |\no---------o---------o\n";
    CSixMensMorrisBoard board(SIX_MENS_MORRIS_PLAYER_R, list, a, h);
    EXPECT_EQ(board.ToString(), d);
    EXPECT_EQ(board.PlayerTurn(), 'R');
    board.Place('R', 0);
    static const int unplaced1[]={0, 0};
    const int *list1=unplaced1;
    const char *a1="RWRWRWRWRWRWoooo";
    const char *h1="RWRWRWRWRWRooooo";
    CSixMensMorrisBoard board1(SIX_MENS_MORRIS_PLAYER_R, list1, a1, h1);
    EXPECT_EQ(board1.PlayerTurn(), 'R');
    EXPECT_EQ(board1.UnplacedPieces('W'), 0);
    EXPECT_EQ(board1.PlayerAtPosition(1), 'W');
}

TEST(SixMensMorrisBoardTest, ResetBoardTest){
    // Needs to test that resetting to default board is correct
    CSixMensMorrisBoard board;
    std::string b=" RU:5 RC:0 >WU:6 WC:0\nR---------o---------o      0---1---2\n|         |         |      | 3-4-5 |\n|         |         |      6-7   8-9\n|    o----o----o    |      | A-B-C |\n|    |         |    |      D---E---F\n|    |         |    |        LEGEND\no----o         o----o\n|    |         |    |\n|    |         |    |\n|    o----o----o    |\n|         |         |\n|         |         |\no---------o---------o\n";
    board.Place('R', 0);
    EXPECT_EQ(board.ToString(), b);
    board.ResetBoard();
    std::string a=">RU:6 RC:0  WU:6 WC:0\no---------o---------o      0---1---2\n|         |         |      | 3-4-5 |\n|         |         |      6-7   8-9\n|    o----o----o    |      | A-B-C |\n|    |         |    |      D---E---F\n|    |         |    |        LEGEND\no----o         o----o\n|    |         |    |\n|    |         |    |\n|    o----o----o    |\n|         |         |\n|         |         |\no---------o---------o\n";
    EXPECT_EQ(board.ToString(),a);
}

TEST(SixMensMorrisBoardTest, PlacementTest){
    // Needs to test that normal placement is correct
    CSixMensMorrisBoard board;
    EXPECT_EQ(board.PlayerTurn(), 'R');
    board.Place('R', 3);
    EXPECT_EQ(board.UnplacedPieces('R'), 5);
    EXPECT_EQ(board.UnplacedPieces('W'), 6);
    EXPECT_EQ(board.PlayerAtPosition(3), 'R');
    EXPECT_EQ(board.PlayerTurn(), 'W');
    board.Place('W', 1);
    EXPECT_EQ(board.PlayerAtPosition(1), 'W');
    EXPECT_EQ(board.PlayerTurn(), 'R');
    EXPECT_EQ(board.UnplacedPieces('R'), 5);
    EXPECT_EQ(board.UnplacedPieces('W'), 5);
}

TEST(SixMensMorrisBoardTest, PlacementMillTest){
    // Needs to test that placement creating a mill is correct with removal
    CSixMensMorrisBoard board;
    board.Place('R', 0);
    board.Place('W', 3);
    board.Place('R', 1);
    board.Place('W', 4);
    EXPECT_EQ(board.PlayerTurn(), 'R');
    EXPECT_EQ(board.CanRemove('R'), false);
    board.Place('R', 2);
    EXPECT_EQ(board.PlayerTurn(), 'R');
    EXPECT_EQ(board.CanRemove('R'), true);
    board.Remove('R', 3);
    EXPECT_EQ(board.PlayerAtPosition(3), 'o');
}

TEST(SixMensMorrisBoardTest, MoveTest){
    // Needs to test that movement is correct
    CSixMensMorrisBoard board;
    board.Place('R', 0);
    board.Place('W', 3);
    board.Place('R', 1);
    board.Place('W', 2);
    board.Place('R', 6);
    board.Place('W', 13);
    board.Place('R', 8);
    board.Place('W', 15);
    board.Place('R', 9);
    board.Place('W', 10);
    board.Place('R', 7);
    board.Place('W', 12);
    EXPECT_EQ(board.PlayerTurn(), 'R');
    EXPECT_EQ(board.CanMove('R', 8),true);
    EXPECT_EQ(board.CanMove('R', 12), false);
    board.Move('R', 8, 5);
    EXPECT_EQ(board.PlayerAtPosition(5), 'R');
    EXPECT_EQ(board.PlayerTurn(), 'W');
    board.Move('W', 3, 4);
    EXPECT_EQ(board.PlayerAtPosition(4), 'W');
    EXPECT_EQ(board.PlayerTurn(), 'R');
}

TEST(SixMensMorrisBoardTest, MoveMillTest){
    // Needs to test that movement creating a mill is correct with removal
    CSixMensMorrisBoard board;
    board.Place('R', 0);
    board.Place('W', 3);
    board.Place('R', 1);
    board.Place('W', 2);
    board.Place('R', 6);
    board.Place('W', 13);
    board.Place('R', 8);
    board.Place('W', 15);
    board.Place('R', 9);
    board.Place('W', 10);
    board.Place('R', 7);
    board.Place('W', 12);
    board.Move('R', 8, 5);
    board.Move('W', 3, 4);
    board.Move('R', 7, 3);
    board.Move('W', 12, 11);
    board.Move('R', 9, 8);
    board.Move('W', 11, 14);
    EXPECT_EQ(board.PlayerTurn(), 'W');
    EXPECT_EQ(board.CanRemove('W'), true);
    board.Remove('W', 8);
    EXPECT_EQ(board.PlayerAtPosition(8), 'o');
    EXPECT_EQ(board.PlayerTurn(), 'R');
}
                                       
TEST(SixMensMorrisBoardTest, TwoPieceGameOverTest){
    // Needs to test that game over is correct when only two pieces left
    CSixMensMorrisBoard board;
    board.Place('R', 0);
    board.Place('W', 3);
    board.Place('R', 1);
    board.Place('W', 2);
    board.Place('R', 6);
    board.Place('W', 13);
    board.Place('R', 8);
    board.Place('W', 15);
    board.Place('R', 9);
    board.Place('W', 10);
    board.Place('R', 7);
    board.Place('W', 12);
    board.Move('R', 8, 5);
    board.Move('W', 3, 4);
    board.Move('R', 7, 3);
    board.Move('W', 12, 11);
    board.Move('R', 9, 8);
    board.Move('W', 11, 14);
    board.Remove('W', 8);
    board.Move('R', 5, 8);
    board.Move('W', 15, 9);
    board.Move('R', 8, 12);
    board.Move('W', 9, 15);
    board.Remove('W', 12);
    board.Move('R', 6, 7);
    board.Move('W', 15, 9);
    board.Move('R', 7, 6);
    board.Move('W', 9, 15);
    board.Remove('W', 6);
    EXPECT_EQ(board.PlayerTurn(), 'R');
    //EXPECT_EQ(board.CanMove('R',0), true);
    EXPECT_EQ(board.CanMove('R',1), false);
    EXPECT_EQ(board.CanMove('R',3), true);
    board.Move('R', 3, 7);
    board.Move('W', 15, 9);
    board.Move('R', 7, 3);
    board.Move('W', 9, 15);
    board.Remove('W', 0);
    EXPECT_EQ(board.GameOver(), true);
}

TEST(SixMensMorrisBoardTest, NoMoveGameOverTest){
    // Needs to test that game over is correct when no movement allowed
    CSixMensMorrisBoard board;
    board.Place('R', 0);
    board.Place('W', 3);
    board.Place('R', 1);
    board.Place('W', 2);
    board.Place('R', 6);
    board.Place('W', 13);
    board.Place('R', 8);
    board.Place('W', 15);
    board.Place('R', 9);
    board.Place('W', 10);
    board.Place('R', 7);
    board.Place('W', 12);
    board.Move('R', 8, 5);
    board.Move('W', 3, 4);
    board.Move('R', 7, 3);
    board.Move('W', 12, 11);
    board.Move('R', 9, 8);
    board.Move('W', 11, 14);
    board.Remove('W', 8);
    board.Move('R', 5, 8);
    board.Move('W', 15, 9);
    board.Move('R', 8, 12);
    board.Move('W', 9, 15);
    board.Remove('W', 12);
    board.Move('R', 6, 7);
    board.Move('W', 15, 9);
    board.Move('R', 7, 6);
    board.Move('W', 9, 15);
    board.Remove('W', 6);
    board.Move('R', 3, 7);
    board.Move('W', 13, 6);
    board.Move('R', 7, 3);
    board.Move('W', 10, 7);
    EXPECT_EQ(board.CanMove('R', 0), false);
    EXPECT_EQ(board.CanMove('R', 1), false);
    EXPECT_EQ(board.CanMove('R', 3), false);
    EXPECT_EQ(board.GameOver(), true);
}

TEST(SixMensMorrisBoardTest, BadParametersTest){
    // Needs to test that correct return upon bad parameters
    //test PlayerAtPosition, UnplacedPieces, Place, CanRemove, CanMove, Move, Remove
    CSixMensMorrisBoard board;
    board.Place('R', 0);
    EXPECT_EQ(board.PlayerAtPosition(-1), '\0');
    EXPECT_EQ(board.PlayerAtPosition(100), '\0');
    EXPECT_EQ(board.UnplacedPieces('S'), -1);
    EXPECT_EQ(board.UnplacedPieces('s'), -1);
    EXPECT_EQ(board.Place('S', 0), false);
    EXPECT_EQ(board.Place('S', -1), false);
    EXPECT_EQ(board.Place('S', 100), false);
    EXPECT_EQ(board.Place('R', -1), false);
    EXPECT_EQ(board.Place('R', 100), false);
    EXPECT_EQ(board.CanRemove('S'), false);
    EXPECT_EQ(board.CanRemove('s'), false);
    EXPECT_EQ(board.CanMove('S', 0), false);
    EXPECT_EQ(board.CanMove('!', 1), false);
    EXPECT_EQ(board.CanMove('R', 3), false);
    EXPECT_EQ(board.Move('S', 0, 1), false);
    EXPECT_EQ(board.Move('R', 0, 3), false);
    EXPECT_EQ(board.Move('R', 0, 17), false);
    EXPECT_EQ(board.Move('R', 17, 0), false);
    EXPECT_EQ(board.Remove('S', 0), false);
    EXPECT_EQ(board.Remove('R', 0), false);
    EXPECT_EQ(board.Remove('R', -17), false);
}

