import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Vegetate {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("revegetate.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("revegetate.out")));
        int n = reader.nextInt();
        int m = reader.nextInt();
        int[] pastures = new int[n];
        int[][] favorites = new int[m][2];
        Arrays.fill(pastures, 1);
        for (int i=0; i<m; i++) {
            int a = reader.nextInt() - 1;
            int b = reader.nextInt() - 1;
            int[] cur = new int[2]; cur[0] = a; cur[1] = b;
            Arrays.sort(cur);
            favorites[i] = cur;
        }
        Arrays.sort(favorites, (o1, o2) -> {
            if (o1[0] == o2[0]) {
                return Integer.compare(o1[1], o2[1]);
            } else {
                return Integer.compare(o1[0], o2[0]);
            }
        });
//        System.out.println(Arrays.deepToString(favorites));
        for (int i=0; i<m; i++) {
            int[] pair = favorites[i];
            if (pastures[pair[0]] == pastures[pair[1]]) {
                pastures[pair[1]] = pastures[pair[0]] + 1;
            }
        }
//        System.out.println(Arrays.toString(pastures));
        for (int num: pastures) writer.print(num);
        writer.println();
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
