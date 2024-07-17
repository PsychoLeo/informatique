package com.company;

public class piApprox {
    public static void main(String[] args) {
        Circle c = new Circle(1, 0, 0);
        int numRd = 1000000; // precision
        int insideCircle = 0;
        for (int i=0; i<numRd; i++) {
            double x = Math.random();
            double y = Math.random();
            if (c.inCircle(x, y)) {
                insideCircle++;
            }   
        }
        System.out.println("Pi approximation : " + 4*(double)insideCircle/numRd);
    }
}
