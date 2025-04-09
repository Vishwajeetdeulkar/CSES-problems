import java.util.*;
public class WierdAlgorithm{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
         ArrayList<Long> sequence = new ArrayList<>();
        sequence.add(n);
        while (n != 1) {
            if ((n & 1) == 1) {
                // If n is odd
                n = 3 * n + 1;
            } else {
                // If n is even
                n = n >> 1;
            }
            sequence.add(n);
        }

        // Output all values
        for (long val : sequence) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}