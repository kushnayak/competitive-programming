import java.io.*;
import java.util.StringTokenizer;

public class Movingfieldretry {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("mowing.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("mowing.out")));
        int n = reader.nextInt();
        //999, 999 is considered 0,0
        int[][] grid = new int[2000][2000];
        int[][] time = new int[2000][2000];
        int curTime = 0;
        int curX = 999;
        int curY = 999;
        int ans = 1001;
        grid[curX][curY] = 1;
        for (int i=0;i<n;i++) {
            char d = reader.next().charAt(0);
            int step = reader.nextInt();
            int x = 0, y=0;
            switch (d) {
                case 'N':
                    x = step;
                    break;
                case 'S':
                    x = -step;
                    break;
                case 'E':
                    y = step;
                    break;
                case 'W':
                    y = -step;
                    break;
            }
            for (int j=0; j<Math.abs(x); j++) {
                curTime++;
                if (x < 0) curX--;
                else curX++;
                if (grid[curX][curY] == 1) {
                    ans = Math.min(curTime - time[curX][curY], ans);
                } else {
                    grid[curX][curY] = 1;
                }
                time[curX][curY] = curTime;
            }
            for (int j=0; j<Math.abs(y); j++) {
                curTime++;
                if (y < 0) curY--;
                else curY++;
                if (grid[curX][curY] == 1) {
                    ans = Math.min(curTime - time[curX][curY], ans);
                } else {
                    grid[curX][curY] = 1;
                }
                time[curX][curY] = curTime;
            }

        }
        if (ans == 1001) writer.println(-1);
        else writer.println(ans);
        writer.close();
    }


    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        public InputReader(String file) throws FileNotFoundException {
            reader = new BufferedReader(new FileReader(file));
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
