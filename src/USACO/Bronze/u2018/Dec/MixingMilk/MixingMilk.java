package USACO.Bronze.u2018.Dec.MixingMilk;

import java.io.*;
import java.util.StringTokenizer;

/*
ID: kushnay1
LANG: PYTHON3
TASK: Mixing Milk
*/
public class MixingMilk {

public static void main(String[]args) throws Exception{


        String in = "mixmilk.in";
        String out = "mixmilk.out";

        int[]amount = new int[3];
        int[]capacity = new int[3];

        StringTokenizer tokens;
        BufferedReader reader=new BufferedReader(new FileReader(in));
        for (int i = 0; i < 3; i++) {
            tokens = new StringTokenizer(reader.readLine());
            capacity[i] = Integer.parseInt(tokens.nextToken());
            amount[i] = Integer.parseInt(tokens.nextToken());
        }
        reader.close();

        int currentBucket = 0;
        int nextBucket = 1;
        int amountPoured;
        for (int i = 0; i < 100; i++) {
            currentBucket = (currentBucket == 3) ? 0: currentBucket;
            nextBucket = (nextBucket == 3) ? 0: nextBucket;
            amountPoured = Math.min(amount[currentBucket], capacity[nextBucket] - amount[nextBucket]);
            amount[currentBucket] -= amountPoured;
            amount[nextBucket] += amountPoured;
            currentBucket++;
            nextBucket++;
        }

        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(out)));

        for (int num: amount) {
            writer.println(num);
        }
        writer.close();




    }
}
