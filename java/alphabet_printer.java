package com.company;
//import java.util.*;

public class alphabet_printer {
    public static void main (String[] args) {
        int i;
        String alph = new String("abcdefghijklmnopqrstuvwxyz");
        for (i=0; i<alph.length(); i++) {
            System.out.print(alph.charAt(i));
        }
        System.out.println("\n");
        for (i=alph.length()-1; i>=0; i--) {
            System.out.print(alph.charAt(i));
        }
    }
}
