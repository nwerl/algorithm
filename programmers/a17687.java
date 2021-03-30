package programmers;

import java.util.LinkedList;
import java.util.Queue;

public class a17687 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution(16, 16, 2, 2));
    }

    public static class Solution {
        public String solution(int n, int t, int m, int p) {
            String answer = "";
            Queue<Character> q = new LinkedList<>();
            
            int num = 0;
            int order = 0;
            boolean flag = true;

            while(flag) {
                Integer.toString(num, n).chars().mapToObj(c -> (char) c).forEach(c -> q.add(c));

                while(!q.isEmpty()) {
                    Character tmp = q.poll();

                    if(order%m == p-1) {
                        answer += tmp;
                        if(answer.length() == t) {
                            flag = false;
                            break;
                        }
                    }
                    order++;
                }
                num++;
            }

            return answer.toUpperCase();
        }
    }
}
