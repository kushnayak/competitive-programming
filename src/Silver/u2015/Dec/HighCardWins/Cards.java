import java.io.*;
import java.util.ArrayList;

public class Cards {


    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("highcard.in"));
        int n = Integer.parseInt(reader.readLine());
        int[] nums = new int[100001];
        for (int i = 0; i<n; i++) {
            nums[Integer.parseInt(reader.readLine())] = 1;
        }
        ArrayList<Integer> elsie = new ArrayList<>(n);
        ArrayList<Integer> bessie = new ArrayList<>(n);
        for (int i = 1; i <= 2 * n; i++) {
            if (nums[i] == 1) {
                if (i == 2 * n) continue;
                elsie.add(i);
            }
            else bessie.add(i);
        }

        int ans = 0;
        for (int i = 0; i < elsie.size(); i++) {
            if (bessie.get(i) > elsie.get(i)) ans++;
            else {
                for (int j = i + 1; j < bessie.size(); j++) {
                    if (bessie.get(j) > elsie.get(i)) {
                        bessie.set(j, elsie.get(i));
                        ans++;
                        break;
                    }
                }
            }
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("highcard.out")));
        writer.println(ans);
        writer.close();





    }
}
