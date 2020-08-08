import java.io.*;
import java.util.StringTokenizer;

public class jog {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("cowjog.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("cowjog.out")));
        int n = reader.nextInt();
        int[] speed = new int[n];
        for (int i = 0; i < n; i++) {
            reader.nextInt();
            speed[i] = reader.nextInt();
        }
        int ans = 1;
        int slow = speed[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (speed[i] > slow) {
                // cows group up
            } else {
                ans++;
            }
            slow = Math.min(slow, speed[i]);
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
