package programers.FirstWeek.HashadNumber;
import java.util.ArrayList;
class Solution {
    public static boolean solution(int x) {
        int num = x;
        ArrayList<Integer> arrNum = new ArrayList<>();
        while(num > 0) {
            arrNum.add(num %10);
            num /= 10;
        }
        System.out.println(arrNum);
        boolean answer = true;
        return answer;
    }
    public static void main(String[] args) {
        solution(121);
    }
}