package testinheritance;
import java.util.*;
import java.lang.*;

class Person
{
    private int aadhaar;
    private String name;
    private String address;
    private char gender;
    
    Person(int aadhaar,String name,String address,char gender)
    {
        this.aadhaar=aadhaar;
        this.name=name;
        this.address=address;
        this.gender=gender;
    }
    public void setAddress(String address)
    {
        this.address=address;
    }
    public int getAadhaar()
    {
        return aadhaar;
    }
    public String getName()
    {
        return name;
    }
    public String getAddress()
    {
        return address;
    }
    public char getGender()
    {
        return gender;
    }
}

class Student extends Person
{
    private String program;
    private int year;
    private float totalmark;
    
    Student(int aadhaar,String name,String address,char gender,String program,int year,float totalmark)
    {
        super(aadhaar,name,address,gender);
        this.program=program;
        this.totalmark=totalmark;
        this.year=year;
    }
    public String getProgram()
    {
        return program;
    }
    public int getYear()
    {
        return year;
    }
    public float getTotalmark()
    {
        return totalmark;
    }
    public void setYear(int year)
    {
        this.year=year;
    }
    public void setTotalmark(float totalmark)
    {
        this.totalmark=totalmark;
    }
    public float calGPA()
    {
        return ((this.totalmark/5)/10);
    }
}

class Faculty extends Person
{
    private String designation;
    private String department;
    private float basicpay;
    private float grosssalary;
    private float deductions;
    private float netsalary;
    
    Faculty(int aadhaar,String name,String address,char gender,String designation,String dept,float pay)
    {
        super(aadhaar,name,address,gender);
        this.basicpay=pay;
        this.department=dept;
        this.designation=designation;
    }
    public void setBasic(float basic)
    {
        this.basicpay=basic;
    }
    public void setDesignation(String design)
    {
        this.designation=design;
    }
    public String getDesignation()
    {
        return designation;
    }
    public float getBasic()
    {
        return basicpay;
    }
    public String getDepartment()
    {
        return department;
    }
    public float calSalary()
    {
        this.grosssalary=this.basicpay+(0.6f*this.basicpay+0.1f*this.basicpay);
        this.deductions=(0.085f*this.basicpay+(0.08f*this.basicpay));
        this.netsalary=this.grosssalary-this.deductions;
        return this.netsalary;
    }
}

