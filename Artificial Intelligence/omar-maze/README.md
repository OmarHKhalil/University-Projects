# Maze Generator and Solver (DFS)

## Description

A **Java Swing** application that generates a random 10×10 maze (walls, a green starting point, and a red ending point), then searches for a path from start to finish using **Depth-First Search (DFS)** while highlighting the solution path on the interface.

## Main Files

| File | Function |
|-------|---------|
| `src/omar/maze/maze.java` | GUI, maze generation, and interactive DFS |
| `src/omar/maze/dfs.java` | DFS logic on an integer matrix (pathfinding) |
| `src/omar/maze/OmarMaze.java` | Default entry point (currently empty) |
| `src/maze1.java` | Additional GUI frame |

## Concepts Used

- **Depth-First Search (DFS)** in a 2D grid
- Cell coloring representation: White (path), Black (wall), Green (start), Red (end), Blue (DFS solution path)
- Random wall generation while preserving the start and end positions

## Requirements

- JDK 20 (according to `nbproject/project.properties`)
- NetBeans IDE or Ant build tool (`build.xml`)

## Running the Project

### Via NetBeans

1. Open the `omar-maze` folder as a project.
2. Run the main class **`omar.maze.maze`** (the full interface).
3. Use the interface buttons to generate the maze, then click **DFS** to display the path.

### Via Command Line (After Building)

```bash
cd omar-maze
ant jar
cd dist
java -jar omar-maze.jar
Note: main.class in the configurations points to OmarMaze; for the full experience, run maze directly from the IDE.

Project Structure
omar-maze/
├── README.md
├── build.xml
├── src/
│   ├── maze1.java
│   └── omar/maze/
│       ├── maze.java
│       ├── dfs.java
│       └── OmarMaze.java
└── nbproject/