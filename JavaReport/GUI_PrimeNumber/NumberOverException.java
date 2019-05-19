package Assignment_6;

public class NumberOverException extends Exception {

	public NumberOverException() {
		super("Number has more than 8 digits!");
	}

	public NumberOverException(String message) {
		super("Message");
	}

}
