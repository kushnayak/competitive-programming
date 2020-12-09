import java.io.*;
import java.util.StringTokenizer;

public class Word {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("word.in"));
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("word.out")));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken()); int k = Integer.parseInt(tokenizer.nextToken());

        tokenizer = new StringTokenizer(reader.readLine());
        int total = 0;
        for (int i = 0; i < n; i++) {
            String word = tokenizer.nextToken();
            if (word.length() + total <= k) {
                if (i != 0 && word.length() <= k) writer.print(" ");
                writer.print(word);
                total += word.length();
            } else {
                total = word.length();
                writer.println();
                writer.print(word);
            }

        }
        writer.close();
    }
}