public class TestInheritance
{
    public static void main(String args[])
    {
        int aadhaar,year,ch,ns=0,nf=0;
        float pay,total;
        char gender;
        String name,address,dept,design,program;
        Student[] student=new Student[50];
        Faculty[] faculty=new Faculty[50];
        Scanner scan=new Scanner(System.in);
        System.out.println("1.Enter Student Details.\n2.Enter Faculty Detals.\n3.Modify Details.\n4.Print all he Student's Details.\n5.Print all the Faculty Details.\n6.Exit.");
        ch=scan.nextInt();
        while(ch!=6)
        {
            switch(ch)
            {
                case 1:{
                System.out.println("Enter the number of Sudents:");
                ns=scan.nextInt();
                for(int i=0;i<ns;i++)
                {
                    System.out.println("Student Number:"+(i+1));
                    System.out.println("Student's name:");
                    name=scan.next();
                    System.out.println("Aadhaar number:");
                    aadhaar=scan.nextInt();
                    System.out.println("Address:");
                    address=scan.next();
                    System.out.println("Gender:");
                    gender=scan.next().charAt(0);
                    System.out.println("Program:");
                    program=scan.next();
                    System.out.println("Year:");
                    year=scan.nextInt();
                    System.out.println("Total Mark:");
                    total=scan.nextFloat();
                    student[i]=new Student(aadhaar,name,address,gender,program,year,total);
                }
                System.out.println("Inserted Successfully!!");
                }
                break;
                case 2:{
                    System.out.println("Enter the number of Faulties:");
                    nf=scan.nextInt();
                    for(int i=0;i<nf;i++)
                    {
                        System.out.println("Faculty Number:"+(i+1));
                        System.out.println("Faculty's name:");
                        name=scan.next();
                        System.out.println("Aadhaar number:");
                        aadhaar=scan.nextInt();
                        System.out.println("Address:");
                        address=scan.next();
                        System.out.println("Gender:");
                        gender=scan.next().charAt(0);
                        System.out.println("Designation:");
                        design=scan.next();
                        System.out.println("Department:");
                        dept=scan.next();
                        System.out.println("Basic Pay:");
                        pay=scan.nextFloat();
                        faculty[i]=new Faculty(aadhaar,name,address,gender,design,dept,pay);
                    }
                    System.out.println("Inserted Successfully!");
                }
                break;
                case 3:
                {
                    int s,s1,s2=0;
                    String sname,address1,yr,tot;
                    System.out.println("Modify,\n1.Student Details.\n2.Faculty Details.");
                    s=scan.nextInt();
                    if(s==1)
                    {
                        System.out.println("Enter the name of the Student:");
                        sname=scan.next();
                        for(int i=0;i<ns;i++)
                        {
                            if(sname.equals(student[i].getName()))
                            {
                                s2=1;
                                System.out.println("Select a field to be modfied:");
                                System.out.println("1.Address.\n2.Year.\n3.Total Marks.\n4.Exit");
                                s1=scan.nextInt();
                                while(s1!=4)
                                {
                                    switch(s1)
                                    {
                                        case 1:{
                                            System.out.println("New Address:");
                                            student[i].setAddress(scan.next());
                                            break;
                                        }
                                        case 2:
                                        {
                                            System.out.println("Enter Year:");
                                            student[i].setYear(scan.nextInt());
                                            break;
                                        }
                                        case 3:
                                        {
                                            System.out.println("TOtal Mark:");
                                            student[i].setTotalmark(scan.nextFloat());
                                            break;
                                        }
                                        case 4:
                                            System.exit(0);
                                        default:
                                            System.out.println("Invalid Input!");
                                    }
                                    System.out.println("1.Address.\n2.Year.\n3.Total Marks.\n4.Exit");
                                    s1=scan.nextInt();
                                }
                            }
                        }
                        if(s2==0)
                            System.out.println("Name not found!");
                    }
                    else
                    {
                        System.out.println("Enter the name of the Faculty:");
                        sname=scan.next();
                        for(int i=0;i<nf;i++)
                        {
                            if(sname.equals(faculty[i].getName()))
                            {
                                s2=1;
                                System.out.println("Select a field to be modfied:");
                                System.out.println("1.Address.\n2.Designation.\n3.Basic Pay.\n4.Exit");
                                s1=scan.nextInt();
                                while(s1!=4)
                                {
                                    switch(s1)
                                    {
                                        case 1:{
                                            System.out.println("New Address:");
                                            faculty[i].setAddress(scan.next());
                                            break;
                                        }
                                        case 2:
                                        {
                                            System.out.println("Enter Designation:");
                                            faculty[i].setDesignation(scan.next());
                                            break;
                                        }
                                        case 3:
                                        {
                                            System.out.println("Basic Pay:");
                                            faculty[i].setBasic(scan.nextFloat());
                                            break;
                                        }
                                        case 4:
                                            System.exit(0);
                                        default:
                                            System.out.println("Invalid Input!");
                                    }
                                    System.out.println("1.Address.\n2.Designation.\n3.Basic Pay.\n4.Exit");
                                    s1=scan.nextInt();
                                }
                            }
                        }
                        if(s2==0)
                            System.out.println("Name not found!");
                    }
                    break;
                }
                case 4:{
                    System.out.println("Printng all the Student's Details!");
                    for(int i=0;i<ns;i++)
                    {
                        System.out.println("Student Number :"+(i+1));
                        System.out.println("Student's name :"+student[i].getName());
                        System.out.println("Aadhaar number :"+student[i].getAadhaar());
                        System.out.println("Address        :"+student[i].getAddress());
                        System.out.println("Gender         :"+student[i].getGender());
                        System.out.println("Program        :"+student[i].getProgram());
                        System.out.println("Year           :"+student[i].getYear());
                        System.out.println("Total Mark     :"+student[i].getTotalmark());
                        System.out.println("GPA            :"+student[i].calGPA());
                    }
                }
                break;
                case 5:{
                    System.out.println("Printing all Faculty Details!");
                    for(int i=0;i<nf;i++)
                    {
                        System.out.println("Faculty Number :"+(i+1));
                        System.out.println("Faculty's name :"+faculty[i].getName());
                        System.out.println("Aadhaar number :"+faculty[i].getAadhaar());
                        System.out.println("Address        :"+faculty[i].getAddress());
                        System.out.println("Gender         :"+faculty[i].getGender());
                        System.out.println("Designation    :"+faculty[i].getDesignation());
                        System.out.println("Department     :"+faculty[i].getDepartment());
                        System.out.println("Basic Pay      :"+faculty[i].getBasic());
                        System.out.println("Net Salary     :"+faculty[i].calSalary());
                    }
                }
                break;
                case 6:{
                    System.exit(0);
                }
                default:System.out.println("Invalid Input!");
            }
            System.out.println("1.Enter Student Details.\n2.Enter Faculty Detals.\n3.Modify Details.\n4.Print all he Student's Details.\n5.Print all the Faculty Details.\n6.Exit.");
            ch=scan.nextInt();
        }
    }
}