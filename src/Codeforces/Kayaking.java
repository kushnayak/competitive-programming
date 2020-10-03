import java.io.*;
import java.util.*;

public class Kayaking {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter writer = new PrintWriter(System.out);
        int n = 2*reader.nextInt();
        Integer[] k = new Integer[n];
        for (int i=0; i<n; i++)
            k[i] = reader.nextInt();
        Arrays.sort(k);
        int ans = 0;

        for (int i = 0; i < n - 3; i += 2)
            ans += k[i + 1] - k[i];
        System.out.println(Arrays.toString(k));
        writer.println(ans);
        writer.close();
    }


    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new InputStreamReader(System.in));
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
