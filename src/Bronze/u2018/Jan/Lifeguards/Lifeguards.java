
import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Lifeguards {

    static int time(int[][] timeArr, int size, int indexToSkip) {
        int start = 0;
        int end = 0;
        int total = 0;
        for (int i = 0; i < size; i++) {
            if (i == indexToSkip) {
                continue;
            }
            int startTime = timeArr[i][0];
            int endTime = timeArr[i][1];
            if (end >= startTime && startTime >= start) {
                if (endTime > end) {
                    total += endTime - end;
                    start = Math.min(start, startTime);
                    end = Math.max(endTime, end);
                }
            } else {
                start = startTime;
                end = endTime;
                total += end - start;
            }
        }
        return total;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("lifeguards.in"));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int[][] timesArr = new int[n][2];
        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            timesArr[i][0] = Integer.parseInt(tokenizer.nextToken());
            timesArr[i][1] = Integer.parseInt(tokenizer.nextToken());
        }
        Arrays.sort(timesArr, Comparator.comparingInt(a -> a[0]));

        int res = 0;
        for (int i = 0; i < n; i++) {
            res = Math.max(res,time(timesArr, n, i));
        }

        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("lifeguards.out")));
        writer.println(res);
        writer.close();


    }
}
