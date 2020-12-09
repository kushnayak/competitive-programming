package Algorithms.Permuatations;

public class RecursivePermutation {

    static void perm (int start, int[] arr) {
        if (start == arr.length) {
            for (int num: arr) {
                System.out.print(num + " ");
            }
            System.out.println();
            return;

        }
        for (int i = start; i < arr.length; i++) {
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;

            perm(start + 1, arr);

            int temp2 = arr[start];
            arr[start] = arr[i];
            arr[i] = temp2;


        }

    }

    public static void main(String[] args) {
        perm(0,new int[]{1,2,3});
    }
}
