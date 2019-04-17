package assignment3;

public abstract class DesktopApp extends Application {

	private String resolution;

	//DesktopApp constructor
	public DesktopApp(String name,String developer,String resolution) {
		super(name,developer);
		this.resolution = resolution;
	}

	public String getResolution() {
		return resolution;
	}

	public void setResolution(String resolution) {
		this.resolution = resolution;
	}

	public String getClassName() {

		return "Desktop";
	}

}