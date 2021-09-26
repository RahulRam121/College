package CookieServlet1;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;

public class FirstServ extends HttpServlet {
public void doPost(HttpServletRequest request, HttpServletResponse response){
try{
response.setContentType("text/html");
PrintWriter out = response.getWriter();
String n=request.getParameter("userName");
out.print("Welcome "+n+ " to the first servlet");
Cookie ck=new Cookie("uname",n);//creating cookie object
response.addCookie(ck);//adding cookie in the response
//creating submit button
out.print("<form action='myservlet2' method='POST'>");
out.print("<input type='submit' value='next servlet'>");
out.print("</form>");
out.close();
}catch(Exception e){System.out.println(e);}
}
}