
# JavaCC Compiler Design & Language Parsers Series

A progressive, three-part academic series exploring the fundamentals of **Compiler Design**, **Syntax Analysis**, and **Syntax-Directed Semantic Evaluation**. Built using **JavaCC (Java Compiler Compiler)** and **Java**, this repository demonstrates how to design a lexical analyzer (Lexer) and grammar parser for a custom C++-like programming language, scaling up to a runtime mathematical expression evaluator.

---

## 📚 Series Registry & Roadmap

The series is structured into three progressive development phases:

| Phase | Project Name | Scope & Core Objective | Execution Mode | Key Technologies |
| :--- | :--- | :--- | :--- | :--- |
| **01** | [Minimal Syntax Parser](#1-minimal-syntax-parser) | Basic token validation, variable declarations, and simple C++ standard I/O structure. | Single-Line Check | JavaCC, Java, Eclipse |
| **02** | [Full Syntax Parser](#2-full-syntax-parser) | Multi-statement compiler frontend supporting Control Flow Structures (`if/else`, `while`). | Interactive REPL Loop | JavaCC, Java REPL Loop |
| **03** | [Arithmetic Expression Evaluator](#3-arithmetic-expression-evulator) | Semantic evaluation layer implementing an abstract evaluation loop with operator precedence. | Inline Interpretation | JavaCC, Java `ArrayList` |

---

## 🛠️ Global Requirements & Prerequisites

To build and run any of the compiler phases locally, ensure you have:
* **Java Development Kit (JDK 15)** or newer.
* **Eclipse IDE** equipped with the **JavaCC Eclipse Plugin** (`sf.eclipse.javacc`).
* Alternatively, the raw **JavaCC CLI tool** installed on your system environment.

---

## 1. Minimal Syntax Parser

### Description
The foundation of the series, focusing on basic lexical analysis (Tokenization) and static context-free grammar analysis. It validates syntax structural units for variable instantiations, fundamental arithmetic operations, and inverted stream I/O semantics without control flow nodes.

### Supported Grammar Rules
* **Data Types:** Primitive keywords recognition: `int`, `double`, `float`, `string`, `char`, `boolean`.
* **Variables Declarations:** Supports structural constructs such as `int score;` or `double rate = 9.5;`.
* **I/O Streams:** Validates `cin >> variable;` and `cout << value;` streams.
* **Custom Tokens:** Features isolated validation rules for bespoke token constraints like `b|c`.

### Sample Valid Syntax Input
```cpp
int counter = 10;
5 + 3 * 2;
cout << "Execution Successful";

```

---

## 2. Full Syntax Parser

### Description

The intermediate tier of the ecosystem, expanding the grammar to accommodate a complete frontend parser architecture. It is wrapped inside an interactive console shell (`while` runtime loop) allowing continuous multi-statement checking until a zero termination code (`0`) is dispatched.

### Supported Grammar Rules

* **Control Flow Loops:** Full recursive checking for loops: `while (condition) { statements }`.
* **Conditional Structures:** Multi-branch logic parsing supporting `if (cond) {}`, nested `elseif (cond) {}`, and fall-through `else {}` blocks.
* **Boolean Logic Expressions:** Evaluates complex logic chains utilizing `<, <=, >, >=, ==, !=, !, &&, ||`.

### Sample Valid Script Block

```cpp
int x = 5;
while (x > 0) {
    cout << x;
    if (x == 3) {
        cout << "Checkpoint reached";
    }
}

```

---

## 3. Arithmetic Expression Evaluator

### Description

Moving beyond pure syntax checking, this advanced module integrates **Semantic Actions** directly inside the EBNF grammar productions. It functions as an inline mathematical compiler/interpreter that parses complex inline calculations, builds data stacks dynamically, and resolves calculations by adhering strictly to mathematical operator precedence rules.

### Precedence Evaluation Logic

1. **Token Ingestion:** Digits are pushed onto an Operand list (`st`), while operator characters are appended onto an Operator list (`op`).
2. **First Pass (High Precedence):** The engine triggers an internal evaluation loop resolving all multiplicative operations (`*`, `/`) from left to right.
3. **Second Pass (Low Precedence):** The engine evaluates the remaining additive operations (`+`, `-`).
4. **Final Reduction:** Prints the total resolved output upon encountering the terminal `=` flag.

### Sample Run & Evaluation Tracing

**User Input Expression:** `2+3*4=`

```text
--- Diagnostic Evaluation Stack ---
Operands List  (st): [2, 3, 4]
Operators List (op): [+, *]
-----------------------------------
Evaluating high-precedence operator '*' -> index detected.
Result computed: 12
The Last Result is: 14
FINISH

```

---

## 🚀 Compilation & CLI Execution

To compile and run any of the projects from the native terminal interface, navigate to the specific root directory and execute the following commands:

```bash
# Navigate to the target phase folder
cd 03-Arithmetic-Expression-Evaluator

# Compile generated java files into the binary destination directory
javac -d bin src/*.java

# Boot the compiler/parser executable class
java -cp bin homework.test

```

---

## 📌 Technical Notes & Architecture Summary

* **Parser Architecture:** All generated code uses a top-down, LL(k) predictive parsing methodology engineered by the JavaCC builder template.
* **Source Modification:** Always modify the source configuration file **`MyNewGrammar.jj`**. Avoid updating the output boilerplate classes (`test.java`, `TokenManager.java`) manually, as they are completely overwritten on each local compiler regeneration pass.
* **Package Architecture:** All modules run under the global namespace package `homework`.
