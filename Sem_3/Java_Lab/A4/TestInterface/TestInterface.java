package testinterface;
import java.util.*;
import java.lang.*;

class Person
{
    private String name;
    private String address;    
    Person(String name,String address)
    {
        this.name=name;
        this.address=address;
    }
    public void setAddress(String address)
    {
        this.address=address;
    }
    public String getName()
    {
        return name;
    }
    public String getAddress()
    {
        return address;
    }
}

class Employee extends Person{
    private String dept;
    private int basic,empid; 
    float DA,HRA,MED,PF,gross,ded,netpay;
    Employee(String name,String address,int empid,String dept,int basic){
        super(name,address);
        this.basic=basic;
        this.dept=dept;
        this.empid=empid;
    }    
    public int getEmpid(){
        return empid;
    }
    public String getDept(){
        return dept;
    }
    public int getBasic(){
        return basic;
    }    
    public void setDept(String dept){
        this.dept=dept;
    }
    public void setBasic(int basic){
        this.basic=basic;
    }
    public float calSalary(){
      	int bp=getBasic();
	DA=bp*0.6f;
	HRA=bp*0.7f;
	MED=bp*0.07f;
        PF=bp*0.8f;
	gross=bp+HRA+DA;
	ded=MED+PF;	
	netpay=gross-ded;
	return netpay;
    }
}

class Faculty extends Employee
{
    private String designation;
    private String course;
    float DA,HRA,MED,PF,gross,ded,netpay;
    Faculty(String name,String address,int empid,String dept,int basic,String desig, String course)
    {
        super(name,address,empid,dept,basic);
        this.designation=desig;
        this.course=course;
    }
    public void setDesig(String design){
        this.designation=design;
    }
    public String getDesig(){
        return designation;
    }
    public void setCourse(String course){
	this.course=course;
    }
    public String getCourse(){
        return course;
    }
    @Override
    public float calSalary(){
        int bp=getBasic();
	DA=bp*0.9f;
	HRA=bp*0.7f;
	MED=bp*0.7f;
	PF=bp*0.8f;
	gross=bp+HRA+DA;
	ded=MED+PF;	
	netpay=gross-ded;
	return netpay;
    }
    public String toString(){
        return ("\t\tFACULTY"+"\n"+
	"NAME       : "+super.getName()+ "\n"+
	"ADDRESS    : "+super.getAddress()+"\n"+
        "ID         : "+super.getEmpid()+"\n"+
	"DEPT       : "+super.getDept()+"\n"+
	"DESIGNATION: "+getDesig()+"\n"+
	"BASICPAY   : "+super.getBasic()+ "\n"+
	"COURSE     : "+getCourse()+ "\n"+ 			
        "*********************************"+"\n"+
	"Netpay     :"+calSalary()+"\n"+
	"*********************************");	
	}
}

interface Student{
    float[] getMarks();
    float calcGPA();
}

class ResearchAssistant extends Employee implements Student{
    float[] marks = new float[3];
    float mark;
    private String project;
    private String course;
    Scanner scan = new Scanner(System.in);
    ResearchAssistant(String name,String address,int empid,String dept,int basic,String project,String course){
        super(name,address,empid,dept,basic);
        this.project=project;
        this.course=course;
    }
    public String getProject(){
        return project;
    }
    public String getCourse(){
        return course;
    }
    public void setCourse(String course){
        this.course=course;
    }
    @Override
    public float[] getMarks(){
        System.out.println("Enter the marks: ");
	int i;
	for(i=0;i<3;i++)
        {
            System.out.print("Sub "+(i+1)+":");
            marks[i]=scan.nextInt();
            mark+=marks[i];
	}
	return marks ;
    }
    @Override
    public float calcGPA(){
        return mark/30;
    }
    public float calcSalary(){
        int bp=super.getBasic();
      	DA=bp*0.6f;
	HRA=bp*0.1f;
	MED=bp*0.085f;
	PF=bp*0.08f;
	gross=bp+HRA+DA;
	ded=MED+PF;	
	netpay=gross-ded;
	return netpay;
    }
    @Override
    public String toString(){
        return ("\t\tRESEARCHASSISTANT"+"\n"+
	"NAME       : "+super.getName()+ "\n"+
	"ADDRESS    : "+super.getAddress()+"\n" +
        "ID         : "+super.getEmpid()+ "\n"+
	"DEPT       : "+super.getDept()+ "\n"+
	"BASICPAY   : "+super.getBasic()+ "\n"+
	"PROJECT    : "+getProject()+ "\n"+
	"TOTMARKS   : "+mark+ "\n"+
	"COURSE     : "+getCourse()+ "\n"+
	"GPA        : "+calcGPA()+ "\n"+
	"*********************************"+"\n"+
	"Netpay     : "+calSalary()+ "\n"+
	"*********************************");	
    }
}

