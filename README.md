# C-Matrix-Board-Game
First-year Software Engineering project: CLI game implementation in C.


A board game developed in C for a software engineering assignment. The game features a 1-vs-1 battle between a human player and an automated AI.

## 📋 Project Specifications & Rules

This project adheres to the following official academic requirements:

1.  **Game Setup:** Played on a 9x9 grid (Indices 1-81). 
2.  **Initial Placement:** 16 pieces (8 for Player 1, 8 for PC) are placed randomly. Initial positions are calculated to ensure no immediate captures are possible.
3.  **Player Roles:** * `1`: Human Player
    * `2`: Computer (AI)
4.  **Movement Logic (6-Way Movement):**
    * Pieces can move **1 unit** in 6 specific directions: **Left, Right, and the 4 Diagonals.**
    * **Prohibited:** Straight forward and straight backward movements are not allowed.
5.  **Capture Mechanic (Diagonal Eat):**
    * Players can capture opponents diagonally if there is a 2-unit distance ("2 çapraz").
    * The attacking piece replaces the captured piece on the target cell.
6.  **Validation:** The computer plays without errors. The user is prompted repeatedly until a valid move/cell selection is made.
7.  **Game Termination:** The game runs for a minimum of 5 turns. If the PC has not captured a piece by turn 5, the game continues until the AI successfully performs a capture.

## 🛠️ Technical Details
- **Language:** C
- **Logic:** Coordinate transformation using `(index - 1) / 9` for row and `(index - 1) % 9` for column mapping.
- **Randomization:** `srand(time(NULL))` for unpredictable AI behavior and board setup.

## 🚀 How to Compile & Run
```bash
gcc main.cpp -o matrixgame
./matrixgame
