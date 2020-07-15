import java.io.*;
import java.util.*;

public class BackandForth {

    static int[] possibleAnswers = new int[2000];

    static void friday(int milk, ArrayList<Integer> first, ArrayList<Integer> second) {
        for (int i = 0; i < second.size(); i++) {
            int num = second.get(i);
            possibleAnswers[milk + num] = 1;
        }
    }


    static void thursday(int milk, ArrayList<Integer> first, ArrayList<Integer> second) {
        for (int i = 0; i < first.size(); i++) {
            int num = first.get(i);
            ArrayList<Integer> newFirst = new ArrayList<>(first); newFirst.remove(i);
            ArrayList<Integer> newSecond = new ArrayList<>(second); newSecond.add(num);
            friday(milk - num, newFirst, newSecond);
        }
    }

    static void wendesday(int milk, ArrayList<Integer> first, ArrayList<Integer> second) {
        for (int i = 0; i < second.size(); i++) {
            int num = second.get(i);
            ArrayList<Integer> newFirst = new ArrayList<>(first); newFirst.add(num);
            ArrayList<Integer> newSecond = new ArrayList<>(second); newSecond.remove(i);
            thursday(milk + num, newFirst, newSecond);
        }
    }

    static void tuesday(int milk, ArrayList<Integer> first, ArrayList<Integer> second) {
        for (int i = 0; i < first.size(); i++) {
            int num = first.get(i);
            ArrayList<Integer> newFirst = new ArrayList<>(first); newFirst.remove(i);
            ArrayList<Integer> newSecond = new ArrayList<>(second); newSecond.add(num);
            wendesday(milk - num, newFirst, newSecond);
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("backforth.in"));
        ArrayList<Integer> first = new ArrayList<>();
        ArrayList<Integer> second = new ArrayList<>();
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int j = 0; j < 10; j++) {
            first.add(Integer.parseInt(tokenizer.nextToken()));
        }
        tokenizer = new StringTokenizer(reader.readLine());
        for (int j = 0; j < 10; j++) {
            second.add(Integer.parseInt(tokenizer.nextToken()));
        }

        tuesday(1000,first,second);

        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("backforth.out")));
        int count = 0;
        for (int i = 0; i < 2000; i++) {
            if (possibleAnswers[i] == 1) count++;
        }
        writer.println(count);
        writer.close();

    }
}
