package Algorithm_problem.ASubB_1001;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class A_sub_B_1001 {
    public static void main(String[] agr)throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String numString = bf.readLine();
        String[] NumArr = numString.split( " ");
        int sum = Integer.parseInt(NumArr[0]) + Integer.parseInt(NumArr[1]);
        System.out.print(sum);
    }
}
