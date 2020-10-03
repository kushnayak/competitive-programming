import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Crosswords {

    static char[][] board;
    static int n , m;

    static boolean possibleStart(int i, int j) {
        boolean vertical = (i == 0 || board[i - 1][j] == '#') && board[i][j] == '.' && (i + 2 < n
                && board[i + 1][j] == '.' && board[i + 2][j] == '.');
        boolean horizontal = (j == 0 || board[i][j - 1] == '#') && board[i][j] == '.' && (j + 2 < m
                && board[i][j + 1] == '.' && board[i][j + 2] == '.');
        return (horizontal || vertical);
    }

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("crosswords.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("crosswords.out")));
        n = reader.nextInt();
        m = reader.nextInt();
        board = new char[n][m];
        for (int i = 0; i < n; i++) {
            String line = reader.next();
            for (int j = 0; j < m; j++) {
                board[i][j] = line.charAt(j);
            }
        }
        ArrayList<int[]> points = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (possibleStart(i, j)) {
                    points.add(new int[]{i + 1, j + 1});
                }
            }
        }
//        System.out.println(Arrays.deepToString(board));
//        points.forEach(x -> System.out.println(Arrays.toString(x)));
        writer.println(points.size());
        for (int[] arr: points) {
            writer.print(arr[0] + " " + arr[1]);
            writer.println();
        }
        writer.close();
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
