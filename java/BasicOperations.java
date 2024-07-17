package com.company;
import java.util.*;

public class BasicOperations {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        int a, b;
        System.out.print("First value : ");
        a = input.nextInt();
        System.out.print("Second value : ");
        b = input.nextInt();
        System.out.print("Operand (+, -, *, /) : ");
        char c = input.next().charAt(0);
        switch (c) {
            case '+' :
                System.out.println(a + " + " + b + " = " + (a+b));
                break;
            case '-' :
                System.out.println(a + " - " + b + " = " + (a-b));
                break;
            case '*' :
                System.out.println(a + " * " + b + " = " + (a*b));
                break;
            case '/' :
                if (b == 0) {
                    System.out.println("Nope, ZeroDivisionError");
            }
                else {
                    System.out.println(a + " / " + b + " = " + ((float)a / b));
                break;
            }
        }
    }
}
