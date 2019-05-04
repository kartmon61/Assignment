package assignment3;

public abstract class Application implements Platform{
	
	private static final String MONTH[]= {"*","January","Feburary","March","April","May","June","July",
			"August","September","October","November","December"};

    private String name;
    private String developer;
    private String release_date;
    

    //Application constructor
	public Application(String name,String developer) {
		this.name = name;
		this.developer=developer;
	}

	//getName & setName
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	//get & set getDeveloper
	public String getDeveloper() {
		return developer;
	}

	public void setDeveloper(String developer) {
		this.developer = developer;
	}

	//get & set Release_Date
	public String getRelease_date() {
		return release_date;
	}

	public void setRelease_date(int day, int month,int year) {

		this.release_date=MONTH[month]+" "+day+", "+year;

	}
}