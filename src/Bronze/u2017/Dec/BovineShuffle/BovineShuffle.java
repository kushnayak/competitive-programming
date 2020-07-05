import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.StringTokenizer;

/*
ID: kushnay1
LANG: JAVA
TASK: The Bovine Shuffle
*/

public class BovineShuffle  {

    public static void main(String[] args) throws Exception {
        String in = "shuffle.in";
        String out = "shuffle.out";
        BufferedReader reader = new BufferedReader(new FileReader(in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokens.nextToken());
        int[][] swaps = new int[3][2];
        int[] swappedNums = new int[n];
        tokens = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            swappedNums[i] = Integer.parseInt(tokens.nextToken());
        }
        System.out.println(Arrays.toString(swappedNums));
        int currentswap = -1;
        for (int i = 0; i < n; i++) {
            int currentnum = swappedNums[i];
            if (currentnum != i + 1) {
                int lostindex = indexFinder(swappedNums, i + 1);
                swaps[currentswap + 1][0] = i;
                swaps[currentswap + 1][1] = lostindex;
                int temp = swappedNums[i];
                swappedNums[i] = swappedNums[lostindex];
                swappedNums[lostindex] = temp;
                currentswap++;

            }
        }

        String[] beforeSwap = new String[n];
        tokens = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            beforeSwap[i] = tokens.nextToken();
        }

        for (int i = swaps.length - 1; i >= 0; i--) {
            System.out.println(Arrays.toString(swaps[i]));
            String temp = beforeSwap[swaps[i][0]];
            beforeSwap[swaps[i][0]] = beforeSwap[swaps[i][1]];
            beforeSwap[swaps[i][1]] = temp;

        }
        System.out.println(Arrays.toString(beforeSwap));



    }

    static int indexFinder(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }


}
