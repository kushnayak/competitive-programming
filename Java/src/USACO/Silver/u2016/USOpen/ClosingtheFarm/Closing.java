import java.io.*;
import java.util.*;

public class Closing {
    static int n, m;
    static ArrayList<Integer>[] adj;
    static boolean[] visited, closed;

    static boolean dfs() {
        int size = 0;
        int node = 0;
        for (int i = 0; i < n; i++) {
            if (!closed[i]) {
                size++;
                node = i;
            }
        }
        Stack<Integer> stack = new Stack<>();
        stack.push(node);
        Set<Integer> set = new HashSet<>();
        while (!stack.empty()) {
            int curNode = stack.pop();
            if (!visited[curNode]) {
                visited[curNode] = true;
                set.add(curNode);
            }
            for (int adjNode: adj[curNode]) {
                if (!visited[adjNode]) {
                    stack.push(adjNode);
                }
            }
        }

        return set.size() == size;
    }

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("closing.in");
        n = reader.nextInt();
        m = reader.nextInt();
        adj = new ArrayList[n];
        visited = new boolean[n];
        closed = new boolean[n];
        for (int i = 0 ; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = reader.nextInt() - 1;
            int b = reader.nextInt() - 1;
            adj[a].add(b);
            adj[b].add(a);
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("closing.out")));
        for (int i = 0; i < n; i++) {
            boolean connected = dfs();
            if (connected) writer.println("YES");
            else writer.println("NO");
            int closedBarn = reader.nextInt() - 1;
            closed[closedBarn] = true;
            visited = closed.clone();
        }

        writer.close();

    }

    static class InputReader {
        java.io.BufferedReader reader;
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
