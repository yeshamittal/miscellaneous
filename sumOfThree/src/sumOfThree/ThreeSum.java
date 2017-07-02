package sumOfThree;

import java.util.Arrays;

public class ThreeSum {
	
	public static void main(String[] args){
		int[] arr = {4,1,6,-4,5,0};
		Arrays.sort(arr);
		//System.out.println(arr[0]); -4,0,1,4,5,6
		int num = 6;
		threeSum(arr, num);
	}
	
	/**
	 * Uncomment the commentted code below to get only 1 set of solution I 
	 * @param arr
	 * @param num
	 */
	public static void threeSum(int[] arr, int num){
		for(int i=0; i<arr.length-2; i++){
			int j = i+1, k = arr.length-1, val = num-arr[i], flag = 0;
			while(j<k){
				if(arr[j] + arr[k] > val){
					k--;
				}
				else if(arr[j] + arr[k] < val){
					j++;
				}
				else{
					//flag = 1;
					System.out.println(arr[i] + " " + arr[j] + " " + arr[k]);
					j++;
					//break;
				}
			}
			//if(flag==1){
			//	break;
			//}
		}
	}
	
}
