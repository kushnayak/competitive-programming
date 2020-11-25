
import java.io.*;
import java.util.*;

public class Rework {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("pails.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("pails.out")));
        int x = reader.nextInt(), y = reader.nextInt(), m = reader.nextInt();
        int max = 0;
        int xPos = m/x;
        for (int i=0;i<=xPos; i++) {
            int yPos = (m-i*x)/y;
            max = Math.max(max, i*x+yPos*y);
        }
        writer.println(max);
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
