package inviteFriends;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
public class Utility {
	
	public static JSONArray readJson(String filename) {
		JSONParser parser = new JSONParser();
		JSONArray jsonArr = null;
		try{
			jsonArr = (JSONArray) parser.parse(new FileReader(filename));
		}
		catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (org.json.simple.parser.ParseException e) {
            e.printStackTrace();
        }
		return jsonArr;
	}
	
	public static void writeJson(int totalFriends, String filename){
		JSONObject obj = null;
		JSONArray frndsJsonArray = new JSONArray();
		for(int i=0; i<totalFriends; i++){
			double lat = Math.random() * 180 - 90;
			double lon = Math.random() * 360 - 180;
			int id = (int) Math.random() * 100 + 1;
			obj = new JSONObject();
			obj.put("name", "abc" + i);
			obj.put("id", id);
			obj.put("latitude", lat);
			obj.put("longitude", lon);
			frndsJsonArray.add(obj);
		}
	
		try (FileWriter file = new FileWriter("friends.json")) {
			file.write(frndsJsonArray.toJSONString());
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
}

