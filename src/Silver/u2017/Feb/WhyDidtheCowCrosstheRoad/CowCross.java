import java.io.*;
import java.util.*;

public class CowCross {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("helpcross.in"));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int c = Integer.parseInt(tokenizer.nextToken());
        int n =  Integer.parseInt(tokenizer.nextToken());
        ArrayList<Integer> chickens = new ArrayList<>(c);
        ArrayList<Interval> cows = new ArrayList<>(n);
        for (int i = 0; i < c; i++) {
            chickens.add(Integer.parseInt(reader.readLine()));
        }
        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            Interval interval = new Interval(Integer.parseInt(tokenizer.nextToken()),
                    Integer.parseInt(tokenizer.nextToken()));
            cows.add(interval);
        }
        Collections.sort(chickens);
        Collections.sort(cows);
//        System.out.println(cows);
//        System.out.println(chickens);
        int ans = 0;
        int index = 0;
        for (int i = 0; i < n; i++) {
            Interval cow = cows.get(i);
            boolean remove = false;
            for (int j = 0; j < chickens.size(); j++) {
                int cpos = chickens.get(j);
                if (cow.start <= cpos && cpos <= cow.end) {
                    index = j; remove = true;
                    ans++;
                    break;
                }
            }
            if (remove) chickens.remove(index);
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("helpcross.out")));
        writer.print(ans);
        writer.close();


    }
    static class Interval implements Comparable<Interval> {
        int start;
        int end;

        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Interval o) {
            return Integer.compare(this.end, o.end);
        }

        @Override
        public String toString() {
            return "Interval{" +
                    "start=" + start +
                    ", end=" + end +
                    '}';
        }
    }
}
