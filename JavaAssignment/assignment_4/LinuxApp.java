package assignment3;

public class LinuxApp extends DesktopApp {

	//LinuxApp constructor
	public LinuxApp(String name, String developer,String resolution) {
		super(name, developer,resolution);
	}

	//implement platform
	public String platform() {
		
		return "Linux";
	}

	//toString
	public String toString() {
		return String.format("*  *  *  %s  *  *  *\n"
				+ "Release Date: %s\n"
				+ "Platform: %s\n"
				+ "Resolution: %s\n",super. getName(),super.getRelease_date(),platform(),super.getResolution());
	}

	
}