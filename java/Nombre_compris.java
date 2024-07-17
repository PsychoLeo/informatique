package com.company;

import java.util.Scanner;

public class Nombre_compris {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the left limit : ");
        int left_lim = input.nextInt();
        System.out.print("Enter the right limit : ");
        int right_lim = input.nextInt();
        int value = verifyWithLimits(left_lim, right_lim);
        System.out.println("You entered the value : " + value);
    }
    public static int verifyWithLimits(int a, int b) {
        Scanner input = new Scanner(System.in);
        int value;
        do {
            System.out.print("Enter an integer between " + a + " and " + b + " : ");
            value = input.nextInt();
        } while (value < a || value > b);
        return value;
    }
}
