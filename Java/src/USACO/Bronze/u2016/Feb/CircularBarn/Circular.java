import java.io.*;
import java.util.StringTokenizer;

public class Circular {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("cbarn.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("cbarn.out")));
        int n = reader.nextInt();
        int[] barn = new int[n];
        int sum = 0;
        for (int i=0; i<n; i++) {
            barn[i] = reader.nextInt();
            sum += barn[i];
        }
        int ans = Integer.MAX_VALUE;
        for (int i=0; i<n; i++) {
            int curr = sum - barn[i];
            int total = 0;
            for (int j=1; j<=n-1; j++) {
                total += curr;
                int nextIndex = (i + j >= n) ? (i + j) - n: i + j;
                curr -= barn[nextIndex];
            }
            ans = Math.min(ans, total);
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
