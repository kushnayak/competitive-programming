//very long make shorter
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class TicTac {

    static char[][] board;

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("tttt.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("tttt.out")));
        int[] letters = new int[26];
        ArrayList<Character> all = new ArrayList<>(9);
        board = new char[3][3];
        for (int i=0; i<3; i++) {
            String line = reader.next();
            for (int j=0; j<3; j++) {
                char c = line.charAt(j);
                board[i][j] = c;
                if (letters[c - 65] == 0) {
                    all.add(c);
                    letters[c - 65]++;
                }
            }
        }
        int ind = 0;
        int team =0;
        for (char c: all) if (checkValid(c)) ind++;
        for (int i=0; i<all.size(); i++) {
            for (int j=i+1; j< all.size(); j++) {
                if(checkValid(all.get(i), all.get(j))) team++;
            }
        }

        writer.println(ind);
        writer.println(team);
        writer.close();
    }

    static boolean checkValid(char c) {
        for (int i=0; i<3; i++) {
            boolean found = true;
            for (int j=0; j<3; j++) {
                if (board[i][j] != c) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
        for (int i=0; i<3; i++) {
            boolean found = true;
            for (int j=0; j<3; j++) {
                if (board[j][i] != c) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
        boolean found = true;
        for (int i=0; i<3; i++) {
            if (board[i][i] != c) {
                found = false;
                break;
            }
        }
        if (found) return true;

        found = true;
        for (int i=0; i<3; i++) {
            if (board[i][2-i] != c){
                found = false;
                break;
            }
        }

        if (found) return true;

        return false;
    }

    static boolean checkValid(char c, char v) {
        for (int i=0; i<3; i++) {
            boolean found = true;
            int cAppear = 0, vAppear = 0;
            for (int j=0; j<3; j++) {
                if (board[i][j] != c && board[i][j] != v) {
                    found = false;
                    break;
                } else {
                    if (board[i][j] == c) cAppear++;
                    if (board[i][j] == v) vAppear++;
                }
            }
            if (found && cAppear > 0 && vAppear > 0) return true;

        }
        for (int i=0; i<3; i++) {
            boolean found = true;
            int cAppear = 0, vAppear = 0;
            for (int j=0; j<3; j++) {
                if (board[j][i] != c & board[j][i] != v) {
                    found = false;
                    break;
                }else {
                    if (board[j][i] == c) cAppear++;
                    if (board[j][i] == v) vAppear++;
                }
            }
            if (found && cAppear > 0 && vAppear > 0) return true;
        }
        boolean found = true;
        int cAppear = 0, vAppear = 0;
        for (int i=0; i<3; i++) {
            if (board[i][i] != c && board[i][i] != v) {
                found = false;
                break;
            } else {
                if (board[i][i] == c) cAppear++;
                if (board[i][i] == v) vAppear++;
            }
        }
        if (found && cAppear > 0 && vAppear > 0) return true;

        cAppear = 0;
        vAppear = 0;
        found = true;
        for (int i=0; i<3; i++) {
            if (board[i][Math.abs(2-i)] != c && board[i][Math.abs(2-i)] != v){
                found = false;
                break;
            } else {
                if (board[i][Math.abs(2-i)] == c) cAppear++;
                if (board[i][Math.abs(2-i)] == v) vAppear++;
            }
        }

        if (found && cAppear > 0 && vAppear > 0) return true;

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


    }
}