public class TestInterface {
    public static void main(String[] args) {
        String name,add,dept,desig,course,project;
	int basic = 0,id,ch;
        Faculty faculty = null;
        ResearchAssistant resassist = null;    
        Scanner scan =new Scanner(System.in);
        System.out.println("Press\n1.Enter Faculty Details.\n2.Enter ResearchAssistant Details."
                + "\n3.Modify Faculty Details.\n4.Modify ResearchAssistant Details.\n"
                + "5.Print Faculty Details.\n6.Print ResearchAssistant Details.\n7.Exit.\n"
                + "Enter your Choice:");
        ch=scan.nextInt();
        while(ch!=7){
            switch(ch){
                case 1:{
                    System.out.println("FACULTY...................");
                    System.out.println("Enter Name:");
                    name=scan.next();
                    System.out.println("Enter Address:");
                    add=scan.next();
                    System.out.println("Enter ID:");
                    id=scan.nextInt();
                    System.out.println("Enter Department:");
                    dept=scan.next();
                    System.out.println("Enter Basic Pay:");
                    basic=scan.nextInt();
                    System.out.println("Enter Designation:");
                    desig=scan.next();
                    System.out.println("Enter Course:");
                    course=scan.next();
                    System.out.println("\n");
                    faculty =new Faculty(name,add,id,dept,basic,desig,course);
                    break;
                }
                case 2:{
                    System.out.println("RESEARCHASSISTANT...................");
                    System.out.println("Enter name:");
                    name=scan.next();
                    System.out.println("Enter address:");
                    add=scan.next();
                    System.out.println("Enter id:");
                    id=scan.nextInt();
                    System.out.println("Enter dept:");
                    dept=scan.next();
                    System.out.println("Enter project:");
                    project=scan.next();
                    System.out.println("Enter course:");
                    course=scan.next();  
                    resassist = new ResearchAssistant(name,add,id,dept,basic,project,course);
                    resassist.getMarks();
                    break;
                }
                case 3:{
                    int ch1;
                    System.out.println("Submenu!\nModify\n1.Address.\n2.Department.\n"
                            + "3.BasicPay.\n4.Designation.\n5.Course.\n6.Exit.\n"
                            + "Enter yout choice:");
                    ch1=scan.nextInt();
                    while(ch1!=6){
                        switch(ch1){
                            case 1:
                                System.out.print("Enter Address:");
                                faculty.setAddress(scan.next());
                                break;
                            case 2:
                                System.out.print("Ener Department:");
                                faculty.setDept(scan.next());
                                break;
                            case 3:
                                System.out.print("Enter Basic Pay:");
                                faculty.setBasic(scan.nextInt());
                                break;
                            case 4:
                                System.out.print("Enter Designation:");
                                faculty.setDesig(scan.next());
                                break;
                            case 5:
                                System.out.print("Enter Course:");
                                faculty.setCourse(scan.next());
                                break;
                            case 6:System.exit(0);
                            default:System.out.print("Invalid Input!!!");
                        }
                        System.out.println("");
                        System.out.println("Submenu!\n1.Address.\n2.Department.\n"
                            + "3.BasicPay.\n4.Designation.\n5.Course.\n6.Exit.\n"
                            + "Enter yout choice:");
                        ch1=scan.nextInt();    
                    }
                    break;
                }
                case 4:{
                    int ch1;
                    System.out.println("Submenu!\nModify\n1.Address.\n2.Department.\n"
                            + "3.BasicPay.\n4.Course.\n5.Exit.\n"
                            + "Enter yout choice:");
                    ch1=scan.nextInt();
                    while(ch1!=5){
                        switch(ch1){
                            case 1:
                                System.out.print("Enter Address:");
                                resassist.setAddress(scan.next());
                                break;
                            case 2:
                                System.out.print("Ener Department:");
                                resassist.setDept(scan.next());
                                break;
                            case 3:
                                System.out.print("Enter Basic Pay:");
                                resassist.setBasic(scan.nextInt());
                                break;
                            case 4:
                                System.out.print("Enter Course:");
                                resassist.setCourse(scan.next());
                                break;
                            case 5:System.exit(0);
                            default:System.out.print("Invalid Input!!!");
                        }
                        System.out.println("");
                        System.out.print("Submenu!\nModify\n1.Address.\n2.Department.\n"
                            + "3.BasicPay.\n4.Course.\n5.Exit.\n"
                            + "Enter yout choice:");
                        ch1=scan.nextInt();
                    }
                    break;
                }
                case 5:
                    System.out.println("\n");
                    System.out.println(faculty);
                    break;
                case 6:
                    System.out.println("\n");
                    System.out.println(resassist);
                    break;
                case 7:System.exit(0);
                default:System.out.println("Invalid Input!!!");
            }
            System.out.println("Press\n1.Enter Faculty Details.\n2.Enter ResearchAssistant Details."
                + "\n3.Modify Faculty Details.\n4.Modify ResearchAssistant Details.\n"
                + "5.Print Faculty Details.\n6.Print ResearchAssistant Details.\n7.Exit.\n"
                + "Enter your Choice:");
            ch=scan.nextInt();
        }
    }     
}
