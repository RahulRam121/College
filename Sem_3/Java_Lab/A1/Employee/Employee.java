package employee;
import java.text.*;
import java.util.*;

class EmployeeFunctions {
    private String name,designation;
    private int id,DA,basic,HRA,LIC,PF,Nhw,HW,gross,ded,netsal;
    private Date dob,doj;
   
    int get_id() {
        return id;
    }
   
    EmployeeFunctions(int nid,String nname,int nbasic,String ndob,String ndoj,String ndesignation,int nLIC) {
        SimpleDateFormat dateformat = new SimpleDateFormat("dd/MM/yyyy");
        id=nid;
        name=nname;
        basic=nbasic;
        try {
            dob = dateformat.parse(ndob);
            } catch (ParseException ex) {
        }
        try {
            doj = dateformat.parse(ndoj);
            } catch (ParseException ex) {
        }
        designation=ndesignation;
        LIC=nLIC;
    }
   
    EmployeeFunctions(int nid,String nname,String ndob,String ndoj,String ndesignation,int nLIC,int nNhw,int nHW) {
        SimpleDateFormat dateformat = new SimpleDateFormat("dd/MM/yyyy");
        id=nid;
        Nhw=nNhw;
        HW=nHW;
        name=nname;
        try {
            dob = dateformat.parse(ndob);
            } catch (ParseException ex) {
        }
        try {
            doj = dateformat.parse(ndoj);
            } catch (ParseException ex) {
        }
        designation=ndesignation;
        LIC=nLIC;
    }
   
    void payrollCalculation() {
        switch(designation) {
            case "intern":
                DA=2000;
                HRA=1000;
                PF=500;
                gross=Nhw*HW+DA+HRA;
                ded=LIC+PF;
                netsal=gross-ded;
                break;
               
            case "manager":
                DA=(int) (0.4*basic);
                HRA=(int) (0.1*basic);
                PF=(int) (0.08*basic);
                gross=basic+DA+HRA;
                ded=LIC+PF;
                netsal=gross-ded;
                break;
               
            case "others":
            case "trainee":
            case "analyst":
            case "softwareengineer":
            case "teamlead":
                DA=(int) (0.3*basic);
                HRA=(int) (0.1*basic);
                PF=(int) (0.08*basic);
                gross=basic+DA+HRA;
                ded=LIC+PF;
                netsal=gross-ded;
                break;
           
            default:
                System.out.println("Invalid");
        }
    }
   
    void employeePayroll() {
        if("intern".equals(designation)) {
            System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.println("ID          : "+id +"             "+"NAME : "+name);
            System.out.println("designation : "+designation);
            System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.println("No.of hours worked : Rs:"+Nhw +" Hours");
            System.out.println("     Hourly wage   : Rs:"+HW +"/-");
            System.out.println("     gross pay     : Rs:"+gross +"/-");
            System.out.println("     deductions    : Rs:"+ded +"/-");
            System.out.println("               ----------------------------------");
            System.out.println("                    net salary : Rs:"+netsal +"/-");
        }
        else {
            System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.println("ID          : "+id +"             "+"NAME : "+name);
            System.out.println("designation : "+designation);
            System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.println("     basic pay  : Rs:"+basic +"/-");
            System.out.println("     gross pay  : Rs:"+gross +"/-");
            System.out.println("     deductions : Rs:"+ded +"/-");
            System.out.println("               ------------------------------");
            System.out.println("                net salary : Rs:"+netsal +"/-");
        }
    }
   
    void employeePayslip () {
        SimpleDateFormat dateformat = new SimpleDateFormat("dd/MM/yyyy");
        if("intern".equals(designation)) {
            System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.println(" ID          : "+id +"            "+"NAME : "+name);
            System.out.println(" D.O.B       : "+dateformat.format(dob) +"    "+"D.O.J : "+dateformat.format(doj));
            System.out.println(" designation : "+designation);
            System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.println("     Monthly wage  : Rs:"+(Nhw*HW) +"/-");
            System.out.println("     DA            : Rs:"+DA +"/-");
            System.out.println("     HRA           : Rs:"+HRA +"/-");
            if(LIC==0)
                System.out.println("     LIC           : not opted");
            else
                System.out.println("     LIC           : Rs:"+LIC +"/-");
            System.out.println("     PF            : Rs:"+PF +"/-");
            System.out.println("     gross pay     : Rs:"+gross +"/-");
            System.out.println("     deductions    : Rs:"+ded +"/-");
            System.out.println("               ----------------------------------");
            System.out.println("                    net salary : Rs:"+netsal +"/-");
        }
        else {
            System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.println(" ID          : "+id +"            "+"NAME : "+name);
            System.out.println(" D.O.B       : "+dateformat.format(dob) +"    "+"D.O.J : "+dateformat.format(doj));
            System.out.println(" designation : "+designation);
            System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            System.out.println("     basic pay  : Rs:"+basic +"/-");
            System.out.println("     DA         : Rs:"+DA +"/-");
            System.out.println("     HRA        : Rs:"+HRA +"/-");
            if(LIC==0)
                System.out.println("     LIC        : not opted");
            else
                System.out.println("     LIC        : Rs:"+LIC +"/-");
            System.out.println("     PF         : Rs:"+PF +"/-");
            System.out.println("     gross pay  : Rs:"+gross +"/-");
            System.out.println("     deductions : Rs:"+ded +"/-");
            System.out.println("               -----------------------------");
            System.out.println("                net salary : Rs:"+netsal +"/-");
        }
    }
   
