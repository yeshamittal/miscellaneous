package inviteFriends;

import org.json.simple.JSONArray;

public class Main {

	public static void main(String[] args){
		
		Utility.writeJson(Constants.totalFriends, Constants.friendsFilePath);
		JSONArray jsonArray = Utility.readJson(Constants.friendsFilePath);
		Friends friends = Friends.getInstance(jsonArray);
		friends.keepNearby(Constants.baseLat, Constants.baseLon, Constants.thresholdDistance);
		friends.sort();
		friends.printStudents();
	}
	
}
