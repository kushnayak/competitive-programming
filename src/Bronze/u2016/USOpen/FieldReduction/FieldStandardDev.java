import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class FieldStandardDev {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("reduce.in"));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int x = Integer.parseInt(tokenizer.nextToken());
            int y = Integer.parseInt(tokenizer.nextToken());
            Point currPoint = new Point(x,y);
            Data currData = new Data(Math.hypot(x,y),currPoint);
            dataList.add(currData);
        }
        for (Data data: dataList) {
            System.out.println(data);
        }

        double mean = mean(dataList);
        double standardDev = standardDev(dataList);
        double startRange = mean - standardDev; double endRange = mean + standardDev;
        ArrayList<Double> possArea = new ArrayList<>();
        System.out.println("start " + startRange + " end: " + endRange);
        for (Data data: dataList) {
            double dist = data.distance;
            if (dist < startRange || dist > endRange) {
                possArea.add(boxArea(dataList,data.p));
            }
        }
        System.out.println(possArea);

    }
    static ArrayList<Data> dataList = new ArrayList<>();

    static double mean (ArrayList<Data> data) {
        double mean = 0;
        for (Data point: data) {
            mean += point.distance;
        }
        mean/=data.size();
        return mean;
    }

    static double standardDev(ArrayList<Data> data) {
        double mean = mean(data);
        double standardDev = 0;
        for (Data point: data) {
            standardDev += Math.pow((mean - point.distance),2);
        }
        standardDev /= data.size();

        return Math.sqrt(standardDev);
    }

    static double boxArea(ArrayList<Data> data, Point avoidPoint) {
        double leftMost = Double.POSITIVE_INFINITY;
        double righMost = 0;
        double lowest = Double.POSITIVE_INFINITY;
        double highest = 0;
        for (Data point: data) {
            if (!point.p.equals(avoidPoint)) {
                int x = point.p.x;
                int y = point.p.y;
                leftMost = Math.min(x,leftMost);
                righMost = Math.max(x,righMost);
                lowest = Math.min(y,lowest);
                highest = Math.max(y,highest);
            }
        }
        return (highest - lowest) * (righMost -leftMost);

    }

    static class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Point{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }
    static class Data {
        double distance;
        Point p;

        public Data(double distance, Point p) {
            this.distance = distance;
            this.p = p;
        }


        @Override
        public String toString() {
            return "Data{" +
                    "distance=" + distance +
                    ", p=" + p +
                    '}';
        }
    }





}


