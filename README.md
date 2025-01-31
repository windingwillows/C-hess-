# Chess Game in C++: Detailed Architecture

Code Structure

Key Classes
- `ChessPiece`: Represents individual chess pieces
  - Attributes: `type` (Piece enum), `color` (Color enum)
  - Generates piece symbols for board display
- `ChessBoard`: Manages game state and logic
  - 8x8 board representation
  - Methods for board reset, piece movement, move validation

Enums
- `Piece`: Defines chess piece types (Empty, King, Queen, Rook, Bishop, Knight, Pawn)
- `Color`: Defines piece colors (White, Black)

Core Functionality

Board Initialization
- Automatically sets up standard chess starting positions
- White pieces on rows 1-2
- Black pieces on rows 7-8
- Middle rows left empty

Move Mechanics
- Input format: `<start column><start row> to <end column><end row>`
- Basic move validation checks:
  - Correct input length
  - Board boundary constraints
  - Piece color constraints
  - Preventing moves to squares with same-color pieces

Game Loop
- Alternates turns between white and black players
- Continuously displays board
- Accepts move inputs
- Validates and executes moves
- Supports game exit via `exit` command

Technical Details
- Uses 2D array for board representation
- Implements basic move logic without full chess ruleset
- Console-based interactive gameplay
