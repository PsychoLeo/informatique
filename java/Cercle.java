package com.company;

import java.util.Scanner;

public class Cercle {
    public static int x, y, r;
    // initializing default values

    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the radius of your circle : ");
        r = input.nextInt();
        System.out.print("Enter the x and y coordinates of your circle (separated by a space) : ");
        x = input.nextInt();
        y = input.nextInt();
//        System.out.println(r + " "+ x + " " + y);
    }

    public void display() {
        System.out.print("Radius : "+ r);
        System.out.println("(x, y) = (" + x + ", " + y + ")");
    }

    public double perimeter () {
        return 2*Math.PI*(float)r;
    }

    public double area () {
        return Math.pow(r, 2)*Math.PI;
    }

    public void agrandir (int n) {
        // agrandir le rayon du cercle de n unités
        r += n;
    }

    public void move (int new_x, int new_y) {
        x = new_x;
        y = new_y;
    }
}
