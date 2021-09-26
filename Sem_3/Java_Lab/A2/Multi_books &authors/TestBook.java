package testbook;
import java.lang.*;
import java.util.*;

class Author
        {
    private String name;
    private String email;
    private char gender;
    Author(String name,String email,char gender)
    {
        setName(name);
        setEmail(email);
        setGender(gender);
    }
   void setName(String name)
   {
       this.name=name;
   } 
   void setEmail(String email)
   {
       this.email=email;
   }
   void setGender(char gender){
       this.gender=gender;
   }
   String getName(){
       return name;
   }
   String getEmail(){
       return email;
   }
   char getGender(){
       return gender;
   }  
}
class Book{
    private Author author[];
    private double price;
    private String name;
    private int qty;
    private int n;
    public Book(String name,Author author[],double price,int qty,int n)
    {
      setAuthor(author);
      setName(name);
      setPrice(price);
      setQuantity(qty);
      setAuthorn(n);
    }
   
    public Book(String name,Author author[],double price,int n)
    {
        setAuthor(author);
        setName(name);
        setPrice(price);
        setQuantity(0);
        setAuthorn(n);
    }
    public void setAuthor(Author author[])
    {
        this.author=author;
    }
    public void setAuthorn(int n)
    {
        this.n=n;
    }
    public void setName(String name)
    {
        this.name=name;
    }
    public void setPrice(double price)
    {
        this.price=price;
    }
    public void setQuantity(int qty)
    {
        this.qty=qty;
    }
    public String getName()
    {
        return name;
    }
    public Author[] getAuthor()
    {
        return author;
    }
    public int getAuthorn()
    {
        return n;
    }
    public double getPrice()
    {
        return price;
    }
    public int getQty()
    {
        return qty;
    }
}
public class TestBook {
    public static void main(String args[]) {
	int n,na;
	String bname,aname,email,sbname;
	char gender;
	double price;
	int qty,ch;
	Scanner scan=new Scanner(System.in);
        Book bk[]=new Book[100];
        Book tempbk[]=new Book[100];
        Author[] temp=new Author[100];
	System.out.println("Enter the number of books:");
	n=scan.nextInt();

	for(int i=0;i<n;i++)
	{
		Author[] author=new Author[100];
                System.out.println("Enter the name of the book:");
		bname=scan.next();
		System.out.println("Enter the number of authors:");
		na=scan.nextInt();
		
		for(int j=0;j<na;j++)
		{
			System.out.println("Author no "+(j+1));
			System.out.println("Enter the name of the Author;");
			aname=scan.next();
			System.out.println("Enter the email id of the Author:");
			email=scan.next();
			System.out.println("Enter the Gender:");
			gender=scan.next().charAt(0);
			author[j]=new Author(aname,email,gender);
		}
                System.out.println("Enter the price:");
                price=scan.nextDouble();
		System.out.println("Enter the Quantity:");
                qty=scan.nextInt();
                if(qty==0)
                {
                    bk[i]=new Book(bname,author,price,na);
                }
                else
                {
                    bk[i]=new Book(bname,author,price,qty,na);
                }
	}
        System.out.println("1.Search\n2.Modify Details\n3.printall\n4.exit");
        ch=scan.nextInt();
        while(ch!=4)
        {
            switch(ch)
            {
                case 1:{
                    int x=0;
                    System.out.println("Enter the name of the book:");
                    sbname=scan.next();
                    for(int k=0;k<n;k++)
                    {
                        if(sbname.equals(bk[k].getName())==true)
                    {
                        temp=bk[k].getAuthor();
                        x=1;
                        for(int l=0;l<(bk[k].getAuthorn());l++)
                        {
                        System.out.println("Author name:"+temp[l].getName());
                        System.out.println("Email:"+temp[l].getEmail());
                        System.out.println("Gender:"+temp[l].getGender());
                    }
                    System.out.println("Price:"+bk[k].getPrice());
                    System.out.println("Quantity:"+bk[k].getQty());
                    }
                    }
                    if(x==0)
                    {
                        System.out.println("Book not found");
                    }
                    break;
                }
                /*case 2:
                {   int x=0;
                    String mail;
                    System.out.println("Enter the name of the author:");
                    sbname=scan.next();
                    for(int k=0;k<n;k++)
                    {
                        temp=bk[k].getAuthor();
                        for(int l=0;l<(bk[k].getAuthorn());l++)
                        {
                        if(sbname.equals(temp[l].getName())==true)
                        {
			x=1;
                        System.out.println("Enter the new email:");
                        mail=scan.next();
                        temp[l].setEmail(mail);
                        }
                    }
                    }
                    if(x==0)
                    {
                        System.out.println("Name not found");
                    }
                    break;
                }*/
                case 2:
                    int ch1;
                    String mail,b2name,a2name;
                    System.out.println("Modify\n1.Email.\n2.Price.\n3.Quantity.\n4.Exit");
                    ch1=scan.nextInt();
                    while(ch1!=4)
                    {
                        int x=0;
                        System.out.println("Enter Book's Name : ");
                        b2name=scan.next();
                        for(int k=0;k<n;k++)
                        {                            
                            if(b2name.equals(bk[k].getName())==true){
                                x=1;
                            switch(ch1){
                                case 1:
                                    int s=0;
                                    System.out.println("Enter the name of the author:");
                                    a2name=scan.next();
                                    temp=bk[k].getAuthor();
                                    for(int l=0;l<(bk[k].getAuthorn());l++)
                                    {
                                        if(a2name.equals(temp[l].getName())==true){
                                            s=1;
                                            System.out.println("Enter the new email:");
                                            mail=scan.next();
                                            temp[l].setEmail(mail);
                                        }
                                    }
                                    if(s==0)
                                        System.out.println("Author not found");
                                    break;
                                case 2:
                                    System.out.println("Enter the new price : ");
                                    bk[k].setPrice(scan.nextDouble());
                                    break;
                                case 3:
                                    System.out.println("Enter the new Quantity : ");
                                    bk[k].setQuantity(scan.nextInt());
                                    break;
                                case 4:return;
                                default:System.out.println("Invald Input!");
                            }
                            }   
                        }
                        if(x==0)
                            System.out.println("Book not found!");
                        System.out.println("Modify\n1.Email.\n2.Price.\n3.Quantity.\n4.Exit");
                        ch1=scan.nextInt();
                    }
                break;
                    
                case 3:
                {
                    for(int k=0;k<n;k++)
                    {
			temp=bk[k].getAuthor();
                        System.out.println("Book No"+(k+1));
                        System.out.println("name of the book:"+bk[k].getName());
                        for(int l=0;l<(bk[k].getAuthorn());l++)
                        {
                        System.out.println("Author name:"+temp[l].getName());
                        System.out.println("Email:"+temp[l].getEmail());
                        System.out.println("Gender:"+temp[l].getGender());
                        }
                        System.out.println("Price:"+bk[k].getPrice());
                        System.out.println("Quantity:"+bk[k].getQty());
                    }
                }
                break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("Invalid Input!");
                
            }
            System.out.println("1.Search\n2.Modify Details\n3.printall\n4.exit");
            ch=scan.nextInt(); 
		

    }
   
}
}
