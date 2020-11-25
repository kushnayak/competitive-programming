
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Field {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("reduce.in"));
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        ArrayList<ArrayList<Integer>> coordinates = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            tokenizer = new StringTokenizer(reader.readLine());
            int x = Integer.parseInt(tokenizer.nextToken());
            int y = Integer.parseInt(tokenizer.nextToken());
            ArrayList<Integer> point = new ArrayList<>();
            point.add(x); point.add(y);
            coordinates.add(point);
        }

        ArrayList<Integer> extremes = extremes(coordinates);
        int extremeXMin = extremes.get(0);
        int extremeXMax = extremes.get(1);
        int extremeYMin = extremes.get(2);
        int extremeYMax = extremes.get(3);
        ArrayList<Double> possArea = new ArrayList<>();
        for (ArrayList<Integer> point: coordinates) {
            int x = point.get(0);
            int y = point.get(1);
            if (x == extremeXMin || x == extremeXMax || y == extremeYMin || y == extremeYMax) {
               possArea.add(boxArea(coordinates,point));
            }
        }

        int res = Collections.min(possArea).intValue();

        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("reduce.out")))) {
            writer.println(res);
        } catch (IOException e) {
            System.out.println(e);
        }

    }


    static double boxArea(ArrayList<ArrayList<Integer>> data, ArrayList<Integer> avoidPoint) {
        ArrayList<ArrayList<Integer>> newPoints = new ArrayList<>(data);
        newPoints.remove(avoidPoint);
        ArrayList<Integer> extremes = extremes(newPoints);
        int leftMost = extremes.get(0);
        int rightMost = extremes.get(1);
        int lowest = extremes.get(2);
        int highest = extremes.get(3);
        return Math.abs(highest - lowest) * Math.abs(rightMost - leftMost);
    }

    static ArrayList<Integer> extremes(ArrayList<ArrayList<Integer>> data) {
        int leftMost = data.get(0).get(0);
        int rightMost = data.get(0).get(0);
        int lowest = data.get(0).get(1);
        int highest = data.get(0).get(1);
        ArrayList<Integer> extremes = new ArrayList<>(4);
        for (ArrayList<Integer> point: data) {
            int x = point.get(0);
            int y = point.get(1);
            leftMost = Math.min(x,leftMost);
            rightMost = Math.max(x,rightMost);
            lowest = Math.min(y,lowest);
            highest = Math.max(y,highest);
        }
        extremes.add(leftMost); extremes.add(rightMost);
        extremes.add(lowest); extremes.add(highest);
        return extremes;
    }



}