    void employeePromotion() {
        Date date = new Date();
        Scanner scan =new Scanner(System.in);
        SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
        long diffInMilliSec = date.getTime() - doj.getTime();
        long years =  (diffInMilliSec / (1000l * 60 * 60 * 24 * 365));
        if(years > 10) {
            switch(designation) {
                case "intern":
                    designation="others";
                    doj=date;
                    System.out.println("\ncongrats," +name +"!!!\n" +"you are promoted to "+designation+"!!!\n");
                    System.out.println("\nEnter the basic pay: ");
                    basic=scan.nextInt();
                    payrollCalculation();
                    break;
                   
                case "others":
                case "trainee":
                case "analyst":
                case "softwareengineer":
                case "teamlead":    
                    designation="manager";
                    doj=date;
                    System.out.println("\ncongrats," +name +"!!!\n" +"you are promoted to "+designation+"!!!\n");
                    break;
                   
                case "manager":
                    System.out.println("\n"+designation+" cannot be promoted!!!\n");
                    break;
                   
                default:
                    System.out.println("\nInvalid chioce\n");
            }
        }
        else
            System.out.println("\n"+name+"doesn't have much experience for promotion\n");
    }
}

class EmployeeDetails {
    String nname,ndesignation,ndob,ndoj;
    int nid,nbasic,nLIC,nNhw,nHW;
    int choice,flag=0;
    Scanner scan =new Scanner(System.in);
    int input() {
        nLIC=0;
        System.out.print("Enter the Employee id: ");
        nid=scan.nextInt();
        System.out.print("Enter the Employee NAME: ");
        nname=scan.next();
        System.out.print("Enter the DATE of BIRTH:(DD/MM/YY) ");
        ndob=scan.next();
        System.out.print("Enter the DATE of JOINING:(DD/MM/YY) ");
        ndoj=scan.next();
        System.out.print("Enter the designation: ");
        ndesignation=scan.next();
        if(!"intern".equals(ndesignation)) {
            System.out.print("Enter the basic pay: ");
            nbasic=scan.nextInt();
        }
        if("intern".equals(ndesignation)) {
            System.out.print("Enter the NO. of HOUR worked :");
            nNhw=scan.nextInt();
            System.out.print("Enter the hour wage: ");
            nHW=scan.nextInt();
        }
        System.out.print("Does Employee Opt for LIC Premium Account? (1. Yes / 2. No): ");
        choice=scan.nextInt();
        if(choice==1) {
            System.out.print("Enter the LIC value: ");
            nLIC=scan.nextInt();
        }
        if(!"intern".equals(ndesignation))
            flag=1;
        else
            flag=0;
        return flag;
    }
}

class Employee {
    public static void main(String[] args){
        int n,idno,choice,flag;
        EmployeeDetails temp=new EmployeeDetails();
        Scanner scan =new Scanner(System.in);
        System.out.print("Enter the number of employees: ");
        n=scan.nextInt();
        EmployeeFunctions[] emp = new EmployeeFunctions[n];
        System.out.println("\nchoose\n1.Enter the Employee Details\n2.Display Employee Records\n3.Generate payslip for an Emplyee\n4.Promote an Emplpoyee\n5.Exit\n");
        System.out.print("Enter your choice: ");
        choice=scan.nextInt();
        while((choice<5) && (choice>0))
        {
            switch(choice){
                case 1:
                    for(int i=0;i<n;i++) {
                        System.out.println("\nEmployee record: "+(i+1));
                        flag=temp.input();
                        if(flag==1)
                            emp[i]=new EmployeeFunctions(temp.nid,temp.nname,temp.nbasic,temp.ndob,temp.ndoj,temp.ndesignation,temp.nLIC);
                        else
                            emp[i]=new EmployeeFunctions(temp.nid,temp.nname,temp.ndob,temp.ndoj,temp.ndesignation,temp.nLIC,temp.nNhw,temp.nHW);
                        emp[i].payrollCalculation();
                    }
                    break;
               
                case 2:
                    for (int i=0;i<n;i++) {
                        System.out.println("\nEmpolyee record: "+(i+1));
                        emp[i].employeePayroll();
                    }
                    break;
               
                case 3:
                    flag=0;
                    System.out.print("Enter the Employee id: ");
                    idno=scan.nextInt();
                    for(int i=0;i<n;i++) {
                        if(idno==emp[i].get_id()) {
                            flag=1;
                            emp[i].employeePayslip();
                            break;
                        }
                    }
                    if(flag==0)
                        System.out.println("\nEmp.no: "+idno +" is not there\n");
                    break;
               
                case 4:
                    flag=0;
                    System.out.print("Enter the Employee id: ");
                    idno=scan.nextInt();
                    for(int i=0;i<n;i++) {
                        if(idno==emp[i].get_id()) {
                            flag=1;
                            System.out.println("\nEmployee "+emp[i].get_id()+" details: ");
                            emp[i].employeePromotion();
                            break;
                        }
                    }
                    if(flag==0)
                        System.out.println("\nEmp.no: "+idno +" is not there\n");
                    break;
               
                default:
                    System.out.println("\nYour choice is Invalid\n");
                }
            System.out.println("\nchoose\n1.Enter the Employee Details\n2.Display Employee Records\n3.Generate payslip for an Emplyee\n4.Promote an Emplpoyee\n5.Exit\n");
            System.out.print("Enter your choice: ");
            choice=scan.nextInt();
        }
    }
}