/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package omar.connect4;

/**
 *
 * @author MAJDEAK
 */
 
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TicTacToeMinMax extends JFrame implements ActionListener {

    private JButton[][] buttons = new JButton[3][3];
    private char[][] board = new char[3][3];
    private char currentPlayer = 'X';

    public TicTacToeMinMax() {
        setTitle("Tic-Tac-Toe with Minimax");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(3, 3));

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                buttons[i][j] = new JButton("");
                buttons[i][j].setFont(new Font("Arial", Font.PLAIN, 60));
                buttons[i][j].setFocusPainted(false);
                buttons[i][j].addActionListener(this);
                add(buttons[i][j]);
                board[i][j] = '-';
            }
        }

        setVisible(true);
    }

    public static void main(String[] args) {
        new TicTacToeMinMax();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JButton buttonClicked = (JButton) e.getSource();
        int row = -1, col = -1;

        // Find the button's position in the grid
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (buttons[i][j] == buttonClicked) {
                    row = i;
                    col = j;
                    break;
                }
            }
        }

        // Player move
        if (board[row][col] == '-') {
            board[row][col] = currentPlayer;
            buttonClicked.setText(String.valueOf(currentPlayer));
            buttonClicked.setEnabled(false);
            if (isWinner(currentPlayer)) {
                JOptionPane.showMessageDialog(this, "Player " + currentPlayer + " wins!");
                resetBoard();
                return;
            } else if (isBoardFull()) {
                JOptionPane.showMessageDialog(this, "It's a draw!");
                resetBoard();
                return;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

            // AI move
            if (currentPlayer == 'O') {
                int[] move = findBestMove();
                board[move[0]][move[1]] = 'O';
                buttons[move[0]][move[1]].setText("O");
                buttons[move[0]][move[1]].setEnabled(false);
                if (isWinner('O')) {
                    JOptionPane.showMessageDialog(this, "Player O wins!");
                    resetBoard();
                } else if (isBoardFull()) {
                    JOptionPane.showMessageDialog(this, "It's a draw!");
                    resetBoard();
                }
                currentPlayer = 'X';
            }
        }
    }

    private int[] findBestMove() {
        int bestVal = Integer.MIN_VALUE;
        int[] bestMove = {-1, -1};

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                    
                    int moveVal = minimax(board, 0, false);
                    board[i][j] = '-';
                    if (moveVal > bestVal) {
                        bestMove[0] = i;
                        bestMove[1] = j;
                        bestVal = moveVal;
                    }
                }
            }
        }
        
        return bestMove;
    }

    private int minimax(char[][] board, int depth, boolean isMax) {
        
        int score = evaluate(board);
        System.out.println("score"+score);
        if (score == 10) return score - depth;
        if (score == -10) return score + depth;
        if (isBoardFull()) return 0;
        
        if (isMax) {
            int best = Integer.MIN_VALUE;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == '-') {
                        board[i][j] = 'O';
                        best = Math.max(best, minimax(board, depth + 1, false));
                        board[i][j] = '-';
     
                    }
                }
            }
            return best;
        } else {
            int best = Integer.MAX_VALUE;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == '-') {
                        board[i][j] = 'X';
                        best = Math.min(best, minimax(board, depth + 1, true));
                        board[i][j] = '-';
                    
                    }
                }
            }
            return best;
        }
    }

    private int evaluate(char[][] board) {
        for (int row = 0; row < 3; row++) {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
                if (board[row][0] == 'O') return 10;
                else if (board[row][0] == 'X') return -10;
            }
        }

        for (int col = 0; col < 3; col++) {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
                if (board[0][col] == 'O') return 10;
                else if (board[0][col] == 'X') return -10;
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            if (board[0][0] == 'O') return 10;
            else if (board[0][0] == 'X') return -10;
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            if (board[0][2] == 'O') return 10;
            else if (board[0][2] == 'X') return -10;
        }

        return 0;
    }

    private boolean isWinner(char player) {
        return (board[0][0] == player && board[0][1] == player && board[0][2] == player) ||
               (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||
               (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||
               (board[0][0] == player && board[1][0] == player && board[2][0] == player) ||
               (board[0][1] == player && board[1][1] == player && board[2][1] == player) ||
               (board[0][2] == player && board[1][2] == player && board[2][2] == player) ||
               (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
               (board[0][2] == player && board[1][1] == player && board[2][0] == player);
    }

    private boolean isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    return false;
                }
            }
        }
        return true;
    }

    private void resetBoard() {
        currentPlayer = 'X';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '-';
                buttons[i][j].setText("");
                buttons[i][j].setEnabled(true);
            }
        }
    }
}
