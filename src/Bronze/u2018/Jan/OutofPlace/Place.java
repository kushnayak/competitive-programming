import java.io.*;
import java.util.Arrays;

public class Place {

    static int indexOf(int[] arr, int num) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num) {
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("outofplace.in"));
        int n = Integer.parseInt(reader.readLine());
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(reader.readLine());
        }
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        int swaps = 0;
        while (!Arrays.equals(nums, sorted)) {
            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] != sorted[i]) {
                    int index = indexOf(nums,sorted[i]);
                    int temp = nums[index];
                    nums[index] = nums[i];
                    nums[i] = temp;
                    swaps++;
                }
            }
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("outofplace.out")));
        writer.println(swaps);
        writer.close();
    }
}
