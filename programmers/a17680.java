package programmers;

import java.util.HashMap;
import java.util.Map;

public class a17680 {
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] in = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
        System.out.println(s.solution(3, in));
    }

    public static class Solution {
        public void putCache(String city, Map<String, Integer> map) {
            for(Map.Entry<String, Integer> entry : map.entrySet()) {
                map.put(entry.getKey(), entry.getValue()+1);
            }
            map.put(city, 0);
        }

        public int solution(int cacheSize, String[] cities) {
            int answer = 0;
            
            Map<String, Integer> map = new HashMap<>();
            
            for(String city : cities) {
                city = city.toLowerCase();
                if(map.containsKey(city)) {
                    answer += 1;
                    putCache(city, map);
                }
                else {
                    answer += 5;

                    if(map.size() < cacheSize) {
                        putCache(city, map);
                    }
                    else {
                        putCache(city, map);

                        Map.Entry<String, Integer> maxValue = null;
                        for(Map.Entry<String, Integer> entry : map.entrySet()) {
                            if(maxValue == null || entry.getValue() > maxValue.getValue()) {
                                maxValue = entry;
                            }
                        }
                        map.remove(maxValue.getKey());
                    }
                }
            }
            return answer;
        }
    }
}
