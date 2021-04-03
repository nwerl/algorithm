package programmers;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class c1 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] passenger = {1,1,1,1,1,1};
        int[][] train = {{1,2},{1,3},{1,4},{3,5},{3,6}};
        int[] ans = s.solution(6, passenger, train);
        System.out.println(ans[0] + " " + ans[1]);
    }

    public static class Solution {
        public int[] solution(int n, int[] passenger, int[][] train) {
            int[] answer = new int[2];
            boolean[] visit = new boolean[n+1];
            int[] ret = new int[n+1];
            Queue<PPair> q = new LinkedList<PPair>();
            ArrayList<Integer>[] arr = new ArrayList[n+1];
            for(int i=0;i<n+1;i++)
                arr[i] = new ArrayList<>();

            for(int i=0;i<train.length;i++) {
                arr[train[i][0]].add(train[i][1]);
                arr[train[i][1]].add(train[i][0]);
            }
            q.add(new PPair(1, passenger[1-1]));
            visit[1] = true;

            while(!q.isEmpty()) {
                int node = q.peek().node;
                int cnt = q.peek().cnt;
                q.poll();

                for(int i=0;i<arr[node].size();i++) {
                    int nnode = arr[node].get(i);

                    if(!visit[nnode]) {
                        q.add(new PPair(nnode, passenger[nnode-1]+cnt));
                        ret[nnode] = passenger[nnode-1]+cnt;
                        visit[nnode] = true;
                    }
                }
            }

            for(int i=1;i<=n;i++) {
                if(answer[1] <= ret[i]) {
                    answer[1] = ret[i];
                    answer[0] = i;
                }
            }


            return answer;
        }

        class PPair {
            public Integer node;
            public Integer cnt;

            PPair(int node, int cnt) {
                this.node = node;
                this.cnt = cnt;
            }
        }
    }
}
