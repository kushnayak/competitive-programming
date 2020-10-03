import java.io.*;
import java.util.StringTokenizer;

public class BlockRetry {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("blocks.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("blocks.out")));
        int n = reader.nextInt();
        String[][] words = new String[n][2];
        for (int i=0; i<n; i++) for(int j=0; j<2; j++) words[i][j] = reader.next();
        int[] letters = new int[26];


        // 'a' starts from ascii 97
        for (int i=0; i<n; i++) {
            int[] first = new int[26];
            int[] second = new int[26];

            String word = words[i][0];
            for (int k=0; k<word.length(); k++) {
                first[(int) word.charAt(k) - 97]++;
            }
            word = words[i][1];
            for (int k=0; k<word.length(); k++) {
                second[(int) word.charAt(k) - 97]++;
            }
            for (int j=0; j<26; j++) {
                letters[j] += Math.max(first[j], second[j]);
            }

        }
        for (int num: letters) writer.println(num);
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
