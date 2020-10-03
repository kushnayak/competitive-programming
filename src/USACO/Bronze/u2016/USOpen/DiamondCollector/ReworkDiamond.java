
import java.io.*;
import java.util.*;

public class ReworkDiamond {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("diamond.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("diamond.out")));
        int n = reader.nextInt(), k = reader.nextInt();
        int[] d = new int[n];
        for (int i=0;i<n;i++)
            d[i]= reader.nextInt();
        int ans = 0;
        for (int i=0;i<n;i++) {
            int b = d[i];
            int e = b+k;
            int c = 0;
            for (int j=0;j<n;j++)
                if (b<=d[j]&&d[j]<=e)
                    c++;
            ans = Math.max(ans, c);
        }
        writer.println(ans);
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
