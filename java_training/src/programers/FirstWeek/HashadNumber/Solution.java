package programers.FirstWeek.HashadNumber;
import java.util.ArrayList;
class Solution {
    public static boolean solution(int x) {

        boolean answer = false;
        Integer num = x;
        ArrayList <Integer> SplitNums = new ArrayList<Integer>();
        while(num > 0){
            SplitNums.add(num % 10);
            num /=10;
        }
        Integer sum = 0;
        for(int i = 0; i < SplitNums.size(); i++){
            sum += SplitNums.get(i);
        }
        if(x % sum == 0){
            answer = true;
        }
        return answer;
    }
    public static void main(String[] args) {

       System.out.println( solution(19));
    }
}