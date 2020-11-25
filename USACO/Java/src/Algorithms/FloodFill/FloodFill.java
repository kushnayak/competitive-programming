package Algorithms.FloodFill;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class FloodFill {

    static int[][] grid;
    static int n, m; // n is rows m is columns
    static boolean[][] visited;
    static int currentSize;

    static void floodfill(int r, int c, int color) {
        if (r < 0 || r >= n || c < 0 || c >= m) return;
        if (grid[r][c] != color) return;
        if (visited[r][c]) return;
        currentSize++;
        visited[r][c] = true;
        floodfill(r + 1, c, color);
        floodfill(r , c + 1, color);
        floodfill(r - 1, c, color);
        floodfill(r , c - 1, color);
    }
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("flood.in");
        n = reader.nextInt();
        m = reader.nextInt();
        grid = new int[n][m];
        visited = new boolean[n][m];
        currentSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = reader.nextInt();
            }
        }
        System.out.println(Arrays.deepToString(grid));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    currentSize = 0;
                    floodfill(i, j, grid[i][j]);
                    System.out.println("Current size of " + grid[i][j] + " is " + currentSize);
                }
            }
        }


    }


    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(String file) throws FileNotFoundException {
            reader = new BufferedReader(new FileReader(file));
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
