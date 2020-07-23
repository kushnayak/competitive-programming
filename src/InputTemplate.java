import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class InputTemplate {

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
