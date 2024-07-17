package com.company;
import java.util.*;

public class Equation {
    public static void main (String[] args) {
        int a, b, c;
        Scanner input = new Scanner(System.in);
        System.out.print("a : ");
        a = input.nextInt();
        System.out.print("b : ");
        b = input.nextInt();
        System.out.print("c : ");
        c = input.nextInt();
        int delta = b*b - 4*a*c;
        if (delta < 0) {
            System.out.println("There are no real solutions");
        }
        else if (delta == 0) {
            float x = (float)-b/(2*a);
            System.out.println("x = "+ x);
        }
        else {
            float x1 = (float) (-b-Math.sqrt(delta))/(2*a);
            float x2 = (float) (-b+Math.sqrt(delta))/(2*a);
            System.out.println("x = " + x1 + " or x = " + x2);
        }
    }
}
