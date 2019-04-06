package assignment2;

public class Movie {
	private String title;
	private int duration;
	private int year;
	private String [] castOfActors;
	private String [] genres;
	private String [] directors;
	private String info;
	
	public Movie() {
	}

	public Movie(String title, int duration, int year, String[] castOfActors,
			String [] directors, String [] genres,String info) {
		this.setTitle(title);
		this.setDuration(duration);
		this.setYear(year);
		this.setCastOfActors(castOfActors);
		this.setDirectors(directors);
		this.setGenres(genres);
		this.setInfo(info);
	}
	
	public String getTitle() {
		return title;
	}
	
	public void setTitle(String title) {
		if(title.length()>20) {
			System.out.println("Length is big. Cut to 20 symbols.");
			this.title= title.substring(0, 20);
		}
		else this.title = title;
	}
	
	public int getDuration() {
		return duration;
	}
	
	public void setDuration(int duration) {
		if(duration <60 || duration >180) {
			System.out.println("Invalid duration. Set to 1.5 hrs.");
			this.duration=90;
		}
		else this.duration = duration;
	}
	
	public int getYear() {
		return year;
	}
	
	public void setYear(int year) {
		if(year > 2020) {
			System.out.println("Invalid year. Set to 2019."	);
			this.year = 2019;
		}
		
		else this.year = year;
	}
	
	public String getCastOfActors() {
		String actors="";
		for(int i=0;i<this.castOfActors.length;i++) {
			actors+=this.castOfActors[i];
			if(i != this.castOfActors.length-1) actors+=", ";
			else actors+=".";
		}
		
		return actors;
	}
	
	public void setCastOfActors(String[] castOfActors) {
		this.castOfActors = castOfActors;
	}
	
	public String getDirectors() {
		String showDirectors="";
		for(int i=0;i<this.directors.length;i++) {
			showDirectors+=this.directors[i];
			if(i != this.directors.length-1) showDirectors+=", ";
			else showDirectors+=".";
		}
		return showDirectors;
	}

	public void setDirectors(String[] directors) {
		this.directors = directors;
	}

	public String getGenres() {
		String showGenres="";
		for(int i=0;i<this.genres.length;i++) {
			showGenres+=this.genres[i];
			if(i != this.genres.length-1) showGenres+=", ";
			else showGenres+=".";
		}
		return showGenres;
	}

	public void setGenres(String [] genres) {
		this.genres = genres;
	}

	public String getInfo() {
		return info;
	}

	public void setInfo(String info) {
		this.info = info;
	}

	public void movieInfo() {
		System.out.printf("***\" %s \"***\n",this.getTitle());
		System.out.printf("Year: %d\n",this.getYear());
		System.out.printf("Running Time: %d minutes\n",this.getDuration());
		System.out.printf("Main roles: %s\n",this.getCastOfActors());
		System.out.printf("Director: %s\n",this.getDirectors());
		System.out.printf("Genres: %s\n",this.getGenres());
		System.out.printf("\n===Plot Summary===\n%s\n\n",this.getInfo());
	}
	
}
