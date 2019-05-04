import java.util.Scanner;
import java.util.Random;

public class palindromes_12170584 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);	
		Random random = new Random();
		
		System.out.println
		("Enter the 5 digit number or -1 to generate it randomly:");
		//print "Enter the 5 digit number or -1 to generate it randomly"
		
		int a = input.nextInt(); //input a
		
		if(a ==-1)	//if input a =-1 , a into random 1~9
		{
			a = random.nextInt(99999)+10000;
		}
		
		while(a>99999 || a<10000)	
			//if a is not 5 digit number repeat the input until 5 digit number
		{
			System.out.println
			("It's not five digit number! Enter the 5 digit number:");
			a = input.nextInt();
			
		}
		
		int sep = a;	//make instant sep 
		int cnt =4;
		int digit[] = new int[5];	 //make array 5 
		
		while(cnt>=0)	//separate 5 digit number and put each array
		{
			digit[cnt]= sep%10;
			sep = sep/10;
			cnt--;
		}
		
		//if 1 and 5 digit is same and 2 and 4 digit is same, print palidrome
		if((digit[0]==digit[4]) && digit[1]==digit[3])
		{
			System.out.printf("The number %d is a palidrome!",a);
		}
		
		//if not, print Not palidrome
		else
		{
			System.out.printf("The number %d is NOT a palidrome!",a);
			
		}
	}

}
