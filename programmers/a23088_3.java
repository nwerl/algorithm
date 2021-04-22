package programmers;

import java.util.ArrayList;

public class a23088_3 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] a =  {-1,1,0};
        int[][] edges = {{0,1},{1,2}};

        System.out.println(s.solution(a, edges));
    }

    public static class Solution {
        private boolean[] visit;
        private ArrayList<ArrayList<Integer>> arr  = new ArrayList<ArrayList<Integer>>();
        private int R = 0;
        private int lastNode = 0;
        private long answer = 0;

        void dfs(int here, int cnt) {
            visit[here] = true;
            if(cnt > R) {
                lastNode = here;
                R = cnt;
            }

            for(int i=0;i<arr.get(here).size();i++) {
                int next = arr.get(here).get(i);
                if(!visit[next]) {
                    visit[next] = true;
                    dfs(next, cnt+1);
                }
            }
        }

        boolean dfs2(int here, int cnt) {
            visit[here] = true;
            if(cnt == R/2) {
                lastNode = here;
                return true;
            }

            for(int i=0;i<arr.get(here).size();i++) {
                int next = arr.get(here).get(i);
                if(!visit[next]) {
                    visit[next] = true;
                    if(dfs2(next, cnt+1))
                        return true;
                }
            }

            return false;
        }

        long dfs3(long[] a, int here) {
            visit[here] = true;
            long ret = Math.abs(a[here]);
            for(int i=0;i<arr.get(here).size();i++) {
                int next = arr.get(here).get(i);
                if(!visit[next]) {
                    visit[next] = true;
                    ret += dfs3(a, next);
                }
            }

            if(here != lastNode)
                answer += Math.abs(ret);
            
            return ret;
        }

        public long solution(int[] b, int[][] edges) {
            long sum = 0;
            long[] a = new long[b.length];
            for(int i=0;i<b.length;i++) {
                sum += b[i];
                a[i] = b[i];
            }
                
            if(sum != 0)    return -1;
            
            for(int i=0;i<a.length;i++) {
                arr.add(new ArrayList<Integer>());
            }

            for(int i=0;i<edges.length;i++) {
                arr.get(edges[i][0]).add(edges[i][1]);
                arr.get(edges[i][1]).add(edges[i][0]);
            }
            visit = new boolean[a.length];
            dfs(0, 0);
            for(int i=0;i<a.length;i++)  visit[i] = false;
            R = 0;
            dfs(lastNode, 0);
            for(int i=0;i<a.length;i++)  visit[i] = false;
            dfs2(lastNode, 0);
            for(int i=0;i<a.length;i++)  visit[i] = false;
            dfs3(a, lastNode);

            return answer;
        }
    }
}