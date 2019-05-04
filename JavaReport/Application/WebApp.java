package assignment3;

public class WebApp extends Application {

	private String url;
	private String hosting_Provider;

	//WebApp constructor
	public WebApp(String name,String url, String hosting_Provider) {
		super(name,hosting_Provider);
		this.url = url;
	}

	//set & get Url
	public String getUrl() {
		return url;
	}

	public void setUrl(String url) {
		this.url = url;
	}

	//set & get Hosting_provider
	public String getHosting_Provider() {
		return hosting_Provider;
	}

	public void setHosting_Provider(String hosting_Provider) {
		this.hosting_Provider = hosting_Provider;
	}

	//implement platform
	public String platform() {
		
		return "Web";
	}
	
	//toString
	public String toString() {
		return String.format("*  *  *  %s  *  *  *\n"
				+ "Release Date: %s\n"
				+ "URL: %s\n"
				+ "Platform: %s\n",super. getName(),super.getRelease_date(),getUrl(),platform());
	}
	
}