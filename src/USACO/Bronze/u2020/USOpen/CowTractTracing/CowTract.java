
import java.io.*;
import java.util.*;

public class CowTract {


    static int N, T;
    static final int MAX_T = 251;
    static int[][] interactions;
    static boolean[] infected;


    static boolean consistentWithData(int patientZero, int k) {
        int[] interactionCounter = new int[N];
        boolean[] currentInfected = new boolean[N];
        currentInfected[patientZero-1] = true;
        for (int i=0; i<MAX_T; i++) {
            if (interactions[i][0]==0)
                continue;
            int x = interactions[i][0]-1;
            int y = interactions[i][0]-1;
            if ( (currentInfected[x] || currentInfected[y])
                    && interactionCounter[x] <= k && interactionCounter[y] <= k) {
                currentInfected[x] = true;
                currentInfected[y] = true;
                interactionCounter[x]++;
                interactionCounter[y]++;
            }
        }
        return Arrays.equals(infected, currentInfected);
    }

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("tracing.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("tracing.out")));
        N = reader.nextInt();
        T = reader.nextInt();
        String binary = reader.next();
        infected = new boolean[N];
        interactions = new int[MAX_T][2];
        for (int i=0; i<N; i++)
            if (binary.charAt(i) == '1')
                infected[i] = true;

        for (int i=0; i<T; i++) {
            int time = reader.nextInt();
            interactions[time][0] = reader.nextInt();
            interactions[time][1] = reader.nextInt();
        }
        boolean infinity = false;
        int total = 0;
        int maxK = 0;
        int minK = Integer.MAX_VALUE;
        for (int i=1; i<=N; i++) {
            boolean consistentOnce = false;
            for (int j=0; j<MAX_T; j++) {
                if(consistentWithData(i, j)) {
                    consistentOnce = true;
                    if (j==T)
                        infinity = true;
                    maxK = Math.max(maxK, j);
                    minK = Math.min(minK, j);
                }
            }

            if (consistentOnce)
                total++;

        }
        writer.print(total + " ");
        writer.print(minK + " ");
        if (infinity)
            writer.println("Infinity");
        else
            writer.println(maxK);


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
