package assignment3;

public abstract class MoblieApp extends Application {
	
	private String os_Version;
	
	//MobileApp constructor
	public MoblieApp(String name,double os_Version,String developer) {
		super(name,developer);
		this.os_Version = Double.toString(os_Version);
	}

	
	
	//get & set Os_version
	public String getOs_Version() {
		return os_Version;
	}

	public void setOs_Version(int os_Version) {
		this.os_Version = Double.toString(os_Version);
	}


}