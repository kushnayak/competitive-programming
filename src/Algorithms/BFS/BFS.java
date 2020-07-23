package Algorithms.BFS;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class BFS {
    static ArrayList<Integer>[] adj;
    static boolean[] visited;
    static int v, e;

    static void dfs(int node) {
        Queue<Integer> q = new LinkedList<>();


    }
    public static void main(String[] args) throws IOException{
        InputReader r = new InputReader("bfs.in");
        v = r.nextInt(); e = r.nextInt();
        adj = new ArrayList[v];
        visited = new boolean[v];
        for (int i = 0; i < v; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < e; i++) {
            int a = r.nextInt() - 1;
            int b = r.nextInt() - 1;
            adj[a].add(b);
            adj[b].add(a);
        }
        System.out.println(Arrays.toString(adj));

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
