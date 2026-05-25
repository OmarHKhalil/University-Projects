# Graphical Calculator Project — Java Swing Calculator

## Description

An interactive desktop calculator application designed with a Graphical User Interface (GUI) using the **Java Swing** framework within the NetBeans IDE. The calculator utilizes **Stacks** data structures to process sequential arithmetic operations, properly managing and applying inputted numbers and mathematical operators.

## Files

| File | Function |
|-------|---------|
| `NewJFrame.java` | Main source code file containing both the graphical design layout and the core logic |

## Technical Concepts Used

- **Operands Stack (`Stack<Double>`)**: Stores numerical values and mathematical inputs entered by the user.
- **Operators Stack (`Stack<String>`)**: Holds sequential arithmetic operator symbols (`+`, `-`, `*`, `/`).
- **Event Handling**: Listens to button clicks and dynamically updates the main text display field `jTextField1`.
- **Sequential Calculation (Evaluation Loop)**: A loop triggered by the equals (`=`) button that pops elements from the stacks, evaluates the values according to the stored operations, and renders the final result on `jLabel3`.

## Supported Features

- Core arithmetic operations (Addition, Subtraction, Multiplication, and Division).
- Floating-point calculation support via the decimal point (`.`) button.
- Comprehensive resetting functionality via the `Clear` button to reinitialize stacks and refresh screen fields.

## Requirements

- Java Development Kit **JDK 8** or newer.
- An IDE supporting Swing GUI building (such as **NetBeans IDE**).

## Running the Application

1. Open the file inside your Java project inside the NetBeans IDE.
2. Right-click on the `NewJFrame.java` file and select **Run File** (or press the shortcut key `Shift + F6`).