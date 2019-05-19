package Assignment_6;

public class NumberUnderException extends Exception {

	public NumberUnderException() {
		super("Number has more than 1");
	}

	public NumberUnderException(String message) {
		super("Message");
	}

}
