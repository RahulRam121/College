package eb;
import java.util.Scanner;
public class Eb{
    double no;
    String name;
    String type;
    double pread;
    double cread;
    double nounit;
    double amount;

    public double domestic(double pread,double cread){
        double unit;
        double amt;
        unit=cread-pread;
        if(unit<=100){
         amt=unit*1;
        }
        else if(unit>100 && unit<=200){
            amt=unit*2.50;
        }
        else if(unit>200 && unit<=500){
            amt=unit*4;
        }
        else{
            amt=unit*6;
        }
        return amt;
    }
     
    public double commercial(double pread,double cread){
        double unit;
        double amt;
        unit=cread-pread;
        if(unit<=100){
            amt=unit*2;
        }
        else if(unit>100 && unit<=200){
            amt=unit*4.50;
        }
        else if(unit>200 && unit<=500){
            amt=unit*6;
        }
        else{
            amt=unit*7;
        }
        return amt;
    }

    public void display()
    {
        System.out.println("\n");
        System.out.println("*************************************************");
        System.out.println(" Consumer ID            : "+no);
        System.out.println(" Consumer name          : "+name);
        System.out.println(" Electricity type       : "+type);
        System.out.println("*************************************************");
        System.out.println("\n");
        System.out.println("        Previous month reading   : "+pread);
        System.out.println("        Current month reading    : "+cread);
        System.out.println("                         ------------------------");
        System.out.println("        total unit consumed      : "+nounit);
        System.out.println("                         ------------------------");
        System.out.println("\n");
        System.out.println("          You need to pay : Rs:"+amount +"/- only");
        System.out.println("\n");
        System.out.println("*************************************************");
    }
    public static void main(String[] args){
        Eb eb=new Eb();
        int ch;
        Scanner scan =new Scanner(System.in);
        System.out.print("\nEnter consumer ID : ");
        eb.no=scan.nextDouble();
        System.out.print("\nEnter consumer name : ");
        eb.name=scan.next();
        System.out.print("\n1.domestic \n2.commercial\n");
        System.out.println("\nEnter the type of connection: ");
        eb.type=scan.next();
        System.out.print("\nprevious reading : ");
        eb.pread=scan.nextDouble();
        System.out.print("current reading : ");
        eb.cread=scan.nextDouble();
        eb.nounit=eb.cread-eb.pread;
        switch (eb.type)
        {
            case "domestic":
                eb.amount=eb.domestic(eb.pread,eb.cread);
                break;
            case "commercial":
                eb.amount=eb.commercial(eb.pread,eb.cread);
                break;
            default:
                System.out.println("Invalid choice: ");
        }
        eb.display();
    }
}