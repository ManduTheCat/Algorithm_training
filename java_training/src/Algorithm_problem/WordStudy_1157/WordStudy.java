package Algorithm_problem.WordStudy_1157;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class WordStudy {

    static public void main(String[] argv)throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] InputString = bf.readLine().toUpperCase().split("");
        String[] UniqueString = Arrays.stream(InputString).distinct().toArray(String[]::new);
        // String[]::new == 생성자참조식 https://hianna.tistory.com/554 http://yoonbumtae.com/?p=2776
        int[] counting = new int[UniqueString.length];
        for(String loop : InputString ){
            for(int j = 0; j < UniqueString.length; j++){
                if(loop.equals( UniqueString[j])) {
                    counting[j] = counting[j]+ 1;
                }
            }
        }
        int[] SortedCounting = counting.clone();
        Arrays.sort(SortedCounting);
        int max_count = SortedCounting[SortedCounting.length - 1];
        if(SortedCounting.length > 1) {
            if (SortedCounting[SortedCounting.length - 1] == SortedCounting[SortedCounting.length - 2]) {
                System.out.println("?");
                return;
            }
        }
        int index = 0;
        for(int i = 0; i < counting.length; i++){
            if(max_count == counting[i]){
                index = i;
            }
        }
        System.out.println(UniqueString[index]);
    }
}
