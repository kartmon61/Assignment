package assignment3;


public class AndroidApp extends MoblieApp {

	private String market;
	//AndroidApp constructor
	public AndroidApp(String name, double os_Version,String developer,String market) {
		super(name, os_Version,developer);
		this.market=market;
	}

	//implement platform
	public String platform() {
		
		return "Android"+" v"+super.getOs_Version();
	}

	//toString
	public String toString() {
		return String.format("*  *  *  %s  *  *  *\n"
				+ "Available in %s \n"
				+ "Release Date: %s\n"
				+ "Platform: %s\n",super. getName(),this.market,super.getRelease_date(),platform());
	}

}