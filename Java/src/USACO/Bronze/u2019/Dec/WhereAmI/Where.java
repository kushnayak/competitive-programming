import java.io.*;
import java.util.StringTokenizer;

public class Where {


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("whereami.in"));
        StringTokenizer tokenizer = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        tokenizer = new StringTokenizer(br.readLine());
        String s = tokenizer.nextToken();
        int res = 0;
        boolean found = true;
        for (int length = 1; length <= s.length(); length++) {
            String sub = null;
            for (int start = 0; start <= s.length() - length; start++) {
                sub = s.substring(start, start + length);
                if (s.indexOf(sub) != s.lastIndexOf(sub)) {
                    found = false;
                    break;
                }
                found = true;
            }

            if (found) {
                res = sub.length();
                break;
            }
        }

        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("whereami.out")));
        writer.println(res);
        writer.close();



    }
}
