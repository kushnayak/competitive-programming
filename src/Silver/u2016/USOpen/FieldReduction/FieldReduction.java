package Silver.u2016.USOpen.FieldReduction;

import java.io.*;
import java.util.*;

public class FieldReduction {

//    static boolean valid(ArrayList<Point> points, Point smallestX, Point largestX, Point smallestY, Point largestY) {
//        int outsidePoints = 0;
//        for (int i = 0; i < points.size(); i++) {
//            int x = points.get(i).x;
//            int y = points.get(i).y;
//            if (smallestX.x > x|| largestX.x < x || smallestY.y > y || largestY.y < y) outsidePoints++;
//        }
//        return outsidePoints <= 3;
//    }
    static long area(ArrayList<Point> removable, Point a, Point b, Point c) {
        if (a.equals(b) || b.equals(c) || a.equals(c)) return Long.MAX_VALUE;
        long smallestX = Long.MAX_VALUE; long largestX = 0;
        long smallestY = Long.MAX_VALUE; long largestY = 0;
        for (int i = 0; i < removable.size(); i++) {
            Point curr = removable.get(i);
            if (curr.equals(a) || curr.equals(b) || curr.equals(c)) continue;
            long x = curr.x; long y = curr.y;
            smallestX = Math.min(smallestX, x);
            largestX = Math.max(largestX, x);
            smallestY = Math.min(smallestY, y);
            largestY = Math.max(largestY, y);
        }
        return (largestX - smallestX) * (largestY - smallestY);
    }


    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("reduce.in"));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        ArrayList<Point> points = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            points.add(new Point(Integer.parseInt(tokenizer.nextToken()),
                    Integer.parseInt(tokenizer.nextToken())));
        }
        ArrayList<Point> removable = new ArrayList<>();
        ArrayList<Point> sortedX = new ArrayList<>(points);
        ArrayList<Point> sortedY = new ArrayList<>(points);
        int len = points.size();
        sortedX.sort(Comparator.comparingInt(o -> o.x));
        sortedY.sort(Comparator.comparingInt(o -> o.y));
        for (int i = 0; i < 4; i++) {
            removable.add(sortedX.get(i));
            removable.add(sortedY.get(i));
            removable.add(sortedX.get(len - 1 - i));
            removable.add(sortedY.get(len - 1 - i));
        }
        long ans = Long.MAX_VALUE;
        len = removable.size();
        for (int i = 0; i < len - 3; i++) {
            Point a = removable.get(i);
            for (int j = i + 1; j < len; j++) {
                Point b = removable.get(j);
                for (int k = i + 2; k < len; k++) {
                    Point c = removable.get(k);
                    ans = Math.min(ans, area(removable,a,b,c));
                }
            }
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("reduce.out")));
        writer.println(ans);
        writer.close();

    }

    static class Point {
        int x,y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
//
//        @Override
//        public String toString() {
//            return "Point{" +
//                    "x=" + x +
//                    ", y=" + y +
//                    '}';
//        }
    }
}
