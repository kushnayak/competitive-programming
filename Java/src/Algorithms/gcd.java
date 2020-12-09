package Algorithms;

import java.io.IOException;

public class gcd {

    static int gcd(int a , int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        System.out.println(gcd(0, 10));
    }


}
