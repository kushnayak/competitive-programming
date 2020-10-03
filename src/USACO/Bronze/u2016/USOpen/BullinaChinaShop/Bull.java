package USACO.Bronze.u2016.USOpen.BullinaChinaShop;

import java.io.*;
import java.util.StringTokenizer;

public class Bull {

    static int n,k;
    static char[][] original;
    static char[][][] pieces;
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader(".in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(".out")));
        n = reader.nextInt();
        k = reader.nextInt();
        original = new char[n][n];
        for (int i=0; i<n; i++) {
            String line = reader.next();
            for (int j=0; j<n; j++) {
                original[i][j] = line.charAt(j);
            }
        }
        pieces = new char[k][n][n];
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                String line = reader.next();
                for (int l=0; l<n; l++) {
                    pieces[l][i][j] = line.charAt(j);
                }
            }
        }

        writer.close();
    }

    static boolean validPieced(int p1, int p2) {
        char[][] piece1 = pieces[p1];
        char[][] piece2 = pieces[p2];
        boolean horizontalJoin = false;
        boolean verticalJoin = false;
        for (int i=0; i<n; i++) {
            int pieceHash = 0;
            int originalHash = 0;
            for (int j=0; j<n; j++) {
                if (piece1[i][j] == '#') pieceHash++;
                if (original[i][j] == '#') originalHash++;
            }

        }
        return false;
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
