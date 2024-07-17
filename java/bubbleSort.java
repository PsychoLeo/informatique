package com.company;

import java.util.*;

public class bubbleSort { // bubble sort class --> O(n²)

    public static void main (String[] args) {
        int SIZE = 2000;
        int MAX_VAL = 100;
//        Scanner input = new Scanner(System.in);
//        System.out.print("Enter the number of elements in your array of integers : ");
//        int num_elements = input.nextInt();
//        int[] array = new int[num_elements];
//        for (int i=1; i<=num_elements; i++) { // adding every value to array
//            System.out.print("Enter the integer n°" + i+ " in your array : ");
//            array[i-1] = input.nextInt();
//        }
        int[] array = randomList(SIZE, MAX_VAL);
        System.out.println("Before sorting : " + Arrays.toString(array));
        long start = System.currentTimeMillis();
        int[] sorted_array = sortBubble(array);
        long total = System.currentTimeMillis() - start;
        System.out.println("After sorting : " + Arrays.toString(sorted_array));
        System.out.println("Time to Bubble Sort " + SIZE + " values : " + total + " milliseconds");
    }

    public static int[] sortBubble (int[] array) {
        int index = 0; // current index in string
        int swaps = 0; // counting number of swaps to know when finished
        while (true) {
            if (index>=array.length-1)  {
                if (swaps == 0) {
                    break; // leaving loop --> no more changes to do
                }
                else {
                    index = 0; // end of array but some values still changed
                    swaps = 0;
                }
            }
            else if (array[index] > array[index+1]) {
                // operating values swap
                int tmp = array[index+1];
                array[index+1] = array[index];
                array[index] = tmp;
                index++;
                swaps++;
            }
            else {
                index++;
            }
        }
        return array;
    }

    public static int[] randomList (int size, int max_val) { // generate a random list of integers
        int[] array = new int[size];
        Random rd = new Random();
        for (int i=0; i<size; i++) {
            array[i] = rd.nextInt(max_val+1);
        }
        return array;
    }
}
