import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class TimeServer
 {
   public static void main(String []args) 
    {
       
       DateFormat date = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
       
       System.out.println("current date and time using Date class");
       Date dateobject = new Date();
       System.out.println(date.format(dateobject));

       
       System.out.println("current date and time using Calender class");
       Calendar calobject = Calendar.getInstance();
       System.out.println(date.format(calobject.getTime()));
    }
}
