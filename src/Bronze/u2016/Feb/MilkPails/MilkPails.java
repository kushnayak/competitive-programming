import java.io.*;
import java.util.StringTokenizer;

public class MilkPails {

    public static void main(String[] args) throws IOException {
        BufferedReader fin = new BufferedReader(new FileReader("pails.in"));
        StringTokenizer tokenizer = new StringTokenizer(fin.readLine());
        int x = Integer.parseInt(tokenizer.nextToken());
        int y = Integer.parseInt(tokenizer.nextToken());
        int m = Integer.parseInt(tokenizer.nextToken());

        int max = 0;

        if (m/x == 1) {
            int milk = x;
            max = Math.max(milk + (m - milk)/y * y, max);
        }
        if (m/y == 1) {
            int milk = y;
            max = Math.max(milk + (m - milk)/x * x, max);
        }
        for (int i = 1; i <= m/y; i++) {
            int milk = y * i;
            max = Math.max(milk + (m - milk)/x * x, max);
        }
        for (int i = 1; i <= m/x; i++) {
            int milk = x * i;
            max = Math.max(milk + (m - milk)/y * y, max);
        }

        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("pails.out")));
        writer.println(max);
        writer.close();


    }
}
