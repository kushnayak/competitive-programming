import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Mountain {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("mountains.in"));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int N = Integer.parseInt(tokenizer.nextToken());
        int[][] intervals = new int[N][2];
        for (int i=0;i<N;i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int x = Integer.parseInt(tokenizer.nextToken());
            int y = Integer.parseInt(tokenizer.nextToken());
            intervals[i][0] = x - y; intervals[i][1] = x + y;
        }
        Arrays.sort(intervals, new Comp());
        int maxEnd = -1;
        int ans = 0;
        System.out.println(Arrays.deepToString(intervals));
        for (int i=0;i<N;i++) {
            int right = intervals[i][1];
            if (right > maxEnd) {
                maxEnd = right;
                ans++;
            }
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("mountains.out")));
        writer.println(ans);
        writer.close();
    }

    static class Comp implements Comparator<int[]> {
        @Override
        public int compare(int[] o1, int[] o2) {
            if (o1[0] == o2[0]) return -Integer.compare(o1[1],o2[1]);
            return Integer.compare(o1[0],o2[0]);
        }
    }

}
