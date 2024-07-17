package com.company;
import org.w3c.dom.ls.LSOutput;

import java.util.*;

public class loops {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
//        int x;
//        do {
//            System.out.print("Enter an integer between 0 and 100 : ");
//            x = input.nextInt();
//        } while (x < 0 || x > 100);
//        System.out.println("0 <= "+x+" <= 100");
        int x, tot, min, max, n;
        n = min = max = tot = 0;
        do {
            System.out.print("Enter a number (0 to stop) : ");
            x = input.nextInt();
            n++;
            tot += x;
            if (x < min) {
                min = x;
            }
            else if (x > max) {
                max = x;
            }
        } while (x != 0);
        System.out.println("Valeur minimale : " + min);
        System.out.println("Valeur maximale : " + max);
        System.out.println("Moyenne : " + ((float)tot/n));
    }
}
