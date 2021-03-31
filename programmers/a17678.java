package programmers;

import java.util.PriorityQueue;

public class a17678 {
    public static void main(String[] args) {
    
    }

    class Solution {
        public static final int MORNING = 540;
        public String solution(int n, int t, int m, String[] timetable) {
            String answer = "";
            PriorityQueue<Integer> q = new PriorityQueue<>();

            for(String s : timetable) {
                int time = Integer.parseInt(s.split(":")[0])*60 + Integer.parseInt(s.split(":")[1]);
                q.add(time);
            }

            int last = 0;
            int time = MORNING;
            int bus = m;
            while(n-->0) {
                while(!q.isEmpty() && bus-->0 && q.peek() <= time)
                    last = q.poll();

                if(n > 0) {
                    if(q.isEmpty()) {
                        last = time + (n+1)*t;
                        break;
                    }
                }
                else {
                    if(bus > 0)
                        last = time;
                    else
                        last--;
                    break;
                }
                bus = m;
                time += t;
            }

            answer = String.format("%02d:", last/60) + String.format("%02d", last%60); 

            return answer;
        }
    }
}
