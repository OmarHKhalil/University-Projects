# Connect 4 — AI Game (Alpha-Beta Pruning)

## Description

A **Java Swing** project providing an interactive Connect 4 game against an intelligent AI based on the **Alpha-Beta Pruning** algorithm with a search depth of up to 5 levels to ensure well-thought-out and fast moves.

## Files

| File | Function |
|-------|---------|
| `src/connect4.java` | Main game source file, Alpha-Beta algorithm logic, and the 6×7 graphical user interface |
| `src/connect4.form` | Visual design file of the graphical user interface via NetBeans GUI Builder |

## Concepts Used

- **Alpha-Beta Pruning:** Pruning unpromising branches of the game tree to speed up the process of searching for the best move programmatically.
- **Board Representation:** Using a 2D array `char[][]` while tracking empty cells with the `'-'` symbol.
- **Win Checking:** An intelligent algorithm to check for four consecutive pieces in all directions (horizontally, vertically, and diagonally).

## Requirements

- JDK 20 or newer
- Apache NetBeans IDE or Ant build tool

## Running the Project

### Via NetBeans
1. Open the `omar-connect4` project inside the program.
2. Right-click on the `connect4.java` file in the `src` folder and select **Run File**.
3. (Optional) You can modify the Main Class in the project properties to `connect4` to run automatically when pressing F6.

### Via Command Line (JAR)
```bash
cd omar-connect4
ant jar
cd dist
java -jar omar-connect4.jar
How to Play
The game is played on a graphical user interface with a size of 6 rows and 7 columns.

Press the upper column buttons named from (col1 to col7) to drop your piece (Player X).

The AI (Player O) calculates and makes its move automatically and instantly as soon as you finish your move.

Relevant Folder Structure
omar-connect4/
├── README.md
├── build.xml
├── src/
│   ├── connect4.java
│   └── connect4.form
└── nbproject/