package com.company;

import java.util.Scanner;

public class Pourcentage {

    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of pays with a credit card : ");
        int credit = input.nextInt();
        System.out.print("Enter the number of pays with 'cheques' : ");
        int cheques = input.nextInt();
        System.out.print("Enter the number of pays with 'virements' : ");
        int virements = input.nextInt();
        int total = credit + cheques + virements;
        System.out.println("Vous avez émis " + total + " ordres de débit");
        float pCredit = getPercentage(credit, total);
        float pCheques = getPercentage(cheques, total);
        float pVirements = getPercentage(virements, total);
        System.out.println(pCredit + "% de crédit");
        System.out.println(pCheques + "% de chèques");
        System.out.println(pVirements + "% de virements");

    }

    public static float getPercentage (int a, int b) {
        return (float) a/b * 100;
    }
}
