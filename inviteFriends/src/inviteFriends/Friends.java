package inviteFriends;

import java.util.ArrayList;
import java.util.Collections;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

public class Friends {
	private static Friends instance = null;
	private ArrayList<Friend> friends;
	
	private Friends(JSONArray friendsArr){
		friends = new ArrayList<Friend>();
		for (Object frndObj : friendsArr) {
			Friend friend = new Friend((JSONObject) frndObj);
			friends.add(friend);    
		  }
	}
	
	public static synchronized Friends getInstance(JSONArray friendsArr) {
	    if (instance == null) {
	    	instance = new Friends(friendsArr);
	    }
	    return instance;
	}
	
	public void print(){
		for(int i=0; i<friends.size(); i++){
			System.out.println(friends.get(i).getName() + " " + friends.get(i).getId() + " "
					+ friends.get(i).getLatitude() + " " + friends.get(i).getLongitude());
		}
	}

	public void keepNearby(double baseLat, double baseLon, int thresholdDistance){
		ArrayList<Friend> nearbyFriends = new ArrayList<Friend>();
		for(Friend frnd: friends){
			double frndDistance = frnd.distance(baseLat, baseLon);
			if(frndDistance <= thresholdDistance){
				nearbyFriends.add(frnd);
			}
		}
		friends = nearbyFriends;
	}
	
	public void sort() {
		Collections.sort(friends);
	}

	public void printStudents(){
		for(Friend frnd: friends){
			System.out.println(frnd);
		}
	}
}
