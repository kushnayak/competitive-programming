import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Lemonade {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("lemonade.in"));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        Integer[] wait = new Integer[n];
        tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0 ; i < n; i++) wait[i] = Integer.parseInt(tokenizer.nextToken());
        Arrays.sort(wait, Collections.reverseOrder());
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (count > wait[i]) break;
            else count++;
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("lemonade.out")));
        writer.println(count);
        writer.close();

    }
}
