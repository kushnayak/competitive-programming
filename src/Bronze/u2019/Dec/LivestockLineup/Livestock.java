//import java.io.BufferedReader;
//import java.io.FileReader;
//import java.io.IOException;
//import java.util.ArrayList;
//import java.util.Arrays;
//import java.util.Comparator;
//import java.util.StringTokenizer;
//
//public class Livestock {
//
//    static ArrayList<ArrayList<String>> validPerm(String[] cows, String[][] adjacent) {
//
//    }
//
//
//    public static void main(String[] args) throws IOException {
//
//        BufferedReader br = new BufferedReader(new FileReader("lineup.in"));
//        StringTokenizer str = new StringTokenizer(br.readLine());
//        int n = Integer.parseInt(str.nextToken());
//        String[] cows = new String[]{"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
//        String[][] adjacent = new String[n][2];
//        for (int i = 0; i < n; i++) {
//            str = new StringTokenizer(br.readLine());
//            adjacent[i][0] = str.nextToken();
//            for (int j = 0; j < 4; j++) str.nextToken();
//            adjacent[i][1] = str.nextToken();
//            Arrays.sort(adjacent[i]);
//        }
////        Arrays.sort(adjacent, Comparator.comparing(a -> a[0]));
//        System.out.println(Arrays.deepToString(adjacent));
//
//
//
//
//
//    }
//}
