import java.io.*;
import java.util.StringTokenizer;

public class Signal {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("cowsignal.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("cowsignal.out")));
        int n = reader.nextInt();
        int m = reader.nextInt();
        int k = reader.nextInt();
        char prevChar = ' ';
        for (int i=0; i<n; i++) {
            String line = reader.next();
            String kLine = kLine(line, m, k);
            for (int j=0; j<k; j++) {
                writer.print(kLine);
                writer.println();
            }
        }

        writer.close();
    }

    static String kLine(String line, int m, int k) {
        StringBuilder s = new StringBuilder();
        for (int i=0; i<m; i++) {
            char curChar = line.charAt(i);
            s.append(multiply(curChar, k));
        }
        return s.toString();
    }
    static String multiply(char c, int k) {
        StringBuilder s = new StringBuilder();
        for (int i=1; i<=k; i++) {
            s.append(c);
        }
        return s.toString();
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
