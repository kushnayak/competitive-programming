import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Triangles {
    public static void main(String[] args) throws IOException {
        String in = "triangles.in";
        String out = "triangles.out";
        BufferedReader reader = new BufferedReader(new FileReader(in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokens.nextToken());
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            tokens = new StringTokenizer(reader.readLine());
            x[i] = Integer.parseInt(tokens.nextToken());
            y[i] = Integer.parseInt(tokens.nextToken());
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || y[i] != y[j]) continue;
                for (int k = 0; k < n; k++) {
                    if (k == j || x[k] != x[j]) continue;
                    max = Math.max(Math.abs(x[i] - x[j]) * Math.abs(y[j] - y[k]),max);
                }
            }
        }
        try (PrintWriter writer = new PrintWriter(new FileWriter(out))) {
            writer.println(max);
        } catch (IOException e) {
            throw new RuntimeException();
        }

    }
}
