package testabstract;
import java.util.Scanner;

abstract class Shape
    {
    protected String colour="RED";

    Shape()
    {
        colour="BLUE";
    }

    Shape(String col)
    {
        colour=col;
    }

    String getColour()
    {   
        return colour;
    }

    void setColour(String col)
    {
        colour=col;
    }
    abstract float getArea();
    abstract float getPerimeter();
}


class Circle extends Shape
{
    protected float radius=1.0f;

    Circle()
    {
        radius =1.0f;
    }

    Circle(float rad)
    {
        radius=rad;
    }

    Circle(float r,String col)
    {
        super(col);
        radius=r;
}

float getRadius()
{
return radius;
}

void setRadius(float rad)
{
radius=rad;
}

float getArea()
{
return (3.14f*radius*radius);
}

float getPerimeter()
{
return (6.28f*radius);
}
}

class Rectangle extends Shape
{
protected float width=1.0f,length=1.0f;

Rectangle()
{
length =1.0f;width=1.0f;
}

Rectangle(float len,float wid)
{
length=len;
width=wid;
}

Rectangle(float len,float wid,String col)
{
super(col);
length=len;
width=wid;

}

float getWidth()
{
return width;
}

float getLength()
{
return length;
}

void setWidth(float r)
{
width=r;
}

void setLength(float r)
{
length=r;
}

float getArea()
{
return (length*width);
}

float getPerimeter()
{
return (2*(length+width));
}
}


class Square extends Rectangle
{
Square()
{
super(1.0f,1.0f);
}

Square(float side)
{
super(side,side);
}

Square(float side,String color)
{
super(side,side,color);
}

float getSide()
{
return getLength();
}

void setSide(float side)
{
setLength(side);
setWidth(side);
}
}

