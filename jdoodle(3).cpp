#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Define the board size
const int BOARD_SIZE = 8;

// Enum to represent piece types
enum class Piece { Empty, King, Queen, Rook, Bishop, Knight, Pawn };

// Enum to represent piece colors
enum class Color { White, Black };

// Class to represent a chess piece
class ChessPiece {
public:
    Piece type;
    Color color;

    ChessPiece(Piece t = Piece::Empty, Color c = Color::White)
        : type(t), color(c) {}

    char getSymbol() const {
        if (type == Piece::Empty) return '.';
        char symbols[] = {'K', 'Q', 'R', 'B', 'N', 'P'};
        return (color == Color::White) ? toupper(symbols[static_cast<int>(type) - 1]) : tolower(symbols[static_cast<int>(type) - 1]);
    }
};

// ChessBoard class to represent the chess game
class ChessBoard {
private:
    ChessPiece board[BOARD_SIZE][BOARD_SIZE];

public:
    ChessBoard() {
        resetBoard();
    }

    void resetBoard() {
        // Place the pieces for White
        board[0][0] = ChessPiece(Piece::Rook, Color::White);
        board[0][1] = ChessPiece(Piece::Knight, Color::White);
        board[0][2] = ChessPiece(Piece::Bishop, Color::White);
        board[0][3] = ChessPiece(Piece::Queen, Color::White);
        board[0][4] = ChessPiece(Piece::King, Color::White);
        board[0][5] = ChessPiece(Piece::Bishop, Color::White);
        board[0][6] = ChessPiece(Piece::Knight, Color::White);
        board[0][7] = ChessPiece(Piece::Rook, Color::White);
        for (int i = 0; i < BOARD_SIZE; i++) {
            board[1][i] = ChessPiece(Piece::Pawn, Color::White);
        }

        // Place the pieces for Black
        board[7][0] = ChessPiece(Piece::Rook, Color::Black);
        board[7][1] = ChessPiece(Piece::Knight, Color::Black);
        board[7][2] = ChessPiece(Piece::Bishop, Color::Black);
        board[7][3] = ChessPiece(Piece::Queen, Color::Black);
        board[7][4] = ChessPiece(Piece::King, Color::Black);
        board[7][5] = ChessPiece(Piece::Bishop, Color::Black);
        board[7][6] = ChessPiece(Piece::Knight, Color::Black);
        board[7][7] = ChessPiece(Piece::Rook, Color::Black);
        for (int i = 0; i < BOARD_SIZE; i++) {
            board[6][i] = ChessPiece(Piece::Pawn, Color::Black);
        }

        // Empty spaces
        for (int i = 2; i < 6; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = ChessPiece(Piece::Empty, Color::White);
            }
        }
    }

    void displayBoard() const {
        cout << "\n  a b c d e f g h\n";
        for (int i = 0; i < BOARD_SIZE; i++) {
            cout << (8 - i) << " ";
            for (int j = 0; j < BOARD_SIZE; j++) {
                cout << board[i][j].getSymbol() << " ";
            }
            cout << (8 - i) << "\n";
        }
        cout << "  a b c d e f g h\n";
    }

    bool isValidMove(const string& move, Color color) {
        // Example of validating input move (very basic)
        if (move.length() != 5) return false;
        char startCol = move[0];
        char startRow = move[1];
        char endCol = move[3];
        char endRow = move[4];

        // Check if the move is within bounds
        if (startCol < 'a' || startCol > 'h' || endCol < 'a' || endCol > 'h' ||
            startRow < '1' || startRow > '8' || endRow < '1' || endRow > '8') {
            return false;
        }

        int startX = 8 - (startRow - '0');
        int startY = startCol - 'a';
        int endX = 8 - (endRow - '0');
        int endY = endCol - 'a';

        // Check if there's a piece of the right color at the start position
        ChessPiece& piece = board[startX][startY];
        if (piece.type == Piece::Empty || piece.color != color) {
            return false;
        }

        // Basic move check: Destination must be empty or contain an opponent's piece
        ChessPiece& destination = board[endX][endY];
        if (destination.color == color) return false;  // Can't land on your own piece

        return true;
    }

    void movePiece(const string& move) {
        char startCol = move[0];
        char startRow = move[1];
        char endCol = move[3];
        char endRow = move[4];

        int startX = 8 - (startRow - '0');
        int startY = startCol - 'a';
        int endX = 8 - (endRow - '0');
        int endY = endCol - 'a';

        // Perform the move
        board[endX][endY] = board[startX][startY];
        board[startX][startY] = ChessPiece(Piece::Empty, Color::White);
    }
};

int main() {
    ChessBoard board;
    string move;
    Color currentPlayer = Color::White;

    while (true) {
        board.displayBoard();
        cout << (currentPlayer == Color::White ? "White's move: " : "Black's move: ");
        getline(cin, move);

        if (move == "exit") break;

        if (board.isValidMove(move, currentPlayer)) {
            board.movePiece(move);
            currentPlayer = (currentPlayer == Color::White) ? Color::Black : Color::White;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}
