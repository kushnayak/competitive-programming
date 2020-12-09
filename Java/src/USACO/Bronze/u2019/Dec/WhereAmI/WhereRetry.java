import java.io.*;
import java.util.*;

public class WhereRetry {
    static int n;
    static String s;

    static boolean duplicate(int len) {
        HashSet<String> set = new HashSet<>();
        for (int i=0; i<n-len; i++) {
            String sub = s.substring(i, i+len+1);
            if (set.contains(sub)) return true;
            set.add(sub);
        }
        return false;
    }
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("whereami.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("whereami.out")));
        n = reader.nextInt();
        s = reader.next();

        int ans = 1;
        while (duplicate(ans)) ans++;
        writer.println(ans+1);
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
