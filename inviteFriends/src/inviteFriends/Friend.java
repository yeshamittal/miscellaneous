package inviteFriends;

import org.json.simple.JSONObject;

public class Friend implements Comparable{
	private String name;
	private int id;
	private double latitude;
	private double longitude;
	
	public Friend(final String name, final int id, final double latitude, final double longitude){
		this.name = name;
		this.id = id;
		this.latitude = latitude;
		this.longitude = longitude;
	}
	
	public Friend(JSONObject friend){
		this.name = (String) friend.get("name");
		this.id = Integer.parseInt(String.valueOf(friend.get("id")));
	    this.latitude = Double.parseDouble(String.valueOf(friend.get("latitude")));
	    this.longitude = Double.parseDouble(String.valueOf(friend.get("longitude")));
	}
	
	public String getName() {
		return name;
	}

	public void setName(final String name) {
		this.name = name;
	}

	public int getId() {
		return id;
	}

	public void setId(final int id) {
		this.id = id;
	}

	public double getLatitude() {
		return latitude;
	}

	public void setLatitude(final double latitude) {
		this.latitude = latitude;
	}
	
	public double getLongitude() {
		return longitude;
	}

	public void setLongitude(final double longitude) {
		this.longitude = longitude;
	}

	public double distance(double srcLat, double srcLon) {
		srcLat = Math.toRadians(srcLat);
		srcLon = Math.toRadians(srcLon);
		double lat = Math.toRadians(this.latitude);
		double lon = Math.toRadians(this.longitude);
		double lonDiff = Math.abs(srcLon-lon);
		double sin = Math.sin(srcLat) * Math.sin(lat);		
		double cos = Math.cos(srcLat) * Math.cos(lat) * Math.cos(lonDiff);
		
		double sum = sin + cos;
		
		double centralAngle = Math.acos(sum); //in degrees
		double arcLength = Constants.radius * centralAngle;
		return arcLength; //kilometer
	}

	
	@Override
	public int compareTo(Object frnd) {
		int compareId = ((Friend) frnd).getId();
		return this.id - compareId;
	}

	@Override
    public String toString() {
        return "[ name=" + name + ", id=" + id + "]";
    }
}
