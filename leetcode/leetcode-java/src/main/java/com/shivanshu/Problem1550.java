package com.shivanshu;

public class Problem1550 {
    public static void main(String[] args) {

    }

    public boolean threeConsecutiveOdds(int[] arr) {
        if(arr.length < 3) return  false;
        for(int i=0;i<arr.length - 3; i++){
            if(arr[i] % 2 == 1 && arr[i+1] % 2 == 1 && arr[i+2] % 2 == 0){
                return true;
            }
        }
        return false;
    }
}
