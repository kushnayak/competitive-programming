import java.io.*;
import java.util.StringTokenizer;

public class Bovine {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("shuffle.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("shuffle.out")));
        int n = reader.nextInt();
        int[] shuffle = new int[n];
        String[] id = new String[n];
        String[] res = new String[n];
        for (int i=0; i<n; i++) shuffle[i] = reader.nextInt() - 1;
        for (int i=0; i<n; i++) id[i] = reader.next();

        for (int i=0; i<3; i++) {
            for (int j=0; j<n; j++) {
                int from = shuffle[j];
                res[j] = id[from];
            }
            id = res.clone();
        }

        for (String i: id) writer.println(i);
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
