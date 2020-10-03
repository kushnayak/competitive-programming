import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Palindrome {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter writer = new PrintWriter(System.out);

        String s = reader.readLine();
        int[] count = new int[26];
        for (int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            count[c-65]++;
        }

        boolean palindrome = false;
        int count1 = 0;

        for (int i=0; i<26; i++) {
            int currCount = count[i];
            if (currCount > 0) {
                if (currCount == 1) count1++;
                if (currCount % 2 == 1 && currCount != 1 || count1 > 1) {
                    palindrome = false;
                    break;
                } else {
                    palindrome = true;
                }
            }
        }
        if (palindrome) {
            StringBuilder res = new StringBuilder();
            int found1 = -1;
            for (int i=0; i<26; i++) {
                int currCount = count[i];
                if (currCount > 0) {
                    if (currCount == 1) {
                        found1 = i;
                        continue;
                    }
                    add(res, currCount/2, (char) (i + 65));
                }
            }
            StringBuilder reverse = new StringBuilder(res.toString());
            reverse.reverse();
            if (found1 != -1) {
                res.append((char) (found1 + 65));
            }
            res.append(reverse);
            writer.println(res.toString());
        } else {
            writer.println("NO SOLUTION");
        }
        writer.close();
    }
    static void add(StringBuilder s, int count, char c) {
        for (int i=0; i<count; i++) s.append(c);
    }
}