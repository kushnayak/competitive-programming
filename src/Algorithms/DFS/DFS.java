package Algorithms.DFS;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class DFS {
    static ArrayList<Integer>[] adj;
    static boolean[] visited;
    static int n, m;

    static void dfs(int node) {
        if (visited[node]) return;
        visited[node] = true;
        System.out.print(node + " ");
        for (int next: adj[node]) {
            dfs(next);
        }
    }
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("dfs.in");
        n = reader.nextInt();
        m = reader.nextInt();
        adj = new ArrayList[n];
        visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = reader.nextInt() - 1;
            int b = reader.nextInt() - 1;
            adj[a].add(b);
            adj[b].add(a);
        }
        System.out.println(Arrays.toString(adj));
        dfs(0);
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
