import java.io.*;
import java.util.StringTokenizer;

public class Promotion {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("promote.in"));
        StringTokenizer tokenizer;
        int[] before = new int[4];
        int[] after = new int[4];
        int totalBefore = 0;
        int totalAfter = 0;
        for (int i = 0; i < 4; i++){
            tokenizer = new StringTokenizer(reader.readLine());
            before[i] = Integer.parseInt(tokenizer.nextToken());
            after[i] = Integer.parseInt(tokenizer.nextToken());

            totalBefore += before[i];
            totalAfter += after[i];
        }
        int newPart = totalAfter - totalBefore;
        before[0] += newPart;
        int[] promotedDiv = new int[3];

        for (int i = 0; i < 3; i++) {
            int moving = before[i] - after[i];
            promotedDiv[i] = moving;
            before[i + 1] += moving;

        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("promote.out")));
        for (int num: promotedDiv) {
            writer.println(num);
        }
        writer.close();
    }

}
