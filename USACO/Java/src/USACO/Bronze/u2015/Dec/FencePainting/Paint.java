
import java.io.*;
import java.util.StringTokenizer;

public class Paint {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("paint.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("paint.out")));
        int a = reader.nextInt(); int b = reader.nextInt();
        int c = reader.nextInt(); int d = reader.nextInt();
        int total = 0;
        if (a <= c && c <= b || a <= d && d <= b || c <= a && a <= d ||
                c <= b && b <= d) {
            total += Math.max(b,d) - Math.min(a, c);
        } else {
            total += (b - a) + (d - c);
        }

        writer.println(total);
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
