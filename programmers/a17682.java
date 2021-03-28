package programmers;

public class a17682 {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.solution("1D2S3T*"));
    }

    public static class Solution {
        public int solution(String dart) {
            int score = 0;
            int sign = 1;
            int sdt = 0;
            int idx = 0;
            int[] arr = {1, 1, 1};

            for(int i=dart.length()-1;i>=0;i--) {
                char ch = dart.charAt(i);
                
                if(ch == '#') {
                    sign = -sign;
                } else if(ch == '*') {
                    arr[idx] *= 2;
                    if(idx<2)
                        arr[idx+1] *= 2;
                } else if(ch == 'S') {
                    sdt = 1;
                } else if(ch == 'D') {
                    sdt = 2;
                } else if(ch == 'T') {
                    sdt = 3;
                } else if(ch >= '0' && ch <= '9') {
                    if(i>0 && ch == '0' && dart.charAt(i-1) == '1') {
                        score = 10;
                        i--;
                    }
                    else {
                        score = (int)(ch-'0');
                    }

                    score = (int) Math.pow(score, sdt)*sign;
                    arr[idx] = score*arr[idx];
                    sign = 1;
                    sdt = 0;
                    score = 0;
                    idx++;
                }
            }
            return arr[0]+arr[1]+arr[2];
        }
    }
}
