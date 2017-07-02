# miscellaneous

This repository contains various kinds of codes/algorithms 

1) invite friends - Problem statment is given below:

 I have some friends records in a text file (say, friends.json) -- one friend per line, JSON-encoded. 
 I want to invite any friends within 100km of our New Delhi office (GPS coordinates 28.521134, 77.206567) for some food 
 and drinks on us. Write a program that will read the full list of friends and output the names and user ids of matching 
 friends (within 100km), sorted by user id (ascending).
 You can use the first formula from this Wikipedia article to calculate distance: https://en.wikipedia.org/wiki/Great-circle_distance 
 -- don't forget, you'll need to convert degrees to radians.
 Each friend's record will have the following attributes: id, name, latitude, longitude. Please use a test-case generating 
 library (or just random number generators) to generate test data for the problem. Don't forget,
 latitudes lie in the range (-90,90) and longitudes (-180,180).
 
 2) sum of three numbers: Write a program that will print three elements in an array whose sum is equal to a given number.
