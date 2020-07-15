import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;

public class CowGymnastics {

    static boolean better(int a, int b, int[][] data, int session, int n) {
        int aindex = 0;
        int bindex = 0;
        for (int i = 0; i < n; i++) {
            aindex = (data[session][i] == a) ? i : aindex;
            bindex = (data[session][i] == b) ? i : bindex;
        }
        return aindex < bindex;
    }

    static boolean betterAll(int a, int b, int[][] data, int k , int n) {
        int total = 0;
        for (int i = 0; i < k; i++) {
            if (better(a,b,data,i,n)) {
                total++;
            }
        }
        return total == k;
    }

    public static void main(String[] args) throws IOException {
        String in = "gymnastics.in";
        String out = "gymnastics.out";
        BufferedReader reader = new BufferedReader(new FileReader(in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());
        int k = Integer.parseInt(tokens.nextToken()); int n = Integer.parseInt(tokens.nextToken());

        int[][] data = new int[10][20];
        for (int i = 0; i < k; i++) {
            tokens = new StringTokenizer(reader.readLine());
            for (int j = 0; j < n; j++) {
                data[i][j] = Integer.parseInt(tokens.nextToken());
            }
        }
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (betterAll(data[0][i], data[0][j], data, k, n)) {
                    res++;
                }
            }
        }

        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(out)));
        writer.println(res);
        writer.close();




    }
}
