/*
ID: kushnay1
LANG: JAVA
TASK: Mowing the Field
*/

//Taken from USACO problem solution
import java.io.*;
import java.util.*;

public class MowingTheField {

    public static void main(String[] args) throws Exception{
        String in = "mowing.in";
        String out = "mowing.out";

        BufferedReader reader = new BufferedReader(new FileReader(in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokens.nextToken());

        int[][] lastTime = new int[2001][2001];
        for (int[] ints : lastTime) {
            Arrays.fill(ints, -1);
        }
        int currentx = 1000;
        int currenty = 1000;
        lastTime[currentx][currenty] = 0;
        int answer = 1001;
        int currentTime = 0;

        for (int i = 0; i < n; i++) {
            tokens = new StringTokenizer(reader.readLine());
            String dir = tokens.nextToken();
            int steps = Integer.parseInt(tokens.nextToken());
            int dirx = 0;
            int diry = 0;
            switch (dir) {
                case "N":
                    dirx = 1;
                    break;
                case "S":
                    dirx = -1;
                    break;
                case "E" :
                    diry = 1;
                    break;
                case "W" :
                    diry = -1;
                    break;
            }
            for (int j = 1; j <= steps; j++) {
                currentx += dirx;
                currenty += diry;
                currentTime++;
                if (lastTime[currentx][currenty] >= 0 && currentTime - lastTime[currentx][currenty] < answer) {
                    answer = currentTime - lastTime[currentx][currenty];
                }
                lastTime[currentx][currenty] = currentTime;
            }

        }

        reader.close();

        answer = (answer == 1001) ? -1 : answer;

        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(out)))) {
            writer.println(answer);
        } catch (Exception e) {
            throw new RuntimeException();
        }




    }
}
