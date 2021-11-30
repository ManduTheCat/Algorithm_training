package Algorithm_problem.CountWord_1152;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class CountWord {
    public String[] stringArr;
    public int count = 0;
    public void counting() throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        this.stringArr = bf.readLine().split(" ");
//        System.out.println(stringArr.length);
        for(String loop : stringArr) {
//            System.out.println("str is :" + stringArr[i]);
            int LenString = loop.length();
            if(LenString > 0){
                count++;
            }
        }
        System.out.println(count);
    }
    public static void main(String[] argv) throws IOException
    {

        CountWord cw = new CountWord();
        cw.counting();
    }
}
