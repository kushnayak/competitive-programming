import java.io.*;
import java.util.*;

public class BeLast {

    public static void main(String[] args) throws IOException {
        InputReader reader = new InputReader("notlast.in");
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("notlast.out")));
        int n = reader.nextInt();
        HashMap<String, Integer> hmp = new HashMap<>(n);
        hmp.put("Bessie",0);
        hmp.put("Elsie",0);
        hmp.put("Daisy",0);
        hmp.put("Gertie",0);
        hmp.put("Annabelle",0);
        hmp.put("Maggie",0);
        hmp.put("Henrietta",0);
        for (int i=0; i<n; i++) {
            String c = reader.next();
            int a = reader.nextInt();
            hmp.replace(c, hmp.get(c)+a);
        }

        TreeSet<Integer> s = new TreeSet<>(hmp.values());


        int s2 = 0;
        try {
            s2 = s.higher(s.first());
        } catch (NullPointerException e) {
            s2 = s.first();
        }

        String res = "";

        int count = 0;
        for (String key: hmp.keySet()) {
            if (hmp.get(key)==s2) {
                count++;
                res = key;
            }
        }
        if (count==1) writer.println(res);
        else writer.println("Tie");
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
