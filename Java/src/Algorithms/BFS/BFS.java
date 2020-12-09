package Algorithms.BFS;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class BFS {
    static ArrayList<Integer>[] adj;
    static boolean[] visited;
    static int n, m;

    static void bfs(int node) {
        Queue<Integer> q = new LinkedList<>();
        q.add(node);

        while (!q.isEmpty()) {
            int curNode = q.poll();
            if (!visited[curNode]) {
                System.out.print(curNode + 1 + " ");
                visited[curNode] = true;
            }
            for (int adjVert: adj[curNode]) {
                if (!visited[adjVert]) {
                    q.add(adjVert);
                }
            }
        }


    }
    public static void main(String[] args) throws IOException{
        InputReader r = new InputReader("bfs.in");
        n = r.nextInt(); m = r.nextInt();
        adj = new ArrayList[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = r.nextInt() -1;
            int b = r.nextInt() -1;
            adj[a].add(b);
            adj[b].add(a);
        }
        System.out.println(Arrays.toString(adj));
        bfs(0);
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
