package numguess;
import java.util.Scanner;
public class NumGuess {
    public static void main(String[] args) {
        double rand;
        rand=Math.random()*100;
        Scanner scan =new Scanner(System.in);
        int ran= (int) rand;
        //System.out.println(+a);
        //System.out.println("c value :"+c);
        int guess,count=1;
        System.out.println("Enter your guess: ");
        guess=scan.nextInt();
        //System.out.println("b value: "+b);
        while(guess!=ran)
        {
            count++;
            if(guess>ran){
                System.out.println("\nTry low: \n");
            }
            else if(guess<ran){
                System.out.println("\nTry higher: \n");
            }
            System.out.println("Enter your guess: ");
            guess=scan.nextInt();
        }
        System.out.println("\nYou got it in " +count +" trials\n");
        System.out.println("The computer generated value is :"+ran);
    }
}