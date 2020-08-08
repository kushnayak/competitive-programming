import java.io.*;
import java.util.StringTokenizer;

public class BadMilk {

    static int[] person, milkDrank, timeDrank;
    static int[] personSick, timeSick;
    static int n,m,d,s;
    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("badmilk.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("badmilk.out")));
        n = reader.nextInt();
        m = reader.nextInt();
        d = reader.nextInt();
        s = reader.nextInt();
        person = new int[d];
        milkDrank = new int[d];
        timeDrank = new int[d];
        for (int i=0; i<d; i++) {
            person[i] = reader.nextInt();
            milkDrank[i] = reader.nextInt();
            timeDrank[i] = reader.nextInt();
        }
        personSick = new int[s];
        timeSick = new int[s];
        for (int i=0; i<s; i++) {
            personSick[i] = reader.nextInt();
            timeSick[i] = reader.nextInt();
        }
        int ans = 0;
        for (int i=1; i<=m; i++) {
            if (milkIsBad(i)) {
//                System.out.println("Drinks from " + i + " is " + drankMilkCount(i));
                ans = Math.max(ans, drankMilkCount(i));
            }
        }
//        System.out.println(Arrays.toString(personSick));
//        System.out.println(Arrays.toString(timeSick));

        writer.println(ans);
        writer.close();
    }

    static boolean milkIsBad(int milk) {
        for (int i=0; i<s; i++) {
            boolean isBadPerson = false;
            int sickPerson = personSick[i];
            int sickTime = timeSick[i];
            for (int j=0; j<d; j++) {
                if (person[j] == sickPerson && milkDrank[j] == milk && timeDrank[j] < sickTime) {
                    isBadPerson = true;
                    break;
                }
            }
            if (!isBadPerson) return false;
        }
        return true;
    }

    static int drankMilkCount(int milk) {
        boolean[] drank = new boolean[51];
        int drinks = 0;
        for (int i=0; i<d; i++) {
            if (milkDrank[i] == milk && !drank[person[i]]) {
                drinks++;
                drank[person[i]] = true;
            }
        }
        return drinks;
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
