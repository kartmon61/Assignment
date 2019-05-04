package assignment;

public class HugeInteger {
	private String digitNumber1;
	private int digit1[];
	private String digitNumber2;
	private int digit2[];
	private int big;
	private int addition[];
	private int subtraction[];

	// constructor
	public HugeInteger(String digitNumber1, String digitNumber2) {
		// initialize
		this.digitNumber1 = digitNumber1;
		this.digitNumber2 = digitNumber2;
		this.digit1 = new int[41];
		this.digit2 = new int[41];
		this.addition = new int[41];
		this.subtraction = new int[41];
		
		// big number size checking
		if (this.digitNumber1.length() > this.digitNumber2.length()) {
			this.big = digitNumber1.length();
		} else {
			this.big = digitNumber2.length();
		}
		// call parse function
		this.parse(this.digitNumber1, this.digitNumber2);
	}

	// parse function
	public void parse(String digitNumber1, String digitNumber2) {

		// string divide one by one and change to integer and input the integer array
		// digit1
		for (int i = 0; i < digitNumber1.length(); i++) {
			digit1[digitNumber1.length() - 1 - i] = (digitNumber1.charAt(i) - '0');
		}

		// string divide one by one and change to integer and input the integer array
		// digit2
		for (int j = 0; j < digitNumber2.length(); j++) {
			digit2[digitNumber2.length() - 1 - j] = (digitNumber2.charAt(j) - '0');
		}
	}

	// add function
	public void add() {
		int plus = 0;
		// add
		for (int i = 0; i <= big; i++) {
			plus += this.digit1[i] + this.digit2[i];

			if (plus >= 10) {
				this.addition[i] = plus % 10;
				plus = plus / 10;
			} else {
				this.addition[i] = plus;
				plus = 0;
			}
		}

		// print add result
		for (int j = big; j >= 0; j--) {

			// skip if the final location number is 0
			if (j == big && this.addition[j] == 0) {
				continue;
			}
			// print addition result
			System.out.print(this.addition[j]);
		}
		System.out.println();
	}

	// subtraction function
	public void subtraction() {
		int result = 0;
		// subtract
		for (int i = 0; i <= big; i++) {
			result += this.digit1[i] - this.digit2[i];
			// if subtract result is minus, bring 10
			if (result < 0) {
				this.subtraction[i] = result + 10;
				result = -1;
			}
			// if subtract result is not minus, just input result
			else {
				this.subtraction[i] = result;
				result = 0;
			}
			// if total subtract result is minus rebuild the result
			if (i == big && result != 0) {
				int minus1 = 0;
				for (int j = 0; j < big; j++) {
					if (10 + minus1 - this.subtraction[j] == 10) {
						this.subtraction[j] = 0;
						minus1 = 0;
					} else {
						this.subtraction[j] = 10 + minus1 - this.subtraction[j];
						minus1 = -1;
					}
				}
				// it means negative integer
				subtraction[big] = 1;
			}
		}
		// print subtraction
		for (int j = big; j >= 0; j--) {
			// print negative reference by subtraction[big]
			if (j == big && subtraction[j] != 0) {
				System.out.print("-");
				continue;
			}
			// print positive reference by subraction[big]
			else if (j == big && subtraction[j] == 0) {
				continue;
			}
			System.out.print(subtraction[j]);
		}
		System.out.println();
	}

	// function isEqualTo
	public boolean isEqualTo() {
		if ((this.digitNumber1).equals(this.digitNumber2)) {
			return true;
		} else {
			return false;
		}
	}

	// function isNotEqualTo
	public boolean isNotEqualTo() {
		if ((this.digitNumber1).equals(this.digitNumber2)) {
			return false;
		} else {
			return true;
		}
	}

	// function isGreaterThan
	public boolean isGreaterThan() {
		if (this.subtraction[big] == 1 || (this.digitNumber1).equals(this.digitNumber2)) {
			return false;
		} else {
			return true;
		}
	}

	// function isLessThan
	public boolean isLessThan() {
		if (this.subtraction[big] == 1) {
			return true;
		} else {
			return false;
		}
	}

	// function isGreaterThanOrEqualTo
	public boolean isGreaterThanOrEqualTo() {
		if (this.subtraction[big] == 1) {
			return false;
		} else {
			return true;
		}
	}

	// function isLessThanOrEqualTo
	public boolean isLessThanOrEqualTo() {
		if (this.subtraction[big] == 1 || (this.digitNumber1).equals(this.digitNumber2)) {
			return true;
		} else {
			return false;
		}
	}

	// function isZero
	public boolean isZero(String digitNumber) {
		if ((digitNumber).equals("0")) {
			return true;
		} else {
			return false;
		}
	}

	// function print
	public void print() {

		System.out.println("*** addition ***");
		this.add();
		System.out.println("*** subtraction ***");
		this.subtraction();
		System.out.println("*** Equality of first and second ***\n" + this.isEqualTo());
		
		System.out.println("*** Inequality first and second ***\n" + this.isNotEqualTo());
		
		System.out.println("*** First is greater than second ***\n" + this.isGreaterThan());
		
		System.out.println("*** First is less than second ***\n" + this.isLessThan());
		
		System.out.println("*** First is greater Or Equal to second ***\n" + this.isGreaterThanOrEqualTo());
		
		System.out.println("*** First is Less than Or Equal to second ***\n" + this.isLessThanOrEqualTo());
		
		System.out.println("*** First is Zero ***\n" + this.isZero(digitNumber1));
		
		System.out.println("*** Second is Zero ***\n" + this.isZero(digitNumber2));
	}
}
