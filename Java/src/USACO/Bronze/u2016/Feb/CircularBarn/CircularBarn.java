package USACO.Bronze.u2016.Feb.CircularBarn;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class CircularBarn  {
    public static void main(String[] args) throws IOException {

        String in = "cbarn.in";
        String out = "cbarn.out";
        BufferedReader reader = new BufferedReader(new FileReader(in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokens.nextToken());
        int[] rooms = new int[n];
        int total = 0;

        for (int i = 0; i < n; i++) {
            tokens = new StringTokenizer(reader.readLine());
            int num = Integer.parseInt(tokens.nextToken());
            rooms[i] = num;
            total += num;

        }
        reader.close();

        ArrayList<Integer> possibleDist = new ArrayList<>(n);

        for (int i = 0; i < n; i++) {
            int distance = 0;
            int remaining = total;
            int index;
            for (int j = 0; j < n; j++) {
                index = (j + i >= n) ? (j + i)%n : j + i;
                remaining -= rooms[index];
                distance += remaining;

            }
            possibleDist.add(distance);
        }

        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(out)))) {
            writer.println(Collections.min(possibleDist));
        }
        catch (IOException e) {
            throw new RuntimeException();
        }





    }
}
