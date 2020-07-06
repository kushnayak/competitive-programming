import java.io.*;
import java.util.*;

/*
ID: kushnay1
LANG: JAVA
TASK: Swapity Swap
*/
public class SwapitySwap {

    public static void main(String[] args) throws IOException {
        String in = "swap.in";
        String out = "swap.out";
        BufferedReader reader = new BufferedReader(new FileReader(in));
        StringTokenizer tokens = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(tokens.nextToken());
        int k = Integer.parseInt(tokens.nextToken());
        tokens = new StringTokenizer(reader.readLine());
        int a1 = Integer.parseInt(tokens.nextToken());
        int a2 = Integer.parseInt(tokens.nextToken());
        tokens = new StringTokenizer(reader.readLine());
        int b1 = Integer.parseInt(tokens.nextToken());
        int b2 = Integer.parseInt(tokens.nextToken());

        ArrayList<Integer> arr = new ArrayList<>(n);
        for (int i = 1; i <= n; i++) {
            arr.add(i);
        }

        ArrayList<Integer> cycle = cycleFinder(arr,k,a1,a2,b1,b2);

        if (cycle.size() == 1 && arr.size() != 1) {
            for (int i = 0; i < k%cycle.get(0); i++) {
                reverse(a1, a2, arr);
                reverse(b1, b2, arr);
            }
        }


        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(out)))) {
            for (int num: arr) {
                writer.println(num);
            }
        }
        catch (IOException e) {
            throw new RuntimeException();
        }




    }

    static void reverse(int index1, int index2, ArrayList<Integer>  arr) {
        index1--;
        index2--;
        List<Integer> subList = arr.subList(index1, index2 + 1);
        Collections.reverse(subList);
        for (int i = index1; i <= index2; i++) {
            arr.set(i,  subList.get(i - index1));
        }

    }

    static boolean linear(ArrayList<Integer> arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (!(arr.get(i) == i + 1)) {
                return false;
            }
        }
        return true;
    }

    static ArrayList<Integer> cycleFinder(ArrayList<Integer> arr,int k,int a1,int a2, int b1, int b2) {
        for (int i = 0; i < k; i++){
            reverse(a1, a2, arr);
            reverse(b1, b2, arr);
            if (linear(arr)) {
                return new ArrayList<Integer>(Collections.singletonList(i + 1));
            }
        }

        return arr;

    }
}

