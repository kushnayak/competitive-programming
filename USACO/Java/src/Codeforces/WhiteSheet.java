package Codeforces;

import java.io.*;
import java.util.StringTokenizer;

public class WhiteSheet {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), 32768);
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int x1 = Integer.parseInt(tokenizer.nextToken());
        int y1 = Integer.parseInt(tokenizer.nextToken());
        int x2 = Integer.parseInt(tokenizer.nextToken());
        int y2 = Integer.parseInt(tokenizer.nextToken());

        tokenizer = new StringTokenizer(reader.readLine());
        int x3 = Integer.parseInt(tokenizer.nextToken());
        int y3 = Integer.parseInt(tokenizer.nextToken());
        int x4 = Integer.parseInt(tokenizer.nextToken());
        int y4 = Integer.parseInt(tokenizer.nextToken());

        tokenizer = new StringTokenizer(reader.readLine());
        int x5 = Integer.parseInt(tokenizer.nextToken());
        int y5 = Integer.parseInt(tokenizer.nextToken());
        int x6 = Integer.parseInt(tokenizer.nextToken());
        int y6 = Integer.parseInt(tokenizer.nextToken());


        PrintWriter pw = new PrintWriter(System.out);
        pw.close();
    }
}
