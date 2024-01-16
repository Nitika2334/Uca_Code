package Test_Series_03;

import java.util.*;

public class container_with_most_water{
    public static int max_area(int arr[]){
        int area=0;
        int left=0 ;
        int right=arr.length-1;
        while(left<right){
            int width=right-left;
            area=Math.max(area , width*Math.min(arr[left],arr[right]));
            if(arr[left]<arr[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int arr[]=new int[n];
        for(int i=0 ; i<n ; i++){
            arr[i]=sc.nextInt();
        }
        System.out.println(max_area(arr));
        sc.close();
    }
}