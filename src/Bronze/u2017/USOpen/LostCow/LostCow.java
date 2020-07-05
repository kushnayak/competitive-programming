package Bronze.u2017.USOpen.LostCow;/*
ID: kushnay1
LANG: PYTHON3
TASK: The Lost Cow
*/

import java.io.*;
import java.util.StringTokenizer;

public class LostCow {
    static String in = "lostcow.in";
    static String out = "lostcow.out";

    public static void main(String[] args) throws Exception{



        BufferedReader reader = new BufferedReader(new FileReader(in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());

        int x = Integer.parseInt(tokens.nextToken()); int y = Integer.parseInt(tokens.nextToken());

        boolean positive = true;
        int distanceTraveled = 0;
        int change = 1;


        if (x == y) {

            writer(0);

        } else {
            while (true) {

                if ((x + change >= y && x <= y && positive) | (x - change <= y && x >= y && !positive)) {
                    distanceTraveled += Math.abs(x - y);
                    break;
                } else {
                    if (positive) {
                        distanceTraveled += change * 2;
                        change *= 2;
                        positive = !positive;
                    } else {
                        distanceTraveled += change * 2;
                        change *= 2;
                        positive = !positive;
                    }
                    System.out.printf("Positive:%b Distance Traveled:%d Change:%d%n",positive,distanceTraveled,change);
                }
            }
            writer(distanceTraveled);
        }


    }

    static void writer(int num) {

        try (PrintWriter writer = new PrintWriter(new FileWriter(out))) {
            writer.println(num);
        } catch (IOException e) {
            throw new RuntimeException();
        }


    }
}
