import java.io.*;
import java.util.*;

public class Moo {

    static ArrayList<Edge>[] adj;
    static boolean[] visited;
    static int n,q;

    static int bfs(int node, int min) {
        Queue<Integer> q = new LinkedList<>();
        int ans = 0;
        q.add(node);

        while (!q.isEmpty()) {
            int curNode = q.poll();
            if (!visited[curNode]) {
                visited[curNode] = true;
                if (curNode != node) ans++;
            }
            for (Edge adjEdge: adj[curNode]) {
                if (!visited[adjEdge.to] && adjEdge.weight >= min) {
                    q.add(adjEdge.to);
                }
            }
        }
        for (int i = 0; i < n; i++) visited[i] = false;
        return ans;
    }


    public static void main(String[] args) throws IOException{
        InputReader reader = new InputReader("mootube.in");
        n = reader.nextInt();
        q = reader.nextInt();
        adj = new ArrayList[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int a = reader.nextInt() - 1;
            int b = reader.nextInt() - 1;
            int weight = reader.nextInt();
            adj[a].add(new Edge(b, weight));
            adj[b].add(new Edge(a, weight));
        }


        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("mootube.out")));
        for (int i = 0; i < q; i++) {
            int minimum = reader.nextInt();
            int rootNode = reader.nextInt() - 1;
//            System.out.println(rootNode + " " + minimum);
            int ans = bfs(rootNode, minimum);

            writer.println(ans);
        }
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
    static class Edge{
        int to;
        int weight;
        public Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }

//        @Override
//        public String toString() {
//            return to + " " + weight ;
//        }
    }

}
