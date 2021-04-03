package programmers;

public class b1 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] needs = {
                        {1, 0, 0},
                        {1, 1, 0},
                        {1, 1, 0},
                        {1, 0, 1},
                        {1, 1, 0},
                        {0, 1, 1}
                    };

        System.out.println(s.solution(needs, 7));
    }

    public static class Solution {
        public int N;
        public int M;
        public int[] part;
        public int func(int[] needs) {
            int ret = 0;

            int p = 0;
            for(int i : part) {
                p += (1 << i);
            }

            for(int i=0;i<N;i++) {
                int res = p | needs[i];
                if(res == p || res == needs[i]) ret++;
            }

            return ret;
        }

        public int combi(int n, int r, int[] needs) {
            if(r == 0) {
                return func(needs);
            }
            else if(n < r){
                return 0;
            }
            else {
                part[r-1] = n-1;
                return Math.max(combi(n-1, r-1, needs), combi(n-1, r, needs));
            }
        }

        public int solution(int[][] need, int r) {
            int answer = 0;
            N = need.length; M = need[0].length;
            part = new int[r];
            int[] needs = new int[need.length];

            for(int i=0;i<N;i++) {
                int tmp = 0;
                for(int j=0;j<M;j++) {
                    if(need[i][j] == 1)
                        tmp += (1 << j);
                }
                needs[i] = tmp;
            }

            answer = combi(M, r, needs);

            return answer;
        }
    }
}
