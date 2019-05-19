package Assignment_6;

public class NumberCompareException extends Exception {

	public NumberCompareException() {
		super("Second input digit is more bigger than first input");
	}

	public NumberCompareException(String message) {
		super("Message");
	}

}