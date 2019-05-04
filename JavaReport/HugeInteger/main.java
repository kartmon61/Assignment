package assignment;

import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		// input first number
		System.out.println("Enter the first number:");
		String digit1 = input.next();
		// input second number
		System.out.println("Enter the second number:");
		String digit2 = input.next();

		// if digit 1 or 2 length is more than 40, input again
		while (digit1.length() > 40 || digit2.length() > 40) {
			System.out.println("One or two numbers have more than 40 digits!");
			System.out.println("Enter the first number again:");
			digit1 = input.next();
			System.out.println("Enter the second number again:");
			digit2 = input.next();
		}
		// make object cal
		HugeInteger cal = new HugeInteger(digit1, digit2);
		// show all result
		cal.print();

	}

}
