package com.company;

public class Circle {
    private double radius, x, y;

    public Circle(float radius, float x,float y) {
        this.radius = radius;
        this.x = x;
        this.y = y;
    }

    public double area() {
        return 2*Math.PI*this.radius;
    }

    public boolean inCircle (double x, double y) {
    // returns if a point (x, y) is in the circle
        double distance = Math.sqrt(Math.pow(x-this.x, 2)+Math.pow(y-this.y,2));
        return distance <= this.radius;
    }
}
