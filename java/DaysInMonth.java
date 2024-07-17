package com.company;
import java.util.*;
public class DaysInMonth {
    public static void main (String[] args) {
        byte numDays;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of the month : ");
        byte month = input.nextByte();
        System.out.print("Enter the year : ");
        int year = input.nextInt();
        switch (month) {
            case 1, 3, 5, 7, 8, 10, 12:
                numDays = 31;
                break;
            case 4, 6, 9, 11:
                numDays = 30;
                break;
            case 2:
                if (year % 4 == 0) {
                    numDays = 29;
                } else {
                    numDays = 28;
                }
                break;
            default :
                numDays = 0;
                System.out.println("Invalid month input");
                System.exit(0);
        }
        System.out.println("In " + year + " and month n°" + month + " there were " + numDays + " days.");
    }
}
