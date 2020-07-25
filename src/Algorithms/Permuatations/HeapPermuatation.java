package Algorithms.Permuatations;

class HeapPermuatation {

    static void printArr(int[] arr) {
        for (int num: arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    static void heapPerm(int[] arr, int size) {
        if (size == 1) {
            printArr(arr);
        }
        for (int i = 0; i < size; i++) {
            heapPerm(arr,size - 1);
            if (size % 2 == 0) {
                int temp = arr[i];
                arr[i] = arr[size - 1];
                arr[size - 1] = temp;
            } else {
                int temp = arr[0];
                arr[0] = arr[size - 1];
                arr[size - 1] = temp;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,4};
        heapPerm(arr,arr.length);
    }
}