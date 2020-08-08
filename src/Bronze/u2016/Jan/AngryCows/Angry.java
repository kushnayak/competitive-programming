import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Angry {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("angry.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("angry.out")));
        int n = reader.nextInt();
        int[] bales = new int[n];
        for (int i=0; i<n; i++) {
            bales[i] = reader.nextInt();
        }
        Arrays.sort(bales);
//        System.out.println(Arrays.toString(bales));
        int ans = 0;
        for (int i=0; i<n; i++) {
            int right = explosionIndex(bales, i, 1);
            int left = explosionIndex(bales, i, -1);
            int pos = right - left + 1;
            ans = Math.max(ans, pos);
        }

        writer.println(ans);
        writer.close();
    }

    static int explosionIndex(int[] locations, int start, final int direction) {
        int lastExplosion = start;
        int currentRadius = 1;
        while (lastExplosion > 0 && lastExplosion < locations.length-1) {

            int nextIndex = lastExplosion;
            while (nextIndex + direction >= 0 && nextIndex + direction < locations.length && Math.abs(locations[nextIndex] - locations[nextIndex + direction]) <= currentRadius) {
                nextIndex += direction;
            }
            if (nextIndex == lastExplosion) break;

            lastExplosion = nextIndex;
            currentRadius++;
        }
        return lastExplosion;
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
