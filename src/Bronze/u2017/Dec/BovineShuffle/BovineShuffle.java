package Bronze.u2017.Dec.BovineShuffle;/*
ID: kushnay1
LANG: JAVA
TASK: The Bovine Shuffle
*/

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BovineShuffle {

    public static void main(String[] args) throws IOException {

        String in = "shuffle.in";
        String out = "shuffle.out";
        BufferedReader reader = new BufferedReader(new FileReader(in));

        StringTokenizer tokens = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokens.nextToken());
        int[] shuffle = new int[n];

        tokens = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            shuffle[i] = Integer.parseInt(tokens.nextToken()) - 1;
        }

        String[] beforeShuffle = new String[n];

        tokens = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            beforeShuffle[i] = tokens.nextToken();
        }


        String[] placedSequence = new String[n];

        for (int j = 0;j < 3; j++) {
            for (int i = 0; i < n; i++) {

                placedSequence[i] = beforeShuffle[shuffle[i]];
            }
            beforeShuffle = placedSequence.clone();
        }

        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(out)))) {
            for (String id: placedSequence) {
                writer.println(id);
            }
        }
        catch (IOException e) {
            throw new RuntimeException();
        }




    }


}
