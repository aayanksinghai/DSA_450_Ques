// Write a program to reverse an array or string
// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

import java.util.*;

public class ReverseArray {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int length = sc.nextInt();
        int temp;
        int arr[] = new int[length];

        for (int i = 0; i < length; i++) {
            arr[i] = sc.nextInt();
        }

        for (int j = 0; j < (length) / 2; j++) {
            temp = arr[j];
            arr[j] = arr[length - j - 1];
            arr[length - j - 1] = temp;
        }

        for (int i = 0; i < length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}