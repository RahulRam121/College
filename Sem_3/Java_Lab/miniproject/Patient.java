package patientdatabase;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class Patient{
    static double con_fees = 250;
    private String name,address,B_Group,mob_no,doctor_name;
    private int age,token_no;
    private char gender;
    private float height,weight;
    double bill,medicine=0;
   
    Patient(String name,String address,String B_Group,int age,char gender,String mob_no,float height,float weight,String doc_name,int token_no)
    {
        this.name=name;
        this.B_Group=B_Group;
        this.address=address;
        this.age=age;
        this.mob_no=mob_no;
        this.gender=gender;
        this.height=height;
        this.weight=weight;
        this.doctor_name=doc_name;
        this.token_no=token_no;
    }
    public void setToken_NO(int token_no){
        this.token_no=token_no;
    }
    public void setDoctor_Name(String name){
        this.doctor_name=name;
    }
    public void setName(String name)
    {
        this.name=name;
    }  
    public void setAddress(String address)
    {
        this.address=address;
    }
    public void setB_Group(String B_Group)
    {
        this.B_Group=B_Group;
    }    
    public void setAge(int age)
    {
        this.age=age;
    }  
    public void setGender(char gender)
    {
        this.gender=gender;
    }      
    public void setHeight(float height)
    {
        this.height=height;
    }
    public void setMob_no(String mob_no)
    {
        this.mob_no=mob_no;
    }
    public void setWeight(float weight)
    {
        this.weight=weight;
    }
     public String getName(){
        return name;
    }  
    public String getAddress(){
        return  address;
    }
    public String getB_Group()
    {
        return B_Group;
    }    
    public int getAge()
    {
        return age;
    }  
    public char getGender()
    {
         return gender;
    }      
    public float getHeight()
    {
        return height;
    }
    public float getWeight()
    {
        return weight;
    }      
    public String getmobNO(){
        return mob_no;
    }
    public String getDoctor_name(){
        return doctor_name;
    }
    public int getToken_No(){
        return token_no;
    }
    public double getMedicine(){
        return medicine;
    }
    public double getBill(){
        return bill;
    }
}