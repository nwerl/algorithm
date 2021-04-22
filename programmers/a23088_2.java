package programmers;

import java.util.Stack;

public class a23088_2 {
    public static void main(String[] args) {
        Solution s = new Solution();
        String input = "[](){}";
        System.out.println(s.solution(input));
    }

    public static class Solution {
        public int solution(String s) {
            int answer = 0;
            int N = s.length();

            for(int i=0;i<s.length();i++) {
                Stack<Character> stk = new Stack();
                StringBuilder stringBuilder = new StringBuilder();
                for(int j=0;j<s.length();j++) {
                    stringBuilder.append(s.charAt((j+i)%N));
                }
                for(int j=0;j<s.length();j++) {
                    char ch = stringBuilder.charAt(j);
                    

                    if(ch == '{' || ch == '[' || ch == '(')
                        stk.push(ch);
                    else {
                        if(stk.empty()) break;
                        char prv = stk.pop();
                        if(ch == '}' && prv != '{')
                            break;
                        if(ch == ']' && prv != '[')
                            break;
                        if(ch == ')' && prv != '(')
                            break;
                    }
                
                    if(j == N-1) {
                        if(stk.empty())
                            answer++;
                    }
                }
                
                
            }
            
            return answer;
        }
    }
}
