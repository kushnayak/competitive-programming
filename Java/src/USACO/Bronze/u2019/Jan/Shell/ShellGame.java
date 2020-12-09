import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ShellGame {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("shell.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("shell.out")));
        int n = reader.nextInt();
        int[][] swap = new int[n][3];
        int[] shell = new int[3];
        for (int i=0; i<n; i++) for (int j=0; j<3; j++) swap[i][j] = reader.nextInt() - 1;

        int ans = 0;
        for (int i=0; i<3; i++) {
            Arrays.fill(shell, 0);
            shell[i] = 1;
            int count = 0;
            for (int j=0; j<n; j++) {
                int swap1 = swap[j][0];
                int swap2 = swap[j][1];
                int temp = shell[swap1];
                shell[swap1] = shell[swap2];
                shell[swap2] = temp;
                if (shell[swap[j][2]] == 1) count++;
            }
            ans = Math.max(ans, count);
        }
        writer.println(ans);
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
