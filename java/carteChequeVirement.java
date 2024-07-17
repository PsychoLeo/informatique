package com.company;
import java.util.*;

public class carteChequeVirement {
    public static void main (String [] args) {
        Scanner input = new Scanner(System.in);
        // Getting user input | assigning them to values
        System.out.print("Nombre de paiements par CB : ");
        int numCB = input.nextInt();
        System.out.print("Nombre de paiements pas cheques : ");
        int numCheque = input.nextInt();
        System.out.print("Nombre de paiement par virement : ");
        int numVirement = input.nextInt();
        // Adding them together
        int totalPays = numCB + numCheque + numVirement;
        System.out.println("Nombre total de paiements : " + totalPays);
        // Printing percentages
        float partCB = (float) numCB * 100 / totalPays;
        System.out.println("CB : " + partCB + "%");
        float partCheque = (float) numCheque * 100 / totalPays;
        System.out.println("Cheques : " + partCheque + "%");
        float partVirement  = (float) numVirement * 100 / totalPays;
        System.out.println("Virements : " + partVirement + "%");
    }
}