public class TestAbstract
{
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        Shape a[]=new Shape[3];
        int ch,ch1;
        float x,y;
        String c;
        do
        {
            System.out.print("\n Press : ");
            System.out.print("\n 1. Circle");
            System.out.print("\n 2. Rectangle");
            System.out.print("\n 3. Square");
            System.out.print("\n 4. Exit");
            System.out.print("\n Enter your choice : ");
            ch=s.nextInt();
            switch(ch)
            {
                case 1:
                    {
                        System.out.print("\n Circle : ");
                        System.out.print("\n 1 .Default Constructor");
                        System.out.print("\n 2 .Change  1 parameter");
                        System.out.print("\n 3 .Change  2 parameters");
                        System.out.print("\n 4 .Exit");
                        System.out.print("\n Enter your choice : ");
                        ch1=s.nextInt();
                        while(ch1!=4)
                        {
                        switch(ch1){
                                            case 1:                                      
{
a[0]=new Circle();
                                                System.out.print("\n color      : "+a[0].getColour());
                                                System.out.print("\n Area       : "+a[0].getArea());
                                                System.out.print("\n Perimeter  : "+a[0].getPerimeter());
                                                break;
}
                                            case 2:
{
System.out.print("\n Radius : ");x=s.nextFloat();
a[0]=new Circle(x);
                                                System.out.print("\n color      : "+a[0].getColour());
                                                System.out.print("\n Area       : "+a[0].getArea());
                                                System.out.print("\n Perimeter  : "+a[0].getPerimeter());
                                                break;
}
                                            case 3:
{
System.out.print("\n Colour : ");c=s.next();
System.out.print(" Radius : ");x=s.nextFloat();
a[0]=new Circle(x,c);
System.out.print("\n color      : "+a[0].getColour());
                                                System.out.print("\n Area       : "+a[0].getArea());
                                                System.out.print("\n Perimeter  : "+a[0].getPerimeter());
                                                break;
}
                                            case 4:
                                                System.exit(0);
                                            default:System.out.println("Invalid Input!!");
                                        }

System.out.print("\n\n");
                                        System.out.print("\n 1 .Default Constructor");
System.out.print("\n 2 .Change  1 parameter");
System.out.print("\n 3 .Change  2 parameters");
                                        System.out.print("\n 4 .Exit");
System.out.print("\n Enter your choice: ");
                                        ch1=s.nextInt();
                                        }
break;
}
case 2:
{
System.out.print("\n Rectangle : ");
System.out.print("\n 1 .Default Constructor");
System.out.print("\n 2 .Change  2 parameters");
System.out.print("\n 3 .Change  3 parameters");
                                        System.out.print("\n 4 .Exit");
System.out.print("\n Enter your Choice : ");
ch1=s.nextInt();
                                        while(ch1!=4)
                                        {
                                            switch(ch1){
                                            case 1:
{
a[1]=new Rectangle();
                                                System.out.print("\n color     : "+a[1].getColour());
                                                System.out.print("\n Area      : "+a[1].getArea());
                                                System.out.print("\n Perimeter : "+a[1].getPerimeter());
                                                break;
}
                                            case 2:
{
System.out.print("\n Length : ");x=s.nextFloat();
System.out.print(" Width  : ");y=s.nextFloat();
a[1]=new Rectangle(x,y);
                                                System.out.print("\n color     : "+a[1].getColour());
                                                System.out.print("\n Area      : "+a[1].getArea());
                                                System.out.print("\n Perimeter : "+a[1].getPerimeter());
                                                break;
}
                                            case 3:
{
System.out.print("\n Color: ");c=s.next();
System.out.print(" Length : ");x=s.nextFloat();
System.out.print(" Width  : ");y=s.nextFloat();
                                                a[1]=new Rectangle(x,y,c);
                                                System.out.print("\n color     : "+a[1].getColour());
                                                System.out.print("\n Area      : "+a[1].getArea());
                                                System.out.print("\n Perimeter : "+a[1].getPerimeter());


                                                break;
                                        }
                                            case 4:
                                                System.exit(0);
                                            default:System.out.println("Invalid Input!!");
                                       
}
                                       
System.out.print("\n\n");
                                        System.out.print("\n 1 .Default Constructor");
System.out.print("\n 2 .Change  1 parameter");
System.out.print("\n 3 .Change  2 parameters");
                                        System.out.print("\n 4 .Exit");
System.out.print("\n Enter your Choice : ");
ch1=s.nextInt();

                                    }
                                        break;
                                }
case 3:
{
System.out.print("\n Square : ");
System.out.print("\n 1 .Default Constructor");
System.out.print("\n 2 .Change  1 parameter");
System.out.print("\n 3 .Change  2 parameters");
                                        System.out.print("\n 4 .Exit");
System.out.print("\n Enter your Choice : ");
ch1=s.nextInt();
                                        while(ch1!=4)
                                        {
                                            switch(ch1){
                                            case 1:
{
a[2]=new Square();
                                                System.out.print("\n colur      : "+a[2].getColour());
                                                System.out.print("\n Area       : "+a[2].getArea());
                                                System.out.print("\n Perimeter  : "+a[2].getPerimeter());
                                                break;
}
                                            case 2:
{
System.out.print("\n Side : ");
                                                x=s.nextFloat();
                                                a[2]=new Square(x);
                                                System.out.print("\n colur      : "+a[2].getColour());
                                                System.out.print("\n Area       : "+a[2].getArea());
                                                System.out.print("\n Perimeter  : "+a[2].getPerimeter());
                                                break;

}
                                            case 3:
{
System.out.print("\n Colour : ");c=s.next();
System.out.print(" Side   : ");x=s.nextFloat();
a[2]=new Square(x,c);
System.out.print("\n colur      : "+a[2].getColour());
                                                System.out.print("\n Area       : "+a[2].getArea());
                                                System.out.print("\n Perimeter  : "+a[2].getPerimeter());
                                                break;

}
                                            case 4:
                                                System.exit(0);
                                            default:System.out.println("Invalid Input!!");
                                        }

                                        System.out.print("\n 1 .Default Constructor");
System.out.print("\n 2 .Change  1 parameter");
System.out.print("\n 3 .Change  2 parameters");
                                        System.out.print("\n 4 .Exit");
System.out.print("\n Enter your Choice : ");
ch1=s.nextInt();

}
                                        break;
}
}
        }while(ch!=4);
}
}
