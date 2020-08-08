import java.io.*;
import java.util.StringTokenizer;

public class Marathon {


    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("marathon.in");
        int n = reader.nextInt();
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = reader.nextInt();
            y[i] = reader.nextInt();
        }
        int total = 0;
        for (int i = 0; i < n - 1; i++) {
            total += Math.abs(x[i] - x[i + 1]) + Math.abs(y[i] - y[i + 1]);
        }
        int largestSkip = 0;
        for (int i = 1; i < n-1; i++) {
            int noSkip = Math.abs(x[i] - x[i + 1]) + Math.abs(y[i] - y[i + 1]) + Math.abs(x[i] - x[i - 1]) + Math.abs(y[i] - y[i - 1]);
            int skipDist = Math.abs(x[i - 1] - x[i + 1]) + Math.abs(y[i + 1] - y[i - 1]);
            largestSkip = Math.max(largestSkip, noSkip - skipDist);
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("marathon.out")));
        writer.println(total - largestSkip);
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
