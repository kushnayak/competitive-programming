import java.io.*;
import java.util.*;

public class Moocast {

    static ArrayList<Integer>[] adj;
    static boolean[] visited;
    static int n;

    static double distance(Point a, Point b) {
        return Math.hypot(b.x - a.x, b.y - a.y);
    }

    static int bfs(int node) {
        int cows = 0;
        Queue<Integer> q = new LinkedList<>();
        q.add(node);
        while (!q.isEmpty()) {
            int currNode = q.poll();
            if (!visited[currNode]) {
                cows++;
                visited[currNode] = true;
            }
            for (int adjCows: adj[currNode]) {
                if (!visited[adjCows]) {
                    q.add(adjCows);
                }
            }
        }
        for (int i = 0; i < n; i++) visited[i] = false;
        return cows;
    }
    public static void main(String[] args) throws IOException{
        InputReader reader = new InputReader("moocast.in");
        n = reader.nextInt();
        Point[] arr = new Point[n];
        adj = new ArrayList[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            Point point = new Point(reader.nextInt(), reader.nextInt(), reader.nextInt());
            arr[i] =  point;
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            Point from = arr[i];
            for (int j = i + 1; j < n; j++) {
                Point to = arr[j];
                double distance = distance(from, to);
                if (from.power >= distance) {
                    adj[i].add(j);
                }
                if (to.power >= distance) {
                    adj[j].add(i);
                }
            }
        }
//        System.out.println(Arrays.toString(adj));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(bfs(i), ans);
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("moocast.out")));
        writer.println(ans);
        writer.close();

    }

    static class Point {
        int x, y, power;

        public Point(int x, int y, int power) {
            this.x = x;
            this.y = y;
            this.power = power;
        }

//        @Override
//        public String toString() {
//            return "Point{" +
//                    "x=" + x +
//                    ", y=" + y +
//                    ", power=" + power +
//                    '}';
//        }
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
