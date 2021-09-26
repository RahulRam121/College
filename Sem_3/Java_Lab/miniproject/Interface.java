package patientdatabase;
public interface InsuranceClaim
{
    void setPolicy(int p);
    double BillDeduction(int ch);
}

public interface MedicalTests{
    double Tests();
}

public interface Medicine{
    static final float para =10,cough_syrup=100,trips_bottle=250,painkillers=60,injection=150,anti=40;
    public double calMed();    
}
