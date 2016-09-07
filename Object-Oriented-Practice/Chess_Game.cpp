/*
Design a chess game highly overview.
+ Basic functionalities:
- Chess Table
- Move
- Valid Move
- Player
- Chess
- a Game

+ Design Pattern Usage:
- Bridge : Make it work before it's even implemented
- Facade : Represent sub entire system
*/

enum Turn {
    First, Second;
};

enum ChessType{
    None, King, Queen;
};

class Player {
...
};

class Game {
private:
    Player firstPlayer;
    Player secondPlayer;
    ChessTable table;
public:
    Game();
    void setFirstTurn();

};

class ChessTable {
private:
    Turn nextTurn;  // who will move first
    vector<Move> moves;
    vector<Move> oldmoves;
    Chess matrix[8][8];
public:
    ChessTable();
    void reset();
    void setNextTurn(Turn o_nextTurn);
    Turn getNextTurn() const;
    void undo(int o_nmoves);
    void redo(int o_states)
    void makeMove(Move mv);
};

class Chess {
public:
    virtual Chess() {};
    virtual ~Chess() {};
    virtual ChessType getType(); // return None
};

class

class Move {
protected:
    Turn turn;
    pair<int, int> from;
    pair<int, int> to;
public:
    Move(pair, pair) {}
    ...
}
