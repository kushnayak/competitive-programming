import java.io.*;
import java.util.StringTokenizer;

public class Load {

    static int n;
    static int[] xLoc, yLoc;
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("balancing.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("balancing.out")));
        n = reader.nextInt();
        int b = reader.nextInt();
        xLoc = new int[n];
        yLoc = new int[n];
        int ans = n;
        for (int i=0; i<n; i++) {
            xLoc[i] = reader.nextInt();
            yLoc[i] = reader.nextInt();
        }
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                ans = Math.min(ans, maxQuadrant(xLoc[i], yLoc[j]));
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                ans = Math.min(ans, maxQuadrant(yLoc[i], xLoc[j]));
            }
        }
        writer.println(ans);
        writer.close();
    }

    static int maxQuadrant(int x, int y) {
        int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
        int xLine = x + 1;
        int yLine = y + 1;
        for (int i=0; i<n; i++) {
            if (xLoc[i] > xLine && yLoc[i] > yLine) q1++;
            else if (xLoc[i] < xLine && yLoc[i] > yLine) q2++;
            else if (xLoc[i] < xLine && yLoc[i] < yLine) q3++;
            else if (xLoc[i] > xLine && yLoc[i] < yLine) q4++;
        }
        return Math.max(Math.max(q1,q2), Math.max(q3, q4));
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
