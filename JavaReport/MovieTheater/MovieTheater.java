package assignment2;

import java.util.Random;

public class MovieTheater {
	private Movie movies[];
	private Random randNum;
	private static int totalTime = 600;
	public MovieTheater(Movie[] movies) {
		this.movies = movies;
	}

	//making schedule function
	public void makeSchedule() {
		randNum=new Random();
		//make random movies array
		for (int i = 0; i < movies.length; i++) {
			int j = randNum.nextInt(movies.length);
			Movie temp = movies[i];
			movies[i] = movies[j];
			movies[j] = temp;
		}

		//print movies
		for (int i = 0; i < movies.length; i++) {
			System.out.println("=================================");
			movies[i].movieInfo();
			//calculate start time 
			int hour = totalTime / 60;
			int minute = totalTime - hour * 60;
			totalTime = totalTime + movies[i].getDuration();
			//calculate end time
			int nextHour = totalTime / 60;
			int nextMinute = totalTime - nextHour * 60;
			
			//when the minute is zero make another zero
			String zero1 = "";
			String zero2 = "";
			if (minute == 0)
				zero1 = "0";
			if (nextMinute == 0)
				zero2 = "0";
			String time = "";
			System.out.println("=================================\n");
			time = "--- Start time: " + hour + ":" + zero1 + minute + " ---\n" + "--- End time: " + nextHour + ":"
					+ zero2 + nextMinute + " ---\n";
			System.out.println(time);
			totalTime += 30;
		}
		System.out.println("=================================\n");
	}

	//main function
	public static void main(String[] args) {

		String[] avengersCast = { "Robert Downey Jr", "Chris HemsWorth", "Scarlett Johanson", "Mark Ruffalo" };
		String[] avengersDirector = {"Anthony Russo, Joe Russo"};
		String[] avengersGenres = {"Fantasy,Action,Adventure,Science Fiction"};
		String avengersInfo = "After the devastating events of Avengers: Infinity War (2018),\n "
				+ "the universe is in ruins. With the help of remaining allies,\n "
				+ "the Avengers assemble once more in order to undo Thanos' actions\n "
				+ "and restore order to the universe.";
		
		String[] shazamCast = { "Zachary Levi", "Mark Strong", "Asher Angel", "Jack Dylan Grazer" };
		String[] shazamDirector = {"David F. Sandberg"};
		String[] shazamGenres = {"None Fiction,Adventure"};
		String shazamsInfo = "We all have a superhero inside us, it just takes a bit of magic to bring it out.\n"
				+ " In Billy Batson's case, by shouting out one word - SHAZAM! "
				+ "-\n this streetwise fourteen-year-old foster kid can turn into the adult superhero Shazam.";
		
		String[] hellboyCast = { "David Harbour", "Milla Jovovich", "Ian McShane", "Sasha Lane" };
		String[] hellboyDirector = {"Neil Marshall"};
		String[] hellboyGenres= {"Action,RPG"};
		String hellboyInfo = "Based on the graphic novels by Mike Mignola, Hellboy, \n"
				+ "caught between the worlds of the supernatural and human,\n"
				+ " battles an ancient sorceress bent on revenge.";
		
		String[] breakthroughCast = { "Sam Trammell", "Dennis haysbert", "Isaac Kragten" };
		String[] breakthroughDirector = {"Roxann Dawson"};
		String[] breakthroughGenres= {"Romance,Action,Adventure"};
		String breakthroughInfo = "When he was 14, Smith drowned in Lake Sainte Louis and was dead for nearly an hour.\n"
				+ " According to reports at the time, CPR was performed 27 minutes to no avail. \n"
				+ "Then the youth's mother, Joyce Smith, entered the room, praying loudly. \n"
				+ "Suddenly, there was a pulse, and Smith came around.";
		
		
		Movie avengers = new Movie("Avengers: Endgameasdfasdfasdfasdfasdfasdf", 180, 2019,
				avengersCast,avengersDirector,avengersGenres,avengersInfo);
		Movie shazam = new Movie("Shazam!", 140, 2019, 
				shazamCast,shazamDirector,shazamGenres,shazamsInfo);
		Movie hellboy = new Movie("Hellboy", 180, 2019, 
				hellboyCast,hellboyDirector,hellboyGenres,hellboyInfo);
		Movie breakthrough = new Movie("Breakthrough", 120, 2019, 
				breakthroughCast,breakthroughDirector,breakthroughGenres,breakthroughInfo);

		Movie[] movies = { avengers, shazam, hellboy, breakthrough };

		MovieTheater CGV = new MovieTheater(movies);

		CGV.makeSchedule();
	}

}
