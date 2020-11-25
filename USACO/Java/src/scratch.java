import java.io.IOException;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class scratch {

    public static void main(String[] args) throws IOException {
        int[] arr1 = {-1, 0, 3, 3, 3, 10, 12};
        int[] arr2 = {-1, 0, 3, 12};
        System.out.println(linearIn(arr1, arr2));
    }
    public static boolean linearIn(int[] outer, int[] inner) {
        int outerLen = outer.length;
        int innerLen = inner.length;
        int pointer = 0;
        for (int i=0; i<innerLen; i++) {
            int find = inner[i];
            boolean found = false;
            System.out.println(pointer);
            while (pointer < outerLen && outer[pointer] <= find) {
                if (outer[pointer] == find) {
                    found = true;
                    break;
                }
                pointer++;
            }
            if (!found)
                return false;
        }
        return true;
    }
}