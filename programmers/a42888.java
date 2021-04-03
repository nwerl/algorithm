package programmers;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class a42888 {
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] inp = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
        String[] out = s.solution(inp);
        for(String a : out)
            System.out.println(a);
    }
    public static class Solution {
        public String[] solution(String[] record) {
            ArrayList<String> ans = new ArrayList<>();
            Map<String, String> hash = new HashMap<>();
            
            for(String s : record) {
                String cmd = s.split(" ")[0];
                if(cmd.equals("Enter")) {
                    String id = s.split(" ")[1];
                    String name = s.split(" ")[2];
                    hash.put(id, name);
                }
                else if(cmd.equals("Change")) {
                    String id = s.split(" ")[1];
                    String name = s.split(" ")[2];
                    hash.put(id, name);
                }
            }

            for(String s : record) {
                String cmd = s.split(" ")[0];
                String id = s.split(" ")[1];

                if(cmd.equals("Enter")) {
                    ans.add(hash.get(id)+"님이 들어왔습니다.");
                }
                else if(cmd.equals("Leave")) {
                    ans.add(hash.get(id)+"님이 나갔습니다.");
                }
            }



            
            return ans.stream().toArray(String[]::new);
        }
    }
}
