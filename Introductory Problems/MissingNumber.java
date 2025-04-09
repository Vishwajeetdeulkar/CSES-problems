import java.util.*;
public class MissingNumber{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();

        long expectedSum = n*(n+1)/2;
        for(int i=0;i<n-1;i++){
            int num = sc.nextInt();
            expectedSum-=num;
        }
        System.out.println(expectedSum);
    }
}