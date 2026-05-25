/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package omar.maze;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.JButton;
import javax.swing.JPanel;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Collections;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

/**
 *
 * @author aa
 */
public class maze extends javax.swing.JFrame {
//    private JButton generateButton;
//    private JButton resetButton;
//    private JPanel mazePanel;
    /**
     * Creates new form maze
     */
  
    private int rows = 10;
    private int cols = 10;
    private JLabel [][] array = new JLabel [rows][cols];
    private JLabel [] label = new JLabel [100];
    static int x;
    static int y;
//    private char[][] maze;
//    private char[][] maze;


    public maze() {
        initComponents();
    }

   void add(){


       maze.setLayout(new GridLayout(10,10));
       for(int i=0 ; i< 10 ; i++){
            for(int j=0 ; j<10;j++){
                array[i][j]=new JLabel();
                array[i][j].setText("omar");
                array[i][j].setBorder(BorderFactory.createLineBorder(Color.PINK));
                array[i][j].setHorizontalAlignment(SwingConstants.CENTER);
                maze.add(array[i][j]);
                array[i][j].setOpaque(true);
                array[i][j].setBackground(Color.WHITE);
            }
//              label[i] = new JLabel();
//              label[i].setText("omar");
//             label[i].setBorder(BorderFactory.createLineBorder(Color.BLACK));
//             label[i].setHorizontalAlignment(SwingConstants.CENTER);
//             maze.add(label[i]);

       }
       maze.revalidate();
        maze.repaint();
   }


public void createRandomMaze() {

    Random random = new Random();

    // Set start and end points
    int startRow = random.nextInt(10);
    int startCol = random.nextInt(10);
    int endRow = random.nextInt(10);
    int endCol = random.nextInt(10);

    // Create random walls
    for (int i = 0; i < 40; i++) {
        int row = random.nextInt(10);
        int col = random.nextInt(10);

        if ((row != startRow || col != startCol) && (row != endRow || col != endCol)) {
            JLabel label = (JLabel) maze.getComponent(row * 10 + col);
            label.setBackground(Color.BLACK);
        }
    }

    // Set start and end points
    JLabel startLabel = (JLabel) maze.getComponent(startRow * 10 + startCol);
    startLabel.setBackground(Color.GREEN);
    x=startRow * 10 + startCol;
//    System.out.println("start"+startRow);
//    System.out.println("start"+startCol);
//    System.out.println("x"+x);
//    System.out.println(x/10);
//    System.out.println(x%10);
    JLabel endLabel = (JLabel) maze.getComponent(endRow * 10 + endCol);
    endLabel.setBackground(Color.blue);
    y = endRow * 10 + endCol;
//    System.out.println("y"+y);
//    System.out.println(y/10);
//    System.out.println(y%10);
}

    private boolean dfs(int currentRow, int currentCol, int endRow, int endCol, boolean[][] visited) {
        System.out.println("row"+currentRow+"coll"+currentCol);
    // تحقق إذا كانت الخانة الحالية خارج حدود المتاهة أو تمت زيارتها من قبل أو هي جدار.
    if (currentRow < 0 || currentRow >= rows || currentCol < 0 || currentCol >= cols || visited[currentRow][currentCol] || array[currentRow][currentCol].getBackground().equals(Color.BLACK)) {
        
        System.out.println("ali");
        return false;
        
    }
    
    System.out.println(array[currentRow][currentCol].getBackground());
        System.out.println();
        System.out.println("omar");
    // تم وصول النقطة النهائية
    if (currentRow == endRow && currentCol == endCol) {
        array[currentRow][currentCol].setBackground(Color.red);
//        label[currentRow * cols + currentCol].setBackground(Color.BLUE);
        return true;
    }

    // وضع الخانة الحالية كمزورة
    
    visited[currentRow][currentCol] = true;
    array[currentRow][currentCol].setBackground(Color.YELLOW);
//    label[currentRow * cols + currentCol].setBackground(Color.GRAY);

    // الخطوات الأربع للتحرك في المتاهة
    boolean found;
    found = dfs(currentRow+1, currentCol, endRow, endCol, visited); // للأسفل
    if (found) return true;
    found = dfs(currentRow-1, currentCol, endRow, endCol, visited); // للأعلى
    if (found) return true;
    found = dfs(currentRow, currentCol+1, endRow, endCol, visited); // لليمين
    if (found) return true;
    found = dfs(currentRow, currentCol-1, endRow, endCol, visited); // لليسار

    if (found) return true;

    // تراجع (Backtracking)
    JLabel z = (JLabel) maze.getComponent(currentRow * cols + currentCol);
    z.setBackground(Color.gray);
//    label[currentRow * cols + currentCol].setBackground(Color.WHITE);
    visited[currentRow][currentCol] = false;

    return false;
}
    
    
    boolean bfs(int startRow, int startCol, int endRow, int endCol,boolean [][] visited) {
    Queue<int[]> queue = new LinkedList<>();
    queue.add(new int[]{startRow, startCol});

    while (!queue.isEmpty()) {
        int[] current = queue.poll();
        int currentRow = current[0];
        int currentCol = current[1];

        if (currentRow < 0 || currentRow >= rows || currentCol < 0 || currentCol >= cols ||
                visited[currentRow][currentCol] || array[currentRow][currentCol].getBackground().equals(Color.BLACK)) {
            continue;
        }

        if (currentRow == endRow && currentCol == endCol) {
            array[currentRow][currentCol].setBackground(Color.RED);
            return true;
        }

        visited[currentRow][currentCol] = true;
        array[currentRow][currentCol].setBackground(Color.CYAN);

        queue.add(new int[]{currentRow + 1, currentCol}); // Down
        queue.add(new int[]{currentRow - 1, currentCol}); // Up
        queue.add(new int[]{currentRow, currentCol + 1}); // Right
        queue.add(new int[]{currentRow, currentCol - 1}); // Left
    }

    return false;
}


boolean ucs(int startRow, int startCol, int endRow, int endCol, boolean[][] visited) {
    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
    pq.add(new int[]{startRow, startCol, 0});

    while (!pq.isEmpty()) {
        int[] current = pq.poll();
        int currentRow = current[0];
        int currentCol = current[1];

        if (currentRow < 0 || currentRow >= rows || currentCol < 0 || currentCol >= cols ||
                visited[currentRow][currentCol] || array[currentRow][currentCol].getBackground().equals(Color.BLACK)) {
            continue;
        }

        if (currentRow == endRow && currentCol == endCol) {
            array[currentRow][currentCol].setBackground(Color.RED);
            return true;
        }

        visited[currentRow][currentCol] = true;
        array[currentRow][currentCol].setBackground(Color.MAGENTA);

        pq.add(new int[]{currentRow + 1, currentCol, current[2] + 1}); // Down
        pq.add(new int[]{currentRow - 1, currentCol, current[2] + 1}); // Up
        pq.add(new int[]{currentRow, currentCol + 1, current[2] + 1}); // Right
        pq.add(new int[]{currentRow, currentCol - 1, current[2] + 1}); // Left
    }

    return false;
}


public boolean isGreedy(int currentRow, int currentCol, int targetRow, int targetCol, boolean[][] visited) {
    if (currentRow == targetRow && currentCol == targetCol) {
        array[currentRow][currentCol].setBackground(Color.red);
        return true;
    }
    
    if (currentRow < 0 || currentRow >= visited.length || currentCol < 0 || currentCol >= visited[0].length || visited[currentRow][currentCol] || array[currentRow][currentCol].getBackground().equals(Color.BLACK))
 {
        return false;
    }
    
    visited[currentRow][currentCol] = true;
    array[currentRow][currentCol].setBackground(Color.YELLOW);
    if (isGreedy(currentRow + 1, currentCol, targetRow, targetCol, visited) ||
        isGreedy(currentRow - 1, currentCol, targetRow, targetCol, visited) ||
        isGreedy(currentRow, currentCol + 1, targetRow, targetCol, visited) ||
        isGreedy(currentRow, currentCol - 1, targetRow, targetCol, visited)) {
        return true;
    }
    
    return false;
}

