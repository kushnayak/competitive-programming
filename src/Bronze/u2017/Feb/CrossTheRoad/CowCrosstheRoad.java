/*
ID: kushnay1
LANG: JAVA
TASK: Why Did the Cow Cross the Road III
*/

import java.io.*;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.StringTokenizer;

public class CowCrosstheRoad {

    public static void main(String[] args) throws Exception {

        String in = "cowqueue.in";
        String out = "cowqueue.out";

        BufferedReader reader = new BufferedReader(new FileReader(in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());
        int lines = Integer.parseInt(tokens.nextToken());

        int[][] cowQueues = new int[lines][2];
        for (int i = 0; i < lines; i++) {
            tokens = new StringTokenizer(reader.readLine());
            for (int j = 0; j <= 1; j++) {
                cowQueues[i][j] = Integer.parseInt(tokens.nextToken());
            }
        }
        reader.close();

        Arrays.sort(cowQueues, Comparator.comparingInt(a -> a[0]));

        int start = 0;
        int end = 0;
        int qstart;
        int qtime;
        for (int[] queue : cowQueues) {
            qstart = queue[0];
            qtime = queue[1];
//            System.out.printf("Entered time:%d  Duration:%d%n",qstart,qtime);
            if ((qstart == start) | (qstart > start && qstart <= end)) {
                end += qtime;
            } else if (qstart > start) {
                start = qstart;
                end = qstart + qtime;
            }
//            System.out.printf("Start:%d End:%d%n",start,end);
        }

//        System.out.println(end);
        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(out)))) {
            writer.println(end);
        } catch (Exception e) {
            throw new RuntimeException();
        }


    }

}


