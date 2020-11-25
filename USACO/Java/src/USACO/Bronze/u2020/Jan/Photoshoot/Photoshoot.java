import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Photoshoot {

    static boolean valid(int[] seq) {
        int[] sorted = seq.clone();
        Arrays.sort(sorted);
        for (int i = 0; i < sorted.length; i++) {
            if (sorted[i] != i + 1) {
                return false;
            }
        }
        return true;
    }


    static int[] generatePerm(int n, int[] afterSeq) {
        int[] res = new int[n];
        for (int i = 1; i <=n; i++) {
            res[0] = i;
            for (int j = 1; j < n; j++) {
                res[j] = afterSeq[j - 1] - res[j - 1];
            }
            if (valid(res)) {
                return res;
            }

        }
        return res;
    }

    public static void main(String[] args) throws IOException {
        String in = "photo.in";
        String out = "photo.out";
        BufferedReader reader = new BufferedReader(new FileReader(in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokens.nextToken());
        int[] arr = new int[n];
        int[] change = new int[n-1];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }
        tokens = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n - 1; i++) {
            change[i] = Integer.parseInt(tokens.nextToken());
        }

        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(out)))) {
            int[] permutation = generatePerm(n, change);
            List<String> strList = new ArrayList<>();
            for (int num: permutation) {
                strList.add(num + "");
            }
            String res = String.join(" ", strList);
            writer.print(res);
            writer.println();
        } catch (IOException e) {
            throw new RuntimeException();
        }



    }
}

