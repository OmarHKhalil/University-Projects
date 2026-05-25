
import java.awt.Font;
import java.awt.GridLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
/**
 *
 * @author aa
 */
public class connect4 extends javax.swing.JFrame implements ActionListener {

    private JLabel[][] array = new JLabel[6][7];
    private char[][] board = new char[6][7];
    char PLAYER = 'X';
    char AI = 'O';

    public connect4() {
        setTitle("Connect4");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        initComponents();
        connect4.setLayout(new GridLayout(6, 7));

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                board[i][j] = '-';
                array[i][j] = new JLabel("");
                array[i][j].setText("515");
                array[i][j].setOpaque(true);
                array[i][j].setFont(new Font("Arial", Font.PLAIN, 60));
                array[i][j].setBorder(BorderFactory.createLineBorder(Color.PINK));
                array[i][j].setHorizontalAlignment(SwingConstants.CENTER);
                array[i][j].setOpaque(true);
                connect4.add(array[i][j]);

            }
        }
        col1.addActionListener(this);
        col2.addActionListener(this);
        col3.addActionListener(this);
        col4.addActionListener(this);
        col5.addActionListener(this);
        col6.addActionListener(this);
        col7.addActionListener(this);
        setVisible(true);
        connect4.revalidate();
        connect4.repaint();
    }

    public void actionPerformed(ActionEvent e) {

        JButton buttonClicked = (JButton) e.getSource();
        int row = -1, col = -1;
        if (buttonClicked == col1) {

            col = 0;
        } else if (buttonClicked == col2) {

            col = 1;
        } else if (buttonClicked == col3) {

            col = 2;
        } else if (buttonClicked == col4) {

            col = 3;
        } else if (buttonClicked == col5) {

            col = 4;
        } else if (buttonClicked == col6) {

            col = 5;
        } else if (buttonClicked == col7) {
            col = 6;

        }

        // Player move
        if (Move(col, PLAYER, board)) {
            if (Win(board) == 'X') {

                JOptionPane.showMessageDialog(this, "Player wins!");
                resetBoard();
                return;
            }
            if (isFull(board)) {
                JOptionPane.showMessageDialog(this, "It's a draw!");
                resetBoard();
                return;
            }
            //Ai move
            int move = alphaBeta(board, 5, Integer.MIN_VALUE, Integer.MAX_VALUE, true)[0];
            System.out.println(move);
            if (move != -1 || move != 0) {
                Move(move, AI, board);
                if (Win(board) == 'O') {

                    JOptionPane.showMessageDialog(this, "AI wins!");
                    resetBoard();
                    return;
                }
                if (isFull(board)) {
                    JOptionPane.showMessageDialog(this, "It's a draw!");
                    resetBoard();
                }
            }
        }
    }

    public int[] alphaBeta(char[][] board1, int depth, int alpha, int beta, boolean maximizingPlayer) {
        int c = 0;
        if (Win(board1) == 'X') {
            return new int[]{-1, -1000};
        }
        if (Win(board1) == 'O') {
            return new int[]{-1, 1000};
        }
        if (depth == 0 || isFull(board1)) {
            return new int[]{-1, 0};
        }
        int bestMove = -1;
        int bestValue = maximizingPlayer ? Integer.MIN_VALUE : Integer.MAX_VALUE;
        for (int col = 0; col < 7; col++) {
            char[][] newBoard = new char[6][7];
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 7; j++) {
                    newBoard[i][j] = board1[i][j];

                }
            }
            if (Move(col, maximizingPlayer ? 'O' : 'X', newBoard)) {
                int value = alphaBeta(newBoard, depth - 1, alpha, beta, !maximizingPlayer)[1];
                //System.out.println(value);
                if (maximizingPlayer) {
                    if (value > bestValue) {
                        bestValue = value;
                        bestMove = col;
                    }
                    alpha = Math.max(alpha, value);
                } else {
                    if (value < bestValue) {
                        bestValue = value;
                        bestMove = col;
                    }
                    beta = Math.min(beta, value);
                }
                if (alpha >= beta) {
                    break;
                }
            }
        }
        return new int[]{bestMove, bestValue};
    }

    public boolean Move(int col, char player, char[][] board1) {
        //Sout.out.println(player);
        for (int row = 6 - 1; row >= 0; row--) {
            //System.out.println("zzzz "+board1[row][col]);
            if (board1[row][col] == '-') {
                board1[row][col] = player;
                if (board[row][col] == PLAYER) {
                    array[row][col].setText("P");
                    array[row][col].setBackground(Color.RED);
                } else if (board[row][col] == AI) {
                    array[row][col].setText("AI");
                    array[row][col].setBackground(Color.blue);
                }
                return true;
            }
        }
        return false;

    }

    private boolean isFull(char[][] border1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                if (border1[i][j] == '-') {
                    return false;
                }
            }
        }
        return true;
    }

    private void resetBoard() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                board[i][j] = '-';
                array[i][j].setBackground(Color.white);

            }
        }
    }

    public char Win(char[][] board1) {
        for (int row = 0; row < 6; row++) {
            for (int col = 0; col < 7; col++) {
                char player = board1[row][col];
                if (player == '-') {
                    continue;
                }
                if (checkD(row, col, 1, 0, player, board1)
                        || checkD(row, col, 0, 1, player, board1)
                        || checkD(row, col, 1, 1, player, board1)
                        || checkD(row, col, 1, -1, player, board1)) {
                    return player;
                }
            }
        }
        return '-';
    }

    private boolean checkD(int row, int col, int rowDir, int colDir, int player, char[][] board) {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            int r = row + i * rowDir;
            int c = col + i * colDir;
            if (r >= 0 && r < 6 && c >= 0 && c < 7 && board[r][c] == player) {
                count++;
            } else {
                break;
            }
        }
        return count == 4;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        connect4 = new javax.swing.JPanel();
        col1 = new javax.swing.JButton();
        col2 = new javax.swing.JButton();
        col3 = new javax.swing.JButton();
        col4 = new javax.swing.JButton();
        col5 = new javax.swing.JButton();
        col6 = new javax.swing.JButton();
        col7 = new javax.swing.JButton();
        reset = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        javax.swing.GroupLayout connect4Layout = new javax.swing.GroupLayout(connect4);
        connect4.setLayout(connect4Layout);
        connect4Layout.setHorizontalGroup(
            connect4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        connect4Layout.setVerticalGroup(
            connect4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 240, Short.MAX_VALUE)
        );

        col1.setText("Col1");
        col1.setMaximumSize(new java.awt.Dimension(100, 100));
        col1.setMinimumSize(new java.awt.Dimension(99, 99));
        col1.setPreferredSize(new java.awt.Dimension(100, 100));
        col1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                col1ActionPerformed(evt);
            }
        });

        col2.setText("Col2");
        col2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                col2ActionPerformed(evt);
            }
        });

        col3.setText("Col3");
        col3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                col3ActionPerformed(evt);
            }
        });

        col4.setText("Col4");
        col4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                col4ActionPerformed(evt);
            }
        });

        col5.setText("Col5");
        col5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                col5ActionPerformed(evt);
            }
        });

        col6.setText("Col6");
        col6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                col6ActionPerformed(evt);
            }
        });

        col7.setText("Col7");
        col7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                col7ActionPerformed(evt);
            }
        });

        reset.setText("Reset");
        reset.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                resetActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(53, 53, 53)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(connect4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(col1, javax.swing.GroupLayout.PREFERRED_SIZE, 138, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(reset, javax.swing.GroupLayout.DEFAULT_SIZE, 138, Short.MAX_VALUE)
                            .addComponent(col2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(col3, javax.swing.GroupLayout.PREFERRED_SIZE, 138, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(col4, javax.swing.GroupLayout.PREFERRED_SIZE, 138, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(col5, javax.swing.GroupLayout.PREFERRED_SIZE, 138, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(col6, javax.swing.GroupLayout.PREFERRED_SIZE, 138, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(col7, javax.swing.GroupLayout.PREFERRED_SIZE, 138, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(27, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(41, Short.MAX_VALUE)
                .addComponent(reset, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(col1, javax.swing.GroupLayout.PREFERRED_SIZE, 42, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(col5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(col6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(col7, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(col3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(col4, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(col2, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addGap(18, 18, 18)
                .addComponent(connect4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void col1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_col1ActionPerformed
        // TODO add your handling code here:


    }//GEN-LAST:event_col1ActionPerformed

    private void col2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_col2ActionPerformed
        // TODO add your handling code here:

    }//GEN-LAST:event_col2ActionPerformed

    private void col3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_col3ActionPerformed
        // TODO add your handling code here:

    }//GEN-LAST:event_col3ActionPerformed

    private void col4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_col4ActionPerformed
        // TODO add your handling code here:

    }//GEN-LAST:event_col4ActionPerformed

    private void col5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_col5ActionPerformed
        // TODO add your handling code here:

    }//GEN-LAST:event_col5ActionPerformed

    private void col7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_col7ActionPerformed
        // TODO add your handling code here:

    }//GEN-LAST:event_col7ActionPerformed

    private void col6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_col6ActionPerformed
        // TODO add your handling code here:

    }//GEN-LAST:event_col6ActionPerformed

    private void resetActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_resetActionPerformed
        // TODO add your handling code here:
        resetBoard();
    }//GEN-LAST:event_resetActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;

                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(connect4.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);

        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(connect4.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);

        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(connect4.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);

        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(connect4.class
                    .getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new connect4().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton col1;
    private javax.swing.JButton col2;
    private javax.swing.JButton col3;
    private javax.swing.JButton col4;
    private javax.swing.JButton col5;
    private javax.swing.JButton col6;
    private javax.swing.JButton col7;
    private javax.swing.JPanel connect4;
    private javax.swing.JButton reset;
    // End of variables declaration//GEN-END:variables
}
