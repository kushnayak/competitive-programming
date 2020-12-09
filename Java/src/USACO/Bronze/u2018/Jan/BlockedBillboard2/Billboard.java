import java.io.*;
import java.util.StringTokenizer;

public class Billboard {

    static int area(int x1, int y1, int x2, int y2) {
        return (x2 - x1) * (y2 - y1);
    }

    static int tarpArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
        int bottomLeftX = Math.max(x1,x3);
        int bottomLeftY = Math.max(y1,y3);
        int topRightX = Math.min(x2,x4);
        int topRightY = Math.min(y2,y4);
        int intersect = area(bottomLeftX,bottomLeftY,topRightX,topRightY);

        int lawnArea = area(x1,y1,x2,y2);


        if (x3 <= x1 && y3 <= y1 && x4 >= x2 && y4 >= y2) {
            return 0;
        }
        if ((topRightY == y2 && bottomLeftY == y1) || (topRightX == x2 && bottomLeftX == x1)) {
            return (lawnArea == intersect) ? 0 : lawnArea - intersect;
        }

        return lawnArea;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new FileReader("billboard.in"));
        StringTokenizer tokenizer = new StringTokenizer(br.readLine());
        int x1 = Integer.parseInt(tokenizer.nextToken());
        int y1 = Integer.parseInt(tokenizer.nextToken());
        int x2 = Integer.parseInt(tokenizer.nextToken());
        int y2 = Integer.parseInt(tokenizer.nextToken());

        tokenizer = new StringTokenizer(br.readLine());
        int x3 = Integer.parseInt(tokenizer.nextToken());
        int y3 = Integer.parseInt(tokenizer.nextToken());
        int x4 = Integer.parseInt(tokenizer.nextToken());
        int y4 = Integer.parseInt(tokenizer.nextToken());


        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("billboard.out")));
        writer.println(tarpArea(x1,y1,x2,y2,x3,y3,x4,y4));
        writer.close();
    }
}
