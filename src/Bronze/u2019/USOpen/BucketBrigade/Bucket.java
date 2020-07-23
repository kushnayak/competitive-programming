import java.io.*;

public class Bucket {

    static String[] split(String line) {
        String[] res = new String[10];
        for (int i = 0; i < 10; i++)  {
            res[i] = line.substring(i,i+1);
        }
        return res;
    }

    static int minimum(Point lake, Point barn, Point rock) {
        if (barn.y == lake.y) {
            if (Math.min(lake.x,barn.x) < rock.x && rock.x < Math.max(lake.x,barn.x) && rock.y == barn.y) {
                return Math.abs(lake.x - barn.x) + 1;
            }
            return Math.abs(lake.x - barn.x) - 1;
        }
        else if (barn.x == lake.x) {
            if (Math.min(lake.y,barn.y) < rock.y && rock.y < Math.max(lake.y,barn.y) && rock.x == barn.x) {
                return Math.abs(lake.y - barn.y) + 1;
            }
            return Math.abs(lake.y - barn.y) - 1;
        }
        return Math.abs(lake.x - barn.x) + Math.abs(lake.y-barn.y) - 1;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader("buckets.in"));
        Point lake = null; Point rock = null; Point barn = null;
        for (int i =  1; i <= 10; i++) {
            String[] line = split(reader.readLine());
            for (int j = 0; j < 10; j++) {
                if (line[j].equals("B")) barn = new Point(j + 1,i + 1);
                if (line[j].equals("L")) lake = new Point(j + 1,i + 1);
                if (line[j].equals("R")) rock = new Point(j + 1,i + 1);
            }
        }
        PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("buckets.out")));
        writer.println(minimum(lake,barn,rock));
        writer.close();
    }
}
class Point {
    int x; int y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

//    @Override
//    public String toString() {
//        return "Point{" +
//                "x=" + x +
//                ", y=" + y +
//                '}';
//    }
}
