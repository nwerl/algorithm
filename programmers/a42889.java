package programmers;

import java.util.Arrays;

public class a42889 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] inp = {4,4,4,4,4};
        int[] out = s.solution(4, inp);
        for(int k : out) {
            System.out.println(k);
        }
    }
    public static class Solution {
        public int[] solution(int N, int[] stages) {
            int[] answer = new int[N];
            int M = stages.length;
            Arrays.sort(stages);
            int[] sum = new int[N+1];
            double[] failure = new double[N+1];

            for(int i : stages)
            {
                if(i > N) continue;
                sum[i]++;
            }

            int cnt = 0;
            for(int i=1;i<=N;i++) {
                if(M-cnt == 0)  continue;
                failure[i] = (double)sum[i]/(double)(M-cnt);
                cnt += sum[i];
            }

            for(int i=0;i<N;i++) {
                int el = 0;
                double MAX = 0;
                for(int j=N;j>=1;j--) {
                    if(MAX <= failure[j]) {
                        MAX = failure[j];
                        el = j;
                    }
                }
                answer[i] = el;
                failure[el] = -1;
            }
            return answer;
       }
    }
}
