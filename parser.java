import java.io.FileReader;
import java.util.Arrays;
import com.opencsv.CSVReader;
 
public class parser
{
   @SuppressWarnings("resource")
   public static void main(String[] args) throws Exception
   {
      //Build reader instance
      //Read data.csv
      //Default seperator is comma
      //Default quote character is double quote
      //Start reading from line number 2 (line numbers start from zero)
      CSVReader reader = new CSVReader(new FileReader("data.csv"), ',' , '"' , 1);
       
      String[] nextLine;
	  String functionName;
	  int device;
	  int subdevice;
	  int obc;
	  String device5bits = new String("");
	  String subdevice8bits = new String("");
	  String obc7bits = new String("");
	  String rs232Command = new String("");
	  String sony20binary = new String("");
	  
      while ((nextLine = reader.readNext()) != null) {
         if (nextLine != null) {
            /*for(int i=0;i<nextLine.length;i++)
			{ 
			System.out.println(nextLine[i]);
			}*/
			functionName=nextLine[0];
			device=Integer.parseInt(nextLine[1]);
			subdevice=Integer.parseInt(nextLine[2]);
			obc=Integer.parseInt(nextLine[3]);
			rs232Command=nextLine[4];
			
			//we need to convert obc to a 7 bit binary, device
			//to a 5 bit binary and subdevice to a 8 bit binary,
			//invert them, concatenate to a 20 bit string and
			//convert that to hex to comply with Sony20 IR format.
			
			device5bits = String.format("%5s", Integer.toBinaryString(device)).replace(' ', '0');
			subdevice8bits = String.format("%8s", Integer.toBinaryString(subdevice)).replace(' ', '0');
			obc7bits = String.format("%7s", Integer.toBinaryString(obc)).replace(' ', '0');
			
			/*System.out.println(device5bits);
			System.out.println(subdevice8bits);
			System.out.println(obc7bits);*/
			
			for(int i=obc7bits.length();i>0;i--) {
				sony20binary+=obc7bits.charAt(i-1);
			}
			
			for(int i=device5bits.length();i>0;i--) {
				sony20binary+=device5bits.charAt(i-1);
			}
			
			for(int i=subdevice8bits.length();i>0;i--) {
				sony20binary+=subdevice8bits.charAt(i-1);
			}
						
			System.out.println("case 0x" + String.format("%05X",Integer.parseInt(sony20binary,2)) + ":      lastCommand=\"" + rs232Command + "\";     mySerial.println(lastCommand);     delay(100);     break ;  // " + functionName);
			System.out.println("");

			//We empty sony20binary for the next iteration
			sony20binary="";
         }
       }
   }
}