
import java.io.*;
import java.util.StringTokenizer;

public class MilkMeasurment {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("measurement.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("measurement.out")));
        int n = reader.nextInt();
        int[] days = new int[n];
        int[] change = new int[n];
        String[] cows = new String[n];

        for (int i=0; i<n; i++) {
            days[i] = reader.nextInt();
            cows[i] = reader.next();
            change[i] = reader.nextInt();
        }

        int ans = 0;

        int elsie = 7, bessie = 7, mildred = 7;

        boolean prevElsie = true, prevBessie = true, prevMildred = true;
        boolean elsieHigh = true, bessieHigh = true, mildredHigh = true;

        for (int i=1; i<=100; i++) {

            for (int j=0; j<n; j++) {
                if (days[j] == i) {
                    switch (cows[j]){
                        case "Bessie":
                            bessie += change[j];
                            break;
                        case "Elsie":
                            elsie += change[j];
                            break;
                        case "Mildred":
                            mildred += change[j];
                            break;
                    }
                    System.out.println(bessie + " " + elsie + " " + mildred);
                    int greatest = Math.max(bessie, Math.max(elsie, mildred));
                    elsieHigh = false; bessieHigh = false; mildredHigh = false;
                    if (bessie == greatest) bessieHigh = true;
                    if (elsie == greatest) elsieHigh = true;
                    if (mildred == greatest) mildredHigh = true;
                    if (!(prevBessie==bessieHigh && prevMildred==mildredHigh && prevElsie==elsieHigh)) ans++;
                    prevBessie=bessieHigh;  prevMildred=mildredHigh; prevElsie=elsieHigh;
                }
            }

        }
        writer.println(ans);
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
