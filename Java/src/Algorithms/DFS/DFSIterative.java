package Algorithms.DFS;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;

public class DFSIterative {

    static ArrayList<Integer>[] adj;
    static boolean[] visited;
    static int n,m;

    static void dfsIterative(int node) {
        Stack<Integer> stack = new Stack<>();
        stack.push(node);

        while(!stack.empty()) {
            int curNode = stack.pop();
            if (!visited[curNode]) {
                System.out.print(curNode + " ");
                visited[curNode] = true;
            }
            for (int adjVert: adj[curNode]) {
                if (!visited[adjVert]) {
                    stack.push(adjVert);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException{
        DFSRecursion.InputReader reader = new DFSRecursion.InputReader("dfs.in");
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
        dfsIterative(0);
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
