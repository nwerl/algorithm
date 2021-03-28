package programmers;

import java.util.ArrayList;

public class a17681 {
    public static void main(String[] args) {

    }

    // 남의 코드. String.format 부분 유의할 것
    
    class Solution {
        public String[] solution(int n, int[] arr1, int[] arr2) {
            String[] answer = new String[n];

            for(int i=0;i<n;i++) 
                answer[i] = Integer.toBinaryString(arr1[i] | arr2[i]);
            
            for(int i=0;i<n;i++) {
                answer[i] = String.format("%" + n + "s", answer[i]);
                answer[i] = answer[i].replaceAll("1", "#");
                answer[i] = answer[i].replaceAll("0", " ");
            }
            

            return answer;
        }
    }

    // 내 코드
    // class Solution {
    //     public String[] solution(int n, int[] arr1, int[] arr2) {
    //         String[] answer = new String[n];
    //         ArrayList<String> map1 = new ArrayList<>();
    //         ArrayList<String> map2 = new ArrayList<>();

    //         for(int num : arr1) {
    //             StringBuilder sb = new StringBuilder();
    //             while(num>0) {
    //                 char ch = num%2==0 ? ' ' : '#';
    //                 sb.append(ch);
    //                 num/=2;
    //             }
    //             while(sb.length() < n) {
    //                 sb.append(' ');
    //             }
    //             sb.reverse();
    //             map1.add(sb.toString());
    //         }

    //         for(int num : arr2) {
    //             StringBuilder sb = new StringBuilder();
    //             while(num>0) {
    //                 char ch = num%2==0 ? ' ' : '#';
    //                 sb.append(ch);
    //                 num/=2;
    //             }
    //             while(sb.length() < n) {
    //                 sb.append(' ');
    //             }
    //             sb.reverse();
    //             map2.add(sb.toString());
    //         }

    //         for(int i=0;i<map1.size();i++) {
    //             StringBuffer sb = new StringBuffer();
    //             for(int j=0;j<n;j++)
    //             {
    //                 if(map1.get(i).charAt(j) == '#' || map2.get(i).charAt(j) == '#')
    //                     sb.append('#');
    //                 else
    //                     sb.append(' ');
    //             }
    //             sb.reverse();
    //             answer[i] = sb.toString();
    //         }

    //         return answer;
    //     }
    // }
}
