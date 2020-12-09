
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ChessboardandQueens {

    static boolean validBoard(char[][] board) {
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in),32768);
        StringTokenizer tokenizer;
        char[][] board = new char[8][8];
        for (int i = 0; i < 8; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            String line = tokenizer.nextToken();
            for (int j = 0; j < 8; j++) {
                board[i][j] = line.charAt(j);
            }
        }
        System.out.println(Arrays.deepToString(board));
    }

}
