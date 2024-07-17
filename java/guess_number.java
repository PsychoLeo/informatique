package com.company;
import java.util.Scanner;

public class guess_number {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        int i = (int)(100*Math.random());
        int x;
        do {
            System.out.print("Enter the secret integer between 0 and 100 : ");
            x = input.nextInt();
            if (x<i) {
                System.out.println("Try higher");
            }
            else if (x > i) {
                System.out.println("Try lower");
            }
        } while (x != i);
        System.out.println("Correct guess !");
    }
}
