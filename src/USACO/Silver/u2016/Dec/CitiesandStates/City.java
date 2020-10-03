
import java.io.*;
import java.util.*;

public class City {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("citystate.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("citystate.out")));
        int n =reader.nextInt();
        HashMap<String,Integer> map = new HashMap<>(n);
        int ans = 0;
        for (int i=0;i<n;i++) {
            String city = reader.next();
            String state = reader.next();
            String uniqueCode = (city.substring(0,2) + state).toLowerCase();
            if (!city.substring(0,2).equals(state)) {
                map.putIfAbsent(uniqueCode, 0);
                map.replace(uniqueCode, map.get(uniqueCode) + 1);
            }        }
        for (String key: map.keySet()) {
            String reversed = key.substring(2) + key.substring(0,2);
            if (map.containsKey(reversed)) {
                ans += map.get(key) * map.get(reversed);
            }
        }
        writer.println(ans/2);

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
