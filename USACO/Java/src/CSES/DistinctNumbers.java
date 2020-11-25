
import java.io.*;
import java.util.*;

public class DistinctNumbers {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter writer = new PrintWriter(System.out);
        int n = reader.nextInt();
        HashSet<Integer> h = new HashSet<>();
        for (int i=0; i<n; i++)
            h.add(reader.nextInt());
        writer.println(h.size());
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
