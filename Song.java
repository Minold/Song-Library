package objects;

public class Song {
	
	private String ttl;
	private String ats;
	private String abm;
	private String yr;

	public Song(String title, String artist, String album, String year)
	{
		this.ttl = title;
		this.ats = artist;
		this.abm = album;
		this.yr = year;
	
	}
	public String getArtist() {
		return this.ats;
	}
	public String getTitle() {
		return this.ttl;
	}
	public String getAlbum() {
		return this.abm;
	}
	public String getYear() {
		return this.yr;
	}
	public void setArtist(String artist) {
		this.ats = artist;
	}
	public void setTitle(String title) {
		this.ttl = title;
	}
	public void setAlbum(String album) {
		this.abm = album;
	}
	public void setYear(String year) {
		this.yr = year;
	}
}