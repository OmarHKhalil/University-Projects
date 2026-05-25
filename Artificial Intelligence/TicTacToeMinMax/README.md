# Tic-Tac-Toe — AI Game (Minimax)

## Description

A **Java Swing** project providing a traditional X-O game on a 3×3 board against an unbeatable AI, relying entirely on the **Minimax** algorithm to calculate all possible outcomes of the game and choose the optimal move.

## Files

| File | Function |
|-------|---------|
| `src/omar/connect4/TicTacToeMinMax.java` | Game source file, complete Minimax algorithm logic, and graphical user interface design |

## Concepts Used

- **Minimax Algorithm:** Maximizing the state value for the AI and minimizing the potential loss based on evaluating the probability tree for a 3×3 board.
- **Board Representation:** A 2D array of type `char[][]` to represent cell states (X for the player, O for the AI, and `'-'` for empty cells).
- **Continuous Checking:** Immediate validation after every move to determine the winner based on alignment of 3 identical symbols in any row, column, or diagonal.

## Requirements

- JDK 20 or newer
- Apache NetBeans IDE or Ant build tool