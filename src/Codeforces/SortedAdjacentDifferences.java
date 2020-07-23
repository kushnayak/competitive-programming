import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class SortedAdjacentDifferences {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int k = Integer.parseInt(tokenizer.nextToken());
        for (int i = 0; i < k; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int n = Integer.parseInt(tokenizer.nextToken());
            int[] arr = new int[n];
            tokenizer = new StringTokenizer(reader.readLine());
            for (int j = 0; j < n; j++) {
                arr[j] = Integer.parseInt(tokenizer.nextToken());
            }

            Arrays.sort(arr);
            int mid = (int) Math.ceil(1.0 * arr.length/2) - 1;
            int change = -1;
            int currIndex = mid;
            int steps = arr.length - 1;
            for (int j= 0; j <= steps ; j++) {
                currIndex += j * change;
                writer.print(arr[currIndex] + " ");
                change *= -1;
            }
            writer.println();
        }
        writer.close();
    }
}