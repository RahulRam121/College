package patientdatabase;
import java.util.Date;


public class OutPatient extends Patient implements MedicalTests,Medicine
{
    private final String visiting_time;
    Date appoinment_date;
    int not;
    Integer array[] = new Integer[5];
    int[] med ;
    OutPatient(String name,String address,String B_Group,int age,char gender,String mob_no,float height,float weight,String doc_name,int token_no,Date doap,String vtime,int med[],int not,Integer arr[])
    {
        super(name,address,B_Group,age,gender,mob_no,height,weight,doc_name,token_no);
        this.visiting_time=vtime;
        this.appoinment_date=doap;
        this.not =0;
        this.med=med;
    }
    /*OutPatient(String name,String address,String B_Group,int age,char gender,String mob_no,float height,float weight,String doc_name,int token_no,int[] med)
    {
        super(name,address,B_Group,age,gender,mob_no,height,weight,doc_name,token_no);
        this.visiting_time = null;
        this.not =0;
        this.med=med;
    }*/
    OutPatient(String name,String address,String B_Group,int age,char gender,String mob_no,float height,float weight,String doc_name,int token_no,int med[],int not,Integer arr[])
    {
        super(name,address,B_Group,age,gender,mob_no,height,weight,doc_name,token_no);
        this.visiting_time=null;
        this.array = arr;
        this.not = not;
        this.med=med;
    }
    public int[] getMed(){
        return this.med;
    }
    public String getVisitingTime(){
        return this.visiting_time;
    }
    public Date getAppointmentDate(){        
        return this.appoinment_date;
    }
    void setMed(int[] med){
        this.med=med;
    }
    @Override
    public double Tests() {        
        double additional_cost=0;
        for(int i=0;i<not;i++){
            switch(array[i])
            {  
                case 1:
                    additional_cost+=1000;
                    break;
                case 2:
                    additional_cost+=1000;
                    break;
                case 3:
                   additional_cost+=600;
                    break;
                case 4:
                    additional_cost+=800;
                    break;
                case 5:
                    additional_cost+=1000;
                    break;
                default:additional_cost+=0;
            }
        }
        return additional_cost;
    }
    @Override
     public double calMed(){
        medicine=0;
        for(int i=0;i<med.length;i++){
            switch(i+1){
                case 1:
                    medicine+=(med[i]*para);break;
                case 2:
                    medicine+=(med[i]*cough_syrup);break;
                case 3:
                    medicine+=(med[i]*anti);break;
                case 4:
                    medicine+=(med[i]*painkillers);break;
                case 5:
                    medicine+=(med[i]*injection);break;
                case 6:
                    medicine+=(med[i]*trips_bottle);break;
            }
        }
        return medicine;
    }
    
    public void display(){
        System.out.println("Displaying Patient's Details..");
        System.out.println("***********************************************");
        System.out.println("Name           : "+getName());
        System.out.println("Age            : "+getAge());        
        System.out.println("Gender         : "+getGender());
        System.out.println("Mobile Number  : "+getmobNO());
        System.out.println("Address        : "+getAddress());
        System.out.println("Blood Group    : "+getB_Group());
        System.out.println("Token Number   : "+getToken_No());
        System.out.println("Doctor's Name  : "+getDoctor_name());
        System.out.println("Height         : "+getHeight());
        System.out.println("Weight         : "+getWeight());
        if(not==0){
        System.out.println("Test Done      :   -");
        }
        else
        {
            for(int i=0;i<not;i++){
                switch(array[i]){
                    case 1:
                        System.out.println("Test Done      : EEG");break;
                    case 2:
                        System.out.println("Test Done      : ECG");break;
                    case 3:
                        System.out.println("Test Done      : X-Ray");break;
                    case 4:
                        System.out.println("Test Done      : Blood Culture Test");break;
                    case 5:
                        System.out.println("Test Done      : Urine Culture Test");break;
                }
            }
        }
        if(getVisitingTime() != null){
        System.out.println("Appoinment Date:"+getAppointmentDate());    
        System.out.println("Visiting Time  :"+getVisitingTime());
        }
        else{
        System.out.println("Appoinment Date:   -");    
        System.out.println("Visiting Time  :   -");    
        }
        System.out.println("***********************************************");
    }
    
    
    public void bill(){
        bill=calMed()+con_fees+Tests();
        System.out.println("***********************************************");
        System.out.println("Patient Name      :"+getName());
        System.out.println("Doctor Name       :"+getDoctor_name());
        System.out.println("Token Number      :"+getToken_No());
        System.out.println("Medicine Charges  :"+calMed());
        if(not!=0){
            System.out.println("Test Charges      :"+Tests());
        }           
        System.out.println("Consultation Fees :"+con_fees);        
        System.out.println("***********************************************");
        System.out.println("Total Charges     :"+getBill());
        System.out.println("***********************************************");
    }
}

