import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Rest {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("reststops.in"));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int totalDist = Integer.parseInt(tokenizer.nextToken());
        int n = Integer.parseInt(tokenizer.nextToken());
        int frate = Integer.parseInt(tokenizer.nextToken());
        int brate = Integer.parseInt(tokenizer.nextToken());
        int[] stops = new int[100000];
        int[] taste = new int[100000];
        boolean[] isMax = new boolean[100000];
        for (int i=0; i<n ; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            stops[i] = Integer.parseInt(tokenizer.nextToken());
            taste[i] = Integer.parseInt(tokenizer.nextToken());
        }
        int mx = 0;
        for(int i=n-1;i>=0;i--)
            if(taste[i] > mx)
            {
                isMax[i] = true;
                mx = taste[i];
            }
        BigInteger ans = new BigInteger("0");
        BigInteger tf = new BigInteger("0");
        BigInteger tb = new BigInteger("0");
        int lastx = 0;
        for(int i=0;i<n;i++) if(isMax[i])
        {
            tf = tf.add(BigInteger.valueOf((stops[i] - lastx)*frate));
            tb = tb.add(BigInteger.valueOf((stops[i] - lastx)*brate));
            ans = ans.add((tf.subtract(tb)).multiply(BigInteger.valueOf(stops[i])));
            tb = new BigInteger("0").add(tf);
            lastx = stops[i];
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("reststops.out")));
        writer.println(ans);
        writer.close();


    }
}
