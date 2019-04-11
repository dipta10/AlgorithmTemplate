// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
// https://www.youtube.com/watch?v=1RpMc3fv0y4
import java.math.BigInteger;
import java.util.Scanner;

public class test {
    public static int binarySearch (int i, int [] X, int increasingSub[], int length) {
        int low = 1;
        int high = length;
        boolean flag = (X[i] == 2);
        while (low <= high) {
            int mid = (int) Math.ceil((low+high)/2);
            if (flag) System.out.println("low: " + low + " mid: " + mid + " high: " + high);
            if (X[increasingSub[mid]] < X[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    public static void LIS (int [] X) {
        int parent[] = new int [X.length];
        int increasingSub[] = new int [X.length + 1];
        int length = 0;

        for (int i = 0; i < X.length; ++i) {
            // binary search
            int pos = binarySearch(i, X, increasingSub, length);
            System.out.println("i: " + X[i] + " pos: " + pos);
            // update parent/previous elements for lis
            parent[i] = increasingSub[pos-1];
            // replace/append
            increasingSub[pos] = i;

            //update the lenght of the subsequence
            if (pos > length) length = pos;
        }

        int lis[] = new int [length];
        int k = increasingSub[length];
        for (int j = length - 1; j >= 0; --j) {
            lis[j] = X[k];
            k = parent[k];
        }

        // print the solution
        System.out.println("Answer:");
        for (int i : lis) {
            System.out.print(i + " ");
        }
        System.out.println();

    }
    public static void main (String args[]) {
        // int X[] = {3,1,5,0,6,4,9};
        int X[] = {3, 1, 5, 2, 6, 4, 9};
		LIS(X);
    }
}
