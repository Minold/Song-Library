package comparator;

import java.util.Comparator;

import objects.Song;

public class SgCmpr implements Comparator<Song>{

	@Override
	public int compare(Song fsong, Song ssong) {
		return fsong.getTitle().toUpperCase().compareTo(ssong.getTitle().toUpperCase());
	}
}
