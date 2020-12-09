
import java.io.*;
import java.util.*;

public class GymRetry {

    static int[][] sessions;
    static int k,n;
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("gymnastics.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("gymnastics.out")));
        k = reader.nextInt();
        n = reader.nextInt();
        sessions = new int[k][n];
        for (int i=0; i<k; i++)
            for (int j=0; j<n; j++)
                sessions[i][j] = reader.nextInt();
        int pairs = 0;
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (i==j)
                    continue;
                if (didBetter(i,j))
                    pairs++;
            }
        }

        writer.println(pairs);
        writer.close();
    }

    static boolean didBetter(int a, int b) {
        for (int i=0;i<k;i++) {
            int aIndex = indexOf(a, i);
            int bIndex = indexOf(b, i);
            if (aIndex > bIndex)
                return false;
        }
        return true;
    }
    static int indexOf(int cow, int session) {
        for (int i=0;i<n;i++) {
            if (sessions[session][i]==cow)
                return i;
        }
        return -1;
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
