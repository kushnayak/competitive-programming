import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class CrossRoadRetry {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("cowqueue.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("cowqueue.out")));
        int n = reader.nextInt();
        int[][] intervals = new int[n][2];
        for (int i=0; i<n; i++) {
            intervals[i][0] = reader.nextInt();
            intervals[i][1] = reader.nextInt();
        }
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        int time = 0;
        for (int i=0; i<n; i++) {
            int in = intervals[i][0];
            int dur = intervals[i][1];
            if (in > time) time = in + dur;
            else {
                time += dur;
            }

        }
        writer.println(time);
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
