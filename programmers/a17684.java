package programmers;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class a17684 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] ret = s.solution("TOBEORNOTTOBEORTOBEORNOT");
        for(int i : ret) {
            System.out.println(i);
        }
    }

    public static class Solution {
        public int[] solution(String msg) {
            ArrayList<Integer> answer = new ArrayList<>();
            Map<String, Integer> map = new HashMap<>();
            for(char c='A';c<='Z';c++)
                map.put(String.valueOf(c), c - 'A' + 1);
            int idx = 27;
            
            int i = 0;
            int len = 1;
            while(i+len <= msg.length()){
                String s = msg.substring(i, i+len);
                
                if(map.containsKey(s)) {
                    len++;
                } else {
                    String prv = msg.substring(i, i+len-1);
                    answer.add(map.get(prv));
                    if(!map.containsKey(s))
                        map.put(s, idx++);
                    len = 1;
                    i+=Math.max(1, prv.length());
                }
            }

            answer.add(map.get(msg.substring(i, i+len-1)));

            return answer.stream().mapToInt(lam -> lam).toArray();
        }
    }
}
