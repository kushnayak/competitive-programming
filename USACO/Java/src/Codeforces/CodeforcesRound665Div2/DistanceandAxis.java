import java.io.*;
import java.util.StringTokenizer;

public class DistanceandAxis {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int t = Integer.parseInt(tokenizer.nextToken());
        for (int cases=0; cases<t; cases++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int n = Integer.parseInt(tokenizer.nextToken());
            int k = Integer.parseInt(tokenizer.nextToken());
            int ans = 0;
            if (k <= n) {
                ;
            } else {
                ans = k - n;
                n = k;
            }
            if (k%2==1 && n%2==0 || k%2==0 && n%2==1){
                ans++;
            }
            writer.println(ans);
        }
        writer.close();
    }


}
