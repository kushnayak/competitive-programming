import java.io.*;
import java.util.StringTokenizer;

public class TernarySequence {
    static int[] a, b;
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader();
        PrintWriter writer = new PrintWriter(System.out);
        int t = reader.nextInt();
        for (int cases=0; cases<t; cases++) {
            a = new int[3];
            b = new int[3];
            for (int i=0; i<3; i++) a[i] = reader.nextInt();
            for (int i=0; i<3; i++) b[i] = reader.nextInt();
            int ans = 0;
            ans += exhaust(2,1) * 2;
            exhaust(0, 2);
            exhaust(2,2);
            if (b[2] > 0) ans -= b[2] * 2;
            writer.println(ans);
        }

        writer.close();
    }

    static int exhaust(int aNum, int bNum) {
        int taken = Math.min(a[aNum], b[bNum]);
        a[aNum] -= taken;
        b[bNum] -= taken;
        return taken;
    }
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader() throws FileNotFoundException {
            reader = new BufferedReader(new InputStreamReader(System.in));
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
