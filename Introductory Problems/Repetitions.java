import java.util.*;
public class Repetitions{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String dna = sc.next();
        int n =dna.length();
        if(n==0){
            System.out.println("0");
        }
        int maximum=1,count=1;
        char curr = dna.charAt(0);
        for(int i=1;i<n;i++){
            if(dna.charAt(i)==curr){
                count++;
                maximum =Math.max(count,maximum);
            } else{
                count=1;
            }
            curr = dna.charAt(i);
        }
        System.out.println(maximum);
    }
}