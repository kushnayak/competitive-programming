import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Block {

    static boolean present(char c,char[] arr) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == c) {
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("blocks.in"));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        HashMap<Character,Integer> alphabet = new HashMap<Character, Integer>();
        for (char i = 'a'; i <= 'z'; i++) {
            alphabet.put(i,0);
        }
        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            String front = tokenizer.nextToken(); String back = tokenizer.nextToken();
            HashMap<Character,Integer> firstCount = new HashMap<>();
            HashMap<Character,Integer> secondCount = new HashMap<>();
            for (char j = 'a'; j <= 'z'; j++) {
                firstCount.put(j,0);
                secondCount.put(j,0);
            }
            for (int j = 0; j < front.length(); j++) {
                char currChar = front.charAt(j);
                firstCount.replace(currChar,firstCount.get(currChar) + 1);
            }
            for (int j = 0; j < back.length(); j++) {
                char currChar = back.charAt(j);
                secondCount.replace(currChar,secondCount.get(currChar) + 1);
            }
            for (char j = 'a'; j <= 'z'; j++) {
                alphabet.replace(j,alphabet.get(j) + Math.max(firstCount.get(j),secondCount.get(j)));
            }

        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("blocks.out")));
        for (int i: alphabet.values()) {
            writer.println(i);
        }
        writer.close();

    }
}
