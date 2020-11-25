import java.io.*;
import java.util.StringTokenizer;

public class Square {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("square.in"));
        StringTokenizer tokenizer;
        int smallestX = 10;
        int largestX = 0;
        int smallestY = 10;
        int largestY = 0;
        for (int i = 0; i < 2; i++) {
            tokenizer = new StringTokenizer(reader.readLine());

            for (int j = 0; j < 2; j++) {
                int x1 = Integer.parseInt(tokenizer.nextToken());
                int y1 = Integer.parseInt(tokenizer.nextToken());
                smallestX = Math.min(smallestX,x1);
                largestX = Math.max(largestX,x1);
                smallestY = Math.min(y1,smallestY);
                largestY = Math.max(y1,largestY);
            }
        }
        int squareSide = Math.max(largestX - smallestX, largestY - smallestY);
        PrintWriter writer = new PrintWriter(new FileWriter("square.out"));
        writer.println(squareSide * squareSide);
        writer.close();
    }
}
