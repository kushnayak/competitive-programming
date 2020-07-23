import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;


public class Boxers {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        tokenizer = new StringTokenizer(reader.readLine());
        int[] valid = new int[150001];
        Integer[] nums = new Integer[n];
        Random random = new Random();
        for (int i = 0; i<n; i++) {
            nums[i] = (Integer.parseInt(tokenizer.nextToken()));
        }
        Arrays.sort(nums);
        int ans = 0;
        int b;
        for (int i = 0; i<n; i++) {
            int curr = nums[i];
            if (curr == 1) b = 0;
            else b = -1;
            for (int j = b; j <=1 ; j++) {
                if (valid[curr + j] == 1) continue;
                valid[curr + j] = 1;
                ans++;
                break;
            }
        }
        PrintWriter writer = new PrintWriter(System.out);
        writer.println(ans);
        writer.close();

    }
}
