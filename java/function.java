package com.company;

public class function {

    public static void main (String[] args) {
        int maxi = f(-5);
        for (int i=-5; i<=5; i++) {
            maxi = max(maxi, f(i));
            System.out.println("f("+i+") = " + f(i));
        }
        System.out.println("Maximum value : " + maxi);
    }

    public static int f(int x) {
        return -x*x + 3*x -2;
    }

    public static int max(int a, int b) {
        if (a > b) {
            return a;
        }
        else {
            return b;
        }
    }
}
