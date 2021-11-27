package Algorithm_problem.CountWord_1152;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
public class CountWord {
    public String[] stringArr;
    public void counting() throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        this.stringArr = bf.readLine().split(" ");
    }
    public static void main(String[] argv)
    {

    }
}
