
import java.io.*;
import java.util.StringTokenizer;

public class Speeding {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("speeding.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("speeding.out")));
        int N = reader.nextInt();
        int M = reader.nextInt();
        int[] limitSpeed = new int[100];
        int[] bessieSpeed = new int[100];
        int curMile = 0;
        for (int i=0; i<N; i++) {
            int segment = reader.nextInt();
            int speed = reader.nextInt();
            for (int j=0; j<segment; j++) {
                limitSpeed[curMile] = speed;
                curMile++;
            }
        }
        curMile = 0;
        for (int i=0; i<N; i++) {
            int segment = reader.nextInt();
            int speed = reader.nextInt();
            for (int j=0; j<segment; j++) {
                bessieSpeed[curMile] = speed;
                curMile++;
            }
        }
        int ans = 0;
        for (int i=0; i<100; i++) {
            if (bessieSpeed[i] > limitSpeed[i]) {
                ans = Math.max(ans, bessieSpeed[i] - limitSpeed[i]);
            }
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
