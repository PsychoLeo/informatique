package com.company;

import java.util.Scanner;

public class Calculette {

    public static double result;
    public static char operation;

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Entrer le premier nombre : ");
        int a = input.nextInt();
        System.out.print("Entrer le second nombre : ");
        int b = input.nextInt();
        menu();
        calculer(a, b);
        afficher(a, b);
    }

    public static void calculer (int a, int b) {
        switch (operation) {
            case ('+') -> result = a + b;
            case ('-') -> result = a - b;
            case ('*') -> result = a * b;
            case ('/') -> result = (float) a / b;
        }
    }

    public static void afficher (int a, int b) {
        System.out.println(a + " " + operation + " " + b + " = " + result);
    }

    public static void menu () {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the operation to perform (+, -, *, /) : ");
        operation = input.next().charAt(0);
    }
}
