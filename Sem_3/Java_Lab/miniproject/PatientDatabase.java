package patientdatabase;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
public class PatientDatabase {
   
    private static final DateFormat simpleDateFormat = new SimpleDateFormat("dd/MM/yyyy");
        
    public static void main(String[] args){
       
        String name,bgroup,address,mob_no,attender_name,doc_name;
        int room_type,age,inp=0,outp=0,ch1,t,ch3,bed_no,room_no,lins,token_no,ch6,op1,ip1,ch7=1;
        char gender;
        int[] med1;
        Date doa,dod;     
        String date1,date2;
        long days;
        
        Integer ch2[] = new Integer[5];
       
        float height,weight;
                       
        Scanner scan = new Scanner(System.in);
        InPatient  inpatient[] = new InPatient[100];
        OutPatient outpatient[] = new OutPatient[100];
        System.out.println("WELCOME TO PATIENT MANAGEMENT SYSTEM!");
        while(ch7!=5){
            switch(ch7){
                case 1:{
                    ch6 = 1;
                    while(ch6 == 1){
                    op1=0;
                    ip1=0;
                    System.out.print("Enter Name :");
                    name = scan.next();
                    System.out.print("Enter AGE :");
                    age = scan.nextInt();
                    System.out.print("Enter Gender :");
                    gender = scan.next().charAt(0);
                    System.out.print("Enter Blood Group :");
                    bgroup = scan.next();
                    System.out.print("Enter Address :");
                    address = scan.next();
                    System.out.print("Enter Mobile Number :");
                    mob_no = scan.next();
                    System.out.print("Enter Height(cms)  :");
                    height = scan.nextFloat();
                    System.out.print("Enter Weight(kgs)  :");
                    weight = scan.nextFloat();
                    System.out.print("Enter the name of the Doctor :");
                    doc_name = scan.next();
                    System.out.print("Enter your Token Number  :");
                    token_no = scan.nextInt();
                    System.out.println("Have you taken any test?");
                    System.out.print("1.Yes\n2.NO \nEnter  :");        
                    ch1 = scan.nextInt();
                    if(ch1==1){
                        System.out.print("Number of Test done  :");
                        t = scan.nextInt();
                        System.out.println("Select the test you have done!");
                        System.out.println("1.EEG\n"
                            + "2.ECG\n"
                            + "3.X-Ray\n"
                            + "4.Blood Culture Test\n"
                            + "5.Urine Culture Test");
                        for(int i=0;i<t;i++){
                            System.out.print("Test no "+(i+1)+" :");
                            ch2[i] = scan.nextInt();
                        }
                        System.out.println("Has the doctor recommended a admission ?");
                        System.out.print("1.YES/2.NO  :");
                        ch3 = scan.nextInt();
                        if(ch3 == 1){
                            inpatient[inp] = new InPatient(name,address,bgroup,age,gender,mob_no,height,weight,doc_name,token_no,t,ch2);
                            ip1+=1;
                            System.out.print("Enter Attender Name  :");
                            attender_name = scan.next();
                            System.out.print("Enter Bed Number  :");
                            bed_no = scan.nextInt();
                            System.out.print("Enter the room no  :");
                            room_no = scan.nextInt();
                            System.out.print("Enter the date of admission  :");
                            date1 = scan.next();
                            try{
                            doa = getDate(date1);  
                            }catch(ParseException e){
                                System.out.println(e);
                                break;
                            }
                            System.out.println("Room Type ");
                            System.out.print("1.First Class\n2.Second Class\n3.Third Class \nEnter :");
                            room_type = scan.nextInt();
                            System.out.println("Enter the Details of Discharge ");
                            System.out.print("Enter the date of discharge(dd/mm/yyyy)  :");
                            date2 = scan.next();
                            try{
                            dod = getDate(date2);
                            }catch(ParseException e){
                                System.out.println(e);
                                break;
                            }
                            days = daysBetween(doa, dod);
                            System.out.println("days:"+(int)days);
                            System.out.println("Do you have any life insurance claims?\n"
                                + "1.YES/2.NO  :");
                            lins = scan.nextInt();               
                            if(lins == 1){
                                inpatient[inp].Admission(bed_no,room_no,doa,attender_name,room_type,date1);
                                inpatient[inp].Discharge(dod,date2,days);                              
                                med1 =getList();
                                inpatient[inp].setMed(med1);
                                System.out.print("Select one of the policies!\n"
                                    + "1.Cashless Claims\n"
                                    + "2.Reimbursement Claims\nEnter  :");
                                int ch5 = scan.nextInt();
                                inpatient[inp].setPolicy(ch5); 
                                inpatient[inp].bill(inpatient[inp].BillDeduction(ch5));                   
                            }
                            else{
                                inpatient[inp].Admission(bed_no,room_no,doa,attender_name,room_type,date1);
                                inpatient[inp].Discharge(dod,date2,days);
                                inpatient[inp].setMed(getList());
                                inpatient[inp].setPolicy(0);
                                inpatient[inp].bill(1);
                            }
                        }
                    else 
                        {
                         int ch4;
                        Date doap;
                        String vtime;
                        System.out.print("Do you have any furhter Appoinment?\n"
                            + "1.Yes/2.No  :" );
                        ch4 = scan.nextInt();
                        if(ch4 == 1){
                            System.out.print("Enter the date of Appoinment(dd/mm/yyyy)  :");
                            try{
                            doap = getDate(scan.next());
                            }catch(ParseException e){
                                System.out.println(e);
                                break;
                            }
                            System.out.print("Enter the time of the Appoinment in 24 hours format(hh:mm)  :");
                            vtime = scan.next();
                            med1 = getList();
                            outpatient[outp] = new OutPatient(name,address,bgroup,age,gender,mob_no,height,weight,doc_name,token_no,doap,vtime,med1,t,ch2);
                            op1+=1;
                        }
                        else{
                            med1 = getList();                
                            outpatient[outp] = new OutPatient(name,address,bgroup,age,gender,mob_no,height,weight,doc_name,token_no,med1,t,ch2);     
                            op1+=1;
                        }
                        outpatient[outp].bill();
                    }                                
                    }
                    else{
                        int ch4;
                        Date doap;
                        String vtime;
                        System.out.print("Do you have any furhter Appoinment?\n"
                            + "1.Yes/2.No  :" );
                        ch4 = scan.nextInt();
                        if(ch4 == 1){
                            System.out.print("Enter the date of Appoinment(dd/mm/yyyy)  :");
                            try{
                            doap = getDate(scan.next());
                            }catch(ParseException e){
                                System.out.println(e);
                                break;
                            }
                            System.out.print("Enter the time of the Appoinment in 24 hours format(hh:mm)  :");
                            vtime = scan.next();
                            med1 = getList();
                            outpatient[outp] = new OutPatient(name,address,bgroup,age,gender,mob_no,height,weight,doc_name,token_no,doap,vtime,med1,0,ch2);
                            op1+=1;
                        }
                        else{
                            med1 = getList();                
                            outpatient[outp] = new OutPatient(name,address,bgroup,age,gender,mob_no,height,weight,doc_name,token_no,med1,0,ch2);     
                            op1+=1;
                        }
                        outpatient[outp].bill();
                    }
                    if(op1==0)
                        inp+=1;
                    else
                        outp+=1;
                    System.out.print("Continue(1.Yes/2.No)  :");
                    ch6 = scan.nextInt();
                    }
                    break;
                }  
                case 2:{
                    int ch8,ch9,ch10;                    
                    String name1;
                    int token;
                    System.out.print("Select \n1.Inpatient/2.Outpatient  :");
                    ch8 = scan.nextInt();
                    if(ch8==1){
                        System.out.print("1.Search by name\n2.Search by Token Number :");
                        ch9 =scan.nextInt();
                        if(ch9==1){
                            System.out.print("Enter Name  :");
                            name1 =scan.next();
                            int flag=0;
                            for(int j=0;j<inp;j++){
                                if(inpatient[j].getName().equals(name1)){
                                    flag=1;
                                    System.out.println("Found");
                                    System.out.print("1.Print Details\n2.Print Bill\n3.Exit\nEnter  :");
                                    ch10=scan.nextInt();                                    
                                    if(ch10==1){
                                        inpatient[j].display();
                                    }
                                    else if(ch10 == 2){
                                        double val = inpatient[j].BillDeduction(inpatient[j].getPolicy());   
                                        inpatient[j].bill(val); 
                                    }               
                                    else
                                        break;
                                }
                            }
                            if(flag == 0)
                                System.out.println("Name not found!");
                        }
                        else{
                            System.out.print("Enter Token number  :");
                            token =scan.nextInt();
                            int flag=0;
                            for(int j=0;j<inp;j++){
                                if(token==inpatient[j].getToken_No()){                                
                                    flag=1;
                                    System.out.println("Found");
                                    System.out.println("1.Print Details\n2.Print Bill\n3.Exit\nEnter  :");
                                    ch10=scan.nextInt();                                    
                                    if(ch10==1){
                                        inpatient[j].display();
                                    }
                                    else if(ch10 == 2){
                                        double val = inpatient[j].BillDeduction(inpatient[j].getPolicy());   
                                        inpatient[j].bill(val); 
                                    }               
                                    else
                                        break;
                                }
                            }
                            if(flag == 0)
                                System.out.println("Token Number not found!");
                        }
                    }
                    else
                    {
                        System.out.print("1.Search by name\n2.Search by Token Number \nEnter  :");
                        ch9 =scan.nextInt();
                        if(ch9==1){
                            System.out.print("Enter Name :");
                            name1 =scan.next();
                            int flag=0;
                            for(int j=0;j<outp;j++){
                                if(outpatient[j].getName().equals(name1)){
                                    flag=1;
                                    System.out.println("Found");
                                    System.out.print("1.Print Details\n2.Print Bill\n3.exit\nEnter  :");
                                    ch10=scan.nextInt();                                    
                                    if(ch10==1){
                                        outpatient[j].display();
                                    }
                                    else if(ch10 == 2){
                                        outpatient[j].bill();
                                    }               
                                    else
                                        break;
                                }
                            }
                            if(flag == 0)
                                System.out.println("Name not found!");
                        }
                        else{
                            System.out.print("Enter Token number  :");
                            token =scan.nextInt();
                            int flag=0;
                            for(int j=0;j<outp;j++){
                                if(token==outpatient[j].getToken_No()){                                
                                    flag=1;
                                    System.out.println("Found");
                                    System.out.println("1.Print Details\n2.Print Bill\n3.exit\nEnter  :");
                                    ch10=scan.nextInt();                                    
                                    if(ch10==1){
                                        outpatient[j].display();
                                    }
                                    else if(ch10 == 2){
                                        outpatient[j].bill();
                                    }               
                                    else
                                        break;
                                }
                            }
                            if(flag == 0)
                                System.out.println("Token Number not found!");
                        }
                    }
                    break;
                }
                case 3:
                {
                    int ch8,ch9,ch10;
                    System.out.println("Select 1.Inpatient/2.Outpatient  :");
                    ch8 = scan.nextInt();
                    if(ch8==1)
                    {
                        System.out.println("Enter Token number :");
                        int token;
                        token =scan.nextInt();
                        int flag=0;
                       for(int j=0;j<inp;j++){
                            if(token==inpatient[j].getToken_No()){                                
                                    flag=1;
                                    System.out.println("Found");
                                    System.out.println("Modify\n1.Name\n2.Age\n3.Height and weight\n4.Blood Group\n5.Address\n6.Mobile Number");
                                    ch9=scan.nextInt();                                    
                                    switch(ch9)
                                    {
                                        case 1:
                                            System.out.println("Enter Name :");
                                            name = scan.next();
                                            inpatient[j].setName(name);
                                            break;
                                        case 2:
                                            System.out.println("Enter AGE :");
                                            age = scan.nextInt();
                                            inpatient[j].setAge(age);
                                            break;
                                        case 4:
                                            System.out.println("Enter Blood Group :");
                                            bgroup = scan.next();
                                            inpatient[j].setB_Group(bgroup);
                                            break;
                                        case 3:
                                            System.out.println("Enter Height :");
                                            height = scan.nextFloat();
                                            System.out.println("Enter Weight :");
                                            weight = scan.nextFloat();
                                            inpatient[j].setHeight(height);
                                            inpatient[j].setWeight(weight);
                                            break;
                                        case 5:
                                            System.out.println("Enter Address :");
                                            address = scan.next();
                                            inpatient[j].setAddress(address);
                                            break;
                                        case 6:
                                            System.out.println("Enter Mobile Number :");
                                            mob_no = scan.next();
                                            inpatient[j].setMob_no(mob_no);
                                            break;
                                         default:
                                            System.out.println("Invalid Input");
                                    }
                            }
                            if(flag == 0)
                                System.out.println("Token Number not found!");
                }
                    }
                       else
                       {System.out.println("Enter Token number :");
                        int token;
                        token =scan.nextInt();
                        int flag=0;
                       for(int j=0;j<inp;j++){
                            if(token==outpatient[j].getToken_No()){                                
                                    flag=1;
                                    System.out.println("Found");
                                    System.out.println("Modify\n1.Name\n2.Age\n3.Height and weight\n4.Blood Group\n5.Address\n6.Mobile Number");
                                    ch9=scan.nextInt();                                    
                                    switch(ch9)
                                    {
                                        case 1:
                                            System.out.println("Enter Name :");
                                            name = scan.next();
                                            outpatient[j].setName(name);
                                            break;
                                        case 2:
                                            System.out.println("Enter AGE :");
                                            age = scan.nextInt();
                                            outpatient[j].setAge(age);
                                            break;
                                        case 4:
                                            System.out.println("Enter Blood Group :");
                                            bgroup = scan.next();
                                            outpatient[j].setB_Group(bgroup);
                                            break;
                                        case 3:
                                            System.out.println("Enter Height :");
                                            height = scan.nextFloat();
                                            System.out.println("Enter Weight :");
                                            weight = scan.nextFloat();
                                            outpatient[j].setHeight(height);
                                            outpatient[j].setWeight(weight);
                                            break;
                                        case 5:
                                            System.out.println("Enter Address :");
                                            address = scan.next();
                                            outpatient[j].setAddress(address);
                                            break;
                                        case 6:
                                            System.out.println("Enter Mobile Number :");
                                            mob_no = scan.next();
                                            outpatient[j].setMob_no(mob_no);
                                            break;
                                        default:
                                            System.out.println("Invalid Input");
                                    }
                            }
                            if(flag == 0)
                                System.out.println("Token Number not found!");
                }
                       }
                    break;
                }
                case 4:
                {
                    int ch8,ch9,ch10;
                    System.out.println("Select 1.Inpatient/2.Outpatient  :");
                    ch8 = scan.nextInt();
                    if(ch8==1)
                    {
                        System.out.println("Displaying All Inpatient Details");
                        for(int i=0;i<inp;i++)
                        {
                            inpatient[i].display();
                        }
                    }
                    else
                    {   System.out.println("Displaying All Outpatient Details");
                        for(int i=0;i<outp;i++)
                        {
                            outpatient[i].display();
                        }
                    }
                    break;
                }
                case 5:System.exit(0);
                default:System.out.println("Inavlid Input!");
            }
            System.out.println("Press\n1.Enter Details.\n2.Search Records.\n3.Modify.\n4.PrintALL.\n5.Exit :");
            ch7 = scan.nextInt();
        }
        
    }
    private static long daysBetween(Date one, Date two) {
        long difference =  (one.getTime()-two.getTime())/86400000;
        return Math.abs(difference);
    }
    private static Date getDate(String date1) throws ParseException{
        return simpleDateFormat.parse(date1);
    } 
    public static int[] getList(){
        Scanner in = new Scanner(System.in);
        int x;
        int[] val ={0,0,0,0,0,0};
        char choice ='y';
        System.out.println("Enter the Purchase Details!");
        while(choice == 'y'){
            System.out.println("Select a Medicine\n"
                    + "1.Paracetamol\n"
                    + "2.Cough syrup\n"
                    + "3.Anti Biotics\n"
                    + "4.Painkillers\n"
                    + "5.Injection\n"
                    + "6.Trips Bottle\n"
                    + "Enter:");
                x = in.nextInt();
                switch(x){
                    case 1:
                        System.out.println("Enter Quantity  :");
                        val[x-1]=in.nextInt();
                        break;
                    case 2:
                        System.out.println("Enter Quantity  :");
                        val[x-1]=in.nextInt();
                        break;
                    case 3:
                        System.out.println("Enter Quantity  :");
                        val[x-1]=in.nextInt();
                        break;
                    case 4:
                        System.out.println("Enter Quantity  :");
                        val[x-1]=in.nextInt();
                        break;
                    case 5:
                        System.out.println("Enter Quantity  :");
                        val[x-1]=in.nextInt();
                        break;
                    case 6:
                        System.out.println("Enter Quantity  :");
                        val[x-1]=in.nextInt();
                        break;
                    default:
                        System.out.println("Invalid Input!");
                }
                System.out.println("Continue(y/n)  :");
                choice = in.next().charAt(0);
        }    
        return val;
    }
}
 