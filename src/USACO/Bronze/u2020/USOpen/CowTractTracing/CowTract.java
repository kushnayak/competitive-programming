
import java.io.*;
import java.util.*;

public class CowTract {


    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader(".in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(".out")));
        int N = reader.nextInt();
        int T = reader.nextInt();
        final int MAX = 251;
        boolean[] infected = new boolean[N+1];
        int[] x = new int[MAX], y = new int[MAX];
        String inf = reader.next();
        for (int i=1; i<=N; i++) {
            if (inf.charAt(i)==1)
                infected[i] = false;
        }
        for (int i=0;i<T;i++) {
            int t = reader.nextInt();
            x[t] = reader.nextInt();
            y[t] = reader.nextInt();
        }
        for (int i=1;i<=N;i++) {
            int minK = Integer.MAX_VALUE;
            int maxK = 0;
            boolean[] curInfected = new boolean[N];
            curInfected[i] = true;
            for (int j=0; j<MAX; j++) {
                if (!(x[j]==0)) {
                    if (curInfected[x[j]]||curInfected[y[j]]) {
                        curInfected[x[j]] = true;
                        curInfected[y[j]] = true;
                    }
                }
            }
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
