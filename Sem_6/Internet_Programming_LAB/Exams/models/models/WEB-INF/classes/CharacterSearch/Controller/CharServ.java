package CharacterSearch.Controller;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.*;

public class CharServ extends HttpServlet {
	public void doPost(HttpServletRequest req, HttpServletResponse res) {
		String search_para = req.getParameter("search_para");
		char search_char = req.getParameter("search_char").charAt(0);

		int count = 0;

		for(int index = 0; index < search_para.length(); index++) {
			if(Character.toLowerCase(search_para.charAt(index)) == Character.toLowerCase(search_char)) {
				count++;
			}
		}

		try {
			res.setContentType("text/html");
			PrintWriter out = res.getWriter();

			FileWriter fw = new FileWriter("D:\\output.txt"); 			    
			fw.write("Search paragraph : " + search_para); 
			fw.write("\nSearch Character : " + search_char); 
			fw.write("\nCount : " + count); 
			fw.close();    
			
			RequestDispatcher rd = req.getRequestDispatcher("/index.html");
			rd.include(req, res);
			out.print("<html><script type=\"text/javascript\">");
			out.println("document.getElementById(\"search_para\").value = '" + search_para.toString() + "';");
			out.println("document.getElementById(\"search_char\").value = '" + search_char + "';");
			out.println("document.getElementById(\"count\").innerHTML = " + count + ";");
			
			out.print("</script></html>");
		}
		catch(Exception e) {
			System.out.println(e);
		}
		
	}
}