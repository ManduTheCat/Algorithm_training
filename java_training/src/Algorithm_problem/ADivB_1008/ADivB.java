package Algorithm_problem.ADivB_1008;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class ADivB {
    static double num1;
    static double num2;
    static double res;

    public static void main(String[] arg) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        String[] NumArr = bf.readLine().split(" ");

        num1 = Float.parseFloat(NumArr[0]);
        num2 = Float.parseFloat(NumArr[1]);
        res = num1/num2;
        System.out.println(res);

    }
}