    // Clear maze

    private void resetMaze() {
        maze.removeAll();
        maze.revalidate();
        maze.repaint();
}
    
   

    
    
    
    
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new maze().setVisible(true);
            }
        });

    }
    
    
    
    
    
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        generate = new javax.swing.JButton();
        reset = new javax.swing.JButton();
        dfs = new javax.swing.JButton();
        maze = new javax.swing.JPanel();
        bfs = new javax.swing.JButton();
        ucs = new javax.swing.JButton();
        gready = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        generate.setText("Generate");
        generate.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                generateActionPerformed(evt);
            }
        });

        reset.setText("Reset");
        reset.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                resetActionPerformed(evt);
            }
        });

        dfs.setText("DFS");
        dfs.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                dfsActionPerformed(evt);
            }
        });

        maze.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(0, 0, 0)));

        javax.swing.GroupLayout mazeLayout = new javax.swing.GroupLayout(maze);
        maze.setLayout(mazeLayout);
        mazeLayout.setHorizontalGroup(
            mazeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 309, Short.MAX_VALUE)
        );
        mazeLayout.setVerticalGroup(
            mazeLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 214, Short.MAX_VALUE)
        );

        bfs.setText("BFS");
        bfs.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                bfsActionPerformed(evt);
            }
        });

        ucs.setText("UCS");
        ucs.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                ucsActionPerformed(evt);
            }
        });

        gready.setText("GREADY");
        gready.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                greadyActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(maze, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(bfs, javax.swing.GroupLayout.PREFERRED_SIZE, 78, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(43, 43, 43)
                                .addComponent(ucs, javax.swing.GroupLayout.PREFERRED_SIZE, 78, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(generate)
                                .addGap(49, 49, 49)
                                .addComponent(reset)))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(dfs, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(gready, javax.swing.GroupLayout.DEFAULT_SIZE, 80, Short.MAX_VALUE))))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(generate)
                    .addComponent(reset)
                    .addComponent(dfs))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(ucs)
                    .addComponent(bfs)
                    .addComponent(gready))
                .addGap(9, 9, 9)
                .addComponent(maze, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void generateActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_generateActionPerformed
        // TODO add your handling code here:
        add();
        createRandomMaze();
    }//GEN-LAST:event_generateActionPerformed

    private void resetActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_resetActionPerformed
        resetMaze();
        // TODO add your handling code here:
    }//GEN-LAST:event_resetActionPerformed

    private void dfsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_dfsActionPerformed
        // TODO add your handling code here:

       boolean[][] visited = new boolean[rows][cols];
       dfs(x/10, x%10, y/10, y%10, visited);


    }//GEN-LAST:event_dfsActionPerformed

    private void bfsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_bfsActionPerformed
        // TODO add your handling code here:
        boolean[][] visited = new boolean[rows][cols];
        bfs(x/10, x%10, y/10, y%10, visited);
    }//GEN-LAST:event_bfsActionPerformed

    private void ucsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_ucsActionPerformed
        // TODO add your handling code here:
        boolean[][] visited = new boolean[rows][cols]; 
        ucs(x/10, x%10, y/10, y%10, visited);
    }//GEN-LAST:event_ucsActionPerformed

    private void greadyActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_greadyActionPerformed
        // TODO add your handling code here:
        boolean[][] visited = new boolean[rows][cols]; 
        isGreedy(x/10, x%10, y/10, y%10, visited);
    }//GEN-LAST:event_greadyActionPerformed

    /**
     * @param args the command line arguments
     */



// Example usage in a JFrame

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton bfs;
    private javax.swing.JButton dfs;
    private javax.swing.JButton generate;
    private javax.swing.JButton gready;
    private javax.swing.JPanel maze;
    private javax.swing.JButton reset;
    private javax.swing.JButton ucs;
    // End of variables declaration//GEN-END:variables




}
