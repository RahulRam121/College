package testbooks;
import java.lang.String;
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
    private Author author;
    private double price;
    private String name;
    private int qty;
    public Book(String name,Author author,double price,int qty)
    {
      setAuthor(author);
      setName(name);
      setPrice(price);
      setQuantity(qty);
    }
   
    public Book(String name,Author author,double price)
    {
        setAuthor(author);
        setName(name);
        setPrice(price);
        setQuantity(0);
    }
    public void setAuthor(Author author)
    {
        this.author=author;
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
    public Author getAuthor()
    {
        return author;
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
public class TestBooks {
    public static void main(String args[]) {
	int n,ch;
	String bname,aname,email,sbname;
	char gender;
	double price;
	int qty;
	Scanner scan=new Scanner(System.in);
        Book[] bk=new Book[100];
        Author author=new Author();
        Author temp=author;
	System.out.println("Enter the number of books:");
	n=scan.nextInt();

	for(int i=0;i<n;i++)
	{
		System.out.println("Enter the name of the book:");
		bname=scan.next();
		System.out.println("Enter the name of the Author;");
		aname=scan.next();
		System.out.println("Enter the email id of the Author:");
		email=scan.next();
		System.out.println("Enter the Gender:");
		gender=scan.next().charAt(0);
		author=new Author(aname,email,gender);
		System.out.println("Enter the price:");
                price=scan.nextDouble();
		System.out.println("Enter the Quantity:");
                qty=scan.nextInt();
                if(qty==0)
                {
                    bk[i]=new Book(bname,author,price);
                }
                else
                {
                    bk[i]=new Book(bname,author,price,qty);
                }
	}
        System.out.println("1.Search\n2.change email\n3.printall\n4.exit");
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
                        temp=bk[k].getAuthor();
                        x=1;
                        System.out.println("Author name:"+temp.getName());
                        System.out.println("Email:"+temp.getEmail());
                        System.out.println("Gender:"+temp.getGender());
                  	System.out.println("Price:"+bk[k].getPrice());
                        System.out.println("Quantity:"+bk[k].getQty());
                    }
                    if(x==0)
                    {
                        System.out.println("Book not found");
                    }
                    break;
                }
                case 2:
                {   int x=0;
                    String mail;
                    System.out.println("Enter the name of the book:");
                    sbname=scan.next();
                    for(int k=0;k<n;k++)
                    {
			temp=bk[k].getAuthor();
			x=1;
                        System.out.println("Enter the new email:");
                        mail=scan.next();
                        temp.setEmail(mail);
                    }
                    if(x==0)
                    {
                        System.out.println("Name not found");
                    }
                    break;
                }
                case 3:
                {
                    for(int k=0;k<n;k++)
                    {
			temp=bk[k].getAuthor();
                        System.out.println("Book No"+(k+1));
                        System.out.println("name of the book:"+bk[k].getName());
                        System.out.println("Author name:"+temp[l].getName());
                        System.out.println("Email:"+temp[l].getEmail());
                        System.out.println("Gender:"+temp[l].getGender());
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
            System.out.println("1.Search\n2.change email\n3.printall\n4.exit");
            ch=scan.nextInt();
            
        }
        
		

    }
   
}



