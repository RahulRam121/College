package bank;
import java.util.Scanner;

class NotEnougMoneyInAccountException extends Exception
{		
    private double bal;        
    NotEnougMoneyInAccountException(double balance){
        bal=balance;
    }
    @Override
    public String toString(){
	return "NotEnougMoneyInAccountException"
        + "\nAvailable Balance : "+bal+""
        + "\nReduce Withdrawal Amount";
    }
}

class MinBalRequiredException extends Exception
{
    private double bal;
    MinBalRequiredException(double balance){
        bal=balance;
    }
    @Override
    public String toString(){
	return "MinBalRequiredException "
        + "\nAvailable Balance : "+bal+""
        + "\nMaintain Minimum Balance";
    }
}
class PANRequiredException extends Exception
{
    @Override
    public String toString(){
	return "PANRequiredException";
    }
}
class AccountNotFoundException extends Exception
{
    @Override
    public String toString(){
	return "AccountNotFoundException";
    }
}

class Account{
    private String cname,branch;
    private int PAN,acct_num;
    private double balance;
    Account(String name,int pan,int accno,String branch,double balance){
        cname=name;
	this.PAN=pan;
	this.acct_num=accno;
	this.branch=branch;
	this.balance=balance;
    }	
    public String getName(){
	return cname;
    }	
    public String getBranch(){
	return branch;
    }		
    public int getPan(){
	return PAN;
    }	
    public int getAcct_num(){
	return acct_num;
    }		
    public double getBalance(){
	return balance;
    }        
    double deposit(int acc_no,double amt) throws PANRequiredException
    {
	if(this.acct_num==acc_no){
            if(this.PAN==0 && amt>50000)
                throw new PANRequiredException();
            else{
		balance=balance+amt;
                return balance;
            }            
	}
        return balance;
    }	
    double widthdraw(int accno,double amt) throws  MinBalRequiredException ,NotEnougMoneyInAccountException{
        if(this.acct_num==accno){
            if(5000>balance-amt && balance-amt>0){
                throw new MinBalRequiredException(balance);
            }
            else if(amt>balance){
                throw new NotEnougMoneyInAccountException(balance);
            }
            else{
                balance=balance-amt;
                return balance;
            }
        }
    return balance;
    }
    public void setBalance(double balance){
        this.balance=balance;
    }
    public void setPan(int pan){
        this.PAN=pan;
    }
}

public class Bank
{
	public static int n;
	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		System.out.println("\nEnter the number of account");
		n=scan.nextInt();
		Account[] account=new Account[n];
		
		for(int i=0;i<n;i++)
		{
			System.out.println("\nEnter the Account details");
			String name,branch;
			int pan,accno;
			double balance;
			
			System.out.print("Name :");
			scan.nextLine();
			name=scan.nextLine();
			
			System.out.print("Branch :");
			branch=scan.nextLine();
		
			System.out.print("Account Number :");
			accno=scan.nextInt();
			
			System.out.print("Pan :");
			pan=scan.nextInt();
			
			System.out.print("Balance :");
			balance=scan.nextDouble();
			
			account[i]=new Account(name,pan,accno,branch,balance);
		}
		
		int ch=1;
		while(ch!=5)
		{
			
			System.out.println("\nEnter\n1.Deposit\n2.Widthdraw\n3.Search\n4.Display\n5.Exit");
			ch=scan.nextInt();
			switch(ch)
			{
				case 1:
				{
					int a,flag=0;
					double b=0;
					System.out.print("Enter account number : ");
					a=scan.nextInt();
					
					
					try{
                                            for(int i=0;i<n;i++)
                                            {
						if(account[i].getAcct_num()==a){
                                                        flag=1;
                                                        System.out.println("Balance Amount:"+account[i].getBalance());
                                                        System.out.print("Enter amount : ");
                                                	b=scan.nextDouble();
							account[i].setBalance(account[i].deposit(a,b));
                                                        System.out.println("Balance Updated!\nNew Balance : "+account[i].getBalance());
                                                }                                                
                                            }
                                            if(flag==0)
                                                System.out.println("Account not found!");                                            
                                        }catch (PANRequiredException e){
						System.out.println("\nCaught: " + e);
					}finally{
                                            int j,ch1;
                                            for(j=0;j<n;j++)
                                            {
						if(account[j].getAcct_num() == a && b > 50000)
                                                {
                                                        if(account[j].getPan()==0){
                                                            System.out.println("Do you want to add PAN?(1.yes/2.n0):");
                                                            ch1=scan.nextInt();
                                                            if(ch1==1){
                                                            System.out.print("Enter pan:");
                                                            account[j].setPan(scan.nextInt());
                                                            System.out.println("Pan Updated!");
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        break;
                                }
				
				case 2:
				{
					int a,flag=0;
					double b;
					System.out.print("Enter account number : ");
					a=scan.nextInt();
					
					
					try{
                                            for(int i=0;i<n;i++)
                                            {
						if(account[i].getAcct_num()==a)
                                                {
                                                    flag=1;
                                                    System.out.println("Balance Amount : "+account[i].getBalance());
                                                    System.out.print("Enter amount : ");
                                                    b=scan.nextDouble();
                                                    account[i].setBalance(account[i].widthdraw(a,b));
                                                    System.out.println("Balance Updated!\nNew Balance : "+account[i].getBalance());
                                                }
                                            }
                                            if(flag==0)
                                                System.out.println("Account not found!");
                                                
                                        }catch (NotEnougMoneyInAccountException e)
					{
						System.out.println("\nCaught : " + e);
					}catch (MinBalRequiredException e)
					{
						System.out.println("\nCaught : " + e);
					}
					break;
				}
				
				case 3:
				{
					int a;
					System.out.println("Enter account number : ");
					a=scan.nextInt();
					try{
                                            search(account,a);
					}catch (AccountNotFoundException e)
					{
						System.out.println("\nCaught : " + e);
					}
					break;
				}
				
				case 4:
				{
					for(int i=0;i<n;i++)
					{
						printDetails(account[i]);
					}
					break;
				}
				case 5:
				{
					System.out.println("Process Completed..");
					break;
				}
                                default:System.out.println("Invalid Input!");
			}
		}
	}
	
	public static void search(Account[] account,int num) throws  AccountNotFoundException
	{
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(account[i].getAcct_num()==num)
			{
				printDetails(account[i]);	
				flag=1;
				break;
			}
		}
		if(flag==0)
			throw new AccountNotFoundException();
	}
	
	public static void printDetails(Account account)
	{
            System.out.println("\n********************************************");
            System.out.println("Name of the customer: "+account.getName());
            System.out.println("Account Number      : "+account.getAcct_num());
            System.out.println("Pan Number          : "+account.getPan());
            System.out.println("Branch              : "+account.getBranch());
            System.out.println("Balance Amount      : "+account.getBalance());
            System.out.println("********************************************\n");
	}
}