package programmers;

import java.util.HashMap;
import java.util.Map;

public class a17677 {
    public static void main(String[] args) {
        Solution s=  new Solution();
        System.out.println(s.solution("E=M*C^2", "e=m*c^2"));
    }

    static public class Solution {
        public int solution(String str1, String str2) {
            int answer = 0;

            str1 = str1.toUpperCase();
            str2 = str2.toUpperCase();
            Map<String, Integer> map1 = new HashMap<>();
            Map<String, Integer> map2 = new HashMap<>();

            int union = 0;
            int inter = 0;

            
            for(int i=0;i<str1.length()-1;i++){
                if(!Character.isLetter(str1.charAt(i)) || !Character.isLetter(str1.charAt(i+1)))  continue;
                String key = str1.substring(i, i+2);
                if(!map1.containsKey(key)) {
                    map1.put(key, 1);
                }
                else {
                    map1.put(key, map1.get(key)+1);
                }
                inter++;
            }
            for(int i=0;i<str2.length()-1;i++){
                if(!Character.isLetter(str2.charAt(i)) || !Character.isLetter(str2.charAt(i+1)))  continue;
                String key = str2.substring(i, i+2);
                if(!map2.containsKey(key)) {
                    map2.put(key, 1);
                }
                else {
                    map2.put(key, map2.get(key)+1);
                }
                inter++;
            }

            if(inter==0)    return 65536;
            
            for(Map.Entry<String, Integer> entry : map1.entrySet()) {
                if(map2.containsKey(entry.getKey())) {
                    int v1 = map1.get(entry.getKey()), v2 = map2.get(entry.getKey());
                    union = union + Math.min(v1, v2);
                    inter = inter - Math.min(v1, v2);
                }
            }

            System.out.println(union + " " + inter);

            answer = union*65536/inter;

            return answer;
        }
    }
}
