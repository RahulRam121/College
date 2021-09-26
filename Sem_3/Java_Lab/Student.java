package student;

import java.util.Scanner;

class Stud{
    private int regno,total,average;
    private String name,dept,grade;
    private int mark[]=new int[3];
    
    int get_id()
    {
        return regno;
    }
    
    String get_dept(){
        return dept;
    }
    
    Stud (int nregno,String nname,String ndept,int nmark1,int nmark2,int nmark3){
        this.regno=nregno;
        this.name=nname;
        this.dept=ndept;
        this.mark[0]=nmark1;
        this.mark[1]=nmark2;
        this.mark[2]=nmark3;
    }
    
    void gradeCalculation(){
        total=mark[0]+mark[1]+mark[2];
        average=total/3;
        if(average>90)
            grade="O";
        else if((average>80) && (average<=90))
            grade="A+";
        else if((average>70) && (average<=80))
            grade="A";
        else if((average>60) && (average<=70))
            grade="B+";
        else if((average>=50) && (average<=60))
            grade="B";
        else
            grade="RA";
    }
    
    void deptDisplay(){
        System.out.println("Student Reg.no     :"+regno);
        System.out.println("Student Name       :"+name);
        System.out.println("Student Department :"+dept);
        System.out.println("Student Grade      :"+grade);
    }
    
    void regDisplay(){
        System.out.println("Student Reg.no     :"+regno);
        System.out.println("Student Name       :"+name);
        System.out.println("Student Department :"+dept);
        System.out.println("Student Grade      :"+grade);
    }
}
public class Student {
    public static void main(String[] args) {
        Scanner scan =new Scanner(System.in);
        int nregno,n,c,id,a,f;
        String nname,ndept,dept;
        int nmark[]=new int[3];
        System.out.println("\nEnter the number of studens: ");
        n=scan.nextInt();
        Stud[] stu =new Stud[n]; 
        for(int i=0;i<n;i++) {
            System.out.println("\nStudent record "+(i+1));
            System.out.println("Enter the Student Name: ");
            nname=scan.next();
            System.out.println("Enter the Student Reg.no: ");
            nregno=scan.nextInt();
            System.out.println("Enter the Stduent Department: ");
            ndept=scan.next();
            for(int j=0;j<3;j++)
            {
                System.out.println("Enter the mark "+(j+1));
                nmark[j]=scan.nextInt();
            }
            stu[i]=new Stud (nregno,nname,ndept,nmark[0],nmark[1],nmark[2]);
            stu[i].gradeCalculation();
        }
        System.out.println("\nchoose\n1.Search using Reg.Number\n2.Search using Department Name\n3.Exit");
        System.out.println("\nEnter your choice: ");
        c=scan.nextInt();
        while((c<3) && (c>0)){
            switch(c){
                case 1:
                    f=0;
                    System.out.println("\nEnter the student Reg.no: ");
                    id=scan.nextInt();
                    for(int i=0;i<n;i++){
                        if(id==stu[i].get_id()){
                            f=1;
                            System.out.println("\nStudent details: ");
                            stu[i].regDisplay();
                            break;
                        }
                    }
                    if(f==0)
                        System.out.println("Reg.no: "+id +"is not there");
                    break;
                case 2:
                    a=0;
                    System.out.println("\nEnter the Department Name: ");
                    dept=scan.next();
                    for(int i=0;i<n;i++){
                        if(dept.equals(stu[i].get_dept())){
                            a++;
                            System.out.println("\nStudent Details "+a);
                            stu[i].deptDisplay();
                        }
                    }
                    break;
            }
            System.out.println("\nchoose\n1.Search using Reg.Number\n2.Search using Department Name\n3.Exit");
            System.out.println("\nEnter your choice: ");
            c=scan.nextInt();
        }
    }
}
