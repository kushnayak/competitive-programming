
import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Learning {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("learning.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("learning.out")));
        int N = reader.nextInt(); int A = reader.nextInt(); int B = reader.nextInt();
        ArrayList<Interval> intervals = new ArrayList<>(N);
        for (int i=0; i<N; ++i) {
            Interval curr = new Interval(reader.next(), reader.nextInt());
            intervals.add(curr);

        }
        int notSpotted = 0;
        intervals.sort(Comparator.comparingInt(a -> a.weight));
        intervals.forEach(x -> System.out.println(x.spotted + " " + x.weight));
        for (int i=0; i<N; i++) {
            Interval cur = intervals.get(i);
            if ((A<=cur.weight && cur.weight<=B) &&cur.spotted.equals("NS")) {
                notSpotted++;

            }
        }

        writer.close();
    }

    static class Interval {
        int weight;
        String spotted;
        public Interval(String spotted, int weight) {
            this.weight = weight;
            this.spotted = spotted;
        }
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
