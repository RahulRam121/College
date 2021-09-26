package patientdatabase;
import java.util.Date;

public class InPatient extends Patient implements InsuranceClaim,MedicalTests,Medicine
{
    private int RoomType,bed_no,room_no,policy;
    Date doa,dod;
    int days;
    private String Attender_name,status,date1,date2;
    double insurance_dedu,test_amount,roomrent;
    int not;
    int[] med;
    Integer array[] = new Integer[5];
   
    InPatient(String name,String address,String B_Group,int age,char gender,String mob_no,float height,float weight,String doc_name,int token_no,int not,Integer array[])
    {
        super(name,address,B_Group,age,gender,mob_no,height,weight,doc_name,token_no);        
        this.Attender_name=null;
        this.not=not;
        this.array=array;
        this.bed_no=0;        
        this.room_no=0;
        this.RoomType='\0';
        this.status=null;
    }
    void Admission(int bed_no,int room_no,Date doa,String Attender_name,int RoomType,String date)
    {
        this.date1=date;
        this.Attender_name=Attender_name;
        this.bed_no=bed_no;
        this.room_no=room_no;
        this.doa=doa;
        this.RoomType=RoomType;
        this.status="Active";
    }
    void Discharge(Date dod,String date,long days)
    {
        this.date2=date;
        this.status = "<DISCHARGED>";
        this.dod=dod;
        this.days=(int)days;
    }
    
    void setMed(int[] med){
        this.med=med;
    }
    public int getRoomType(){
        return this.RoomType;
    }
    public int getBedNo(){
        return this.bed_no;
    }
    public int getRoomNo(){
        return this.room_no;
    }
    public Date getDOA(){
        return this.doa;
    }
    public Date getDOD(){
        return this.dod;
    }
    public String getAttenderName(){
        return this.Attender_name;
    }
    public String getStatus(){
        return this.status;
    }
    public int getDays(){
        return this.days;
    }
    public String getDate1(){
        return this.date1;
    }
    public String getDate2(){
        return this.date2;
    }
    @Override
    public double Tests()
    {
        double additional_cost=0;
        for(int i=0;i<not;i++){
            switch(array[i]){  
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
    public void setPolicy(int n){
        this.policy=n;
    }
    
    public int getPolicy(){
        return this.policy;
    }
   
    @Override
    public double BillDeduction(int ch)
    {  
        double temp=calMed()+calRoomrent()+Tests()+con_fees;
        if(ch==1){
            if(temp>15000){
                System.out.println("The total expense will be paid by the insurance company :)");
                return 0;
            }     
            else{
                System.out.println("Pay 50% of the total expense:");
                return 0.5;
            }
        }
        else if(ch == 2){
            if(temp>15000){
                return 0.75;
            }
            else if(temp>1000)
                return 0.9;
            else
                return 1;
        }
        else 
            return 1;
    }
   
    public void bill(double val)
    {
        double temp=calMed()+calRoomrent()+Tests()+con_fees;
        bill=temp*val;
        System.out.println("***********************************************");
        System.out.println("Patient Name      :"+getName());
        System.out.println("Doctor Name       :"+getDoctor_name());
        System.out.println("Token Number      :"+getToken_No());
        System.out.println("Medicine Charges  :"+getMedicine());
        System.out.println("Consultation Fees :"+con_fees);  
        System.out.println("Room Rent         :"+calRoomrent());
        System.out.println("Test Charges      :"+Tests());
        System.out.println("***********************************************");
        System.out.println("Total Charges     :"+getBill());
        System.out.println("***********************************************");
       
    }
       
    
    double calRoomrent(){
        double cost=0;
        if(RoomType == 1)
            cost+=1500*days;
        else if(RoomType == 2)
            cost+=1000*days;
        else
            cost+=500*days;
        return cost;
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
        System.out.println("Name              :"+getName());
        System.out.println("Age               :"+getAge());        
        System.out.println("Gender            :"+getGender());
        System.out.println("Mobile Number     :"+getmobNO());
        System.out.println("Address           :"+getAddress());
        System.out.println("Blood Group       :"+getB_Group());
        System.out.println("Token Number      :"+getToken_No());
        System.out.println("Doctor's Name     :"+getDoctor_name());
        System.out.println("Height            :"+getHeight());
        System.out.println("Weight            :"+getWeight());
        if(getBedNo()==0){
        System.out.println("Admission Status  : Not Admitted");    
        }
        else{
        System.out.println("Admission Status  : Admitted for "+days+ "days");
        System.out.println("Date of Admission : "+getDate1());
        System.out.println("Date of Discharge :  "+getDate2());
        if(getRoomType()==1){
        System.out.println("Room Type         : First Class");
        } else if(getRoomType() == 2){
        System.out.println("Room Type         : Second Class");
        }else{
        System.out.println("Room Type         : Third Class");
        }        
        System.out.println("Room Number       : "+getRoomNo());
        System.out.println("Bed Number        : "+getBedNo());
        System.out.println("Attender Name     : "+getAttenderName());
        System.out.println("Status            : "+getStatus());
        }
        System.out.println("***********************************************");
    }
}