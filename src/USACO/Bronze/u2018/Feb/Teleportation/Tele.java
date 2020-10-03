import java.io.*;
import java.util.StringTokenizer;

public class Tele {
    public static void main(String[] args) throws IOException {
        StringTokenizer tokenizer = new StringTokenizer(new BufferedReader(new FileReader("teleport.in")).readLine());
        int a = Integer.parseInt(tokenizer.nextToken());
        int b = Integer.parseInt(tokenizer.nextToken());
        int x = Integer.parseInt(tokenizer.nextToken());
        int y = Integer.parseInt(tokenizer.nextToken());
        int res = Math.min(Math.abs(a - x) + Math.abs(b - y),Math.abs(a - y) + Math.abs(b - x));
        res = Math.min(res,Math.abs(a-b));
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("teleport.out")));
        writer.println(res);
        writer.close();
    }
}
