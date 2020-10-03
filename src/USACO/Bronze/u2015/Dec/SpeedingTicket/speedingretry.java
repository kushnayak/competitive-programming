import java.io.*;
import java.util.StringTokenizer;

public class speedingretry {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("speeding.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("speeding.out")));
        int N = reader.nextInt();
        int M = reader.nextInt();
        int[] bessie = new int[100];
        int[] limit = new int[100];
        int dist = 0;
        for (int i=0; i<N; i++) {
            int curDist = reader.nextInt();
            int lim = reader.nextInt();
            for (int j=dist; j<dist+curDist; j++) limit[j] = lim;
            dist += curDist;
        }
        dist = 0;
        for (int i=0; i<N; i++) {
            int curDist = reader.nextInt();
            int lim = reader.nextInt();
            for (int j=dist; j<dist+curDist; j++) bessie[j] = lim;
            dist += curDist;
        }

        int ans = 0;
        for (int i=0; i<100; i++) {
            if (bessie[i] > limit[i]) ans = Math.max(ans, bessie[i] - limit[i]);
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
