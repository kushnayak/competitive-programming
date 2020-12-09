import java.io.*;
import java.util.*;

public class SumofTwoValues {

    public static void main(String[] args) throws IOException {
        InputReader r = new InputReader();
        PrintWriter pw = new PrintWriter(System.out);
        int n = r.nextInt();
        int sum = r.nextInt();
        int[] arr = new int[n];
        HashMap<Integer, Integer> map = new HashMap<>(n);
        for (int i=0; i<n; i++) {
            int num = r.nextInt();
            arr[i] = num;
            if (num < sum) map.put(sum-num, i);
        }
        int f =-1, s = -1;
        for (int i=0; i<n; i++) {
            if (map.containsKey(arr[i]) && map.get(arr[i])!=i) {
                f = i;
                s = map.get(arr[i]);
                break;
            }
        }
        if (f != -1 && s!= -1) pw.println((f+1) + " " + (s+1));
        else pw.println("IMPOSSIBLE");
        pw.close();
    }

    static int indexOf(int[] arr, int n) {
        for (int i=0; i<arr.length; i++)
            if (arr[i]==n)
                return i;
        return -1;
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
