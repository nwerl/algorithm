package programmers;

public class a17676 {
    public static void main(String[] args) {
        String[] inp = {
            "2016-09-15 20:59:57.421 0.351s",
            "2016-09-15 20:59:58.233 1.181s",
            "2016-09-15 20:59:58.299 0.8s",
            "2016-09-15 20:59:58.688 1.041s",
            "2016-09-15 20:59:59.591 1.412s",
            "2016-09-15 21:00:00.464 1.466s",
            "2016-09-15 21:00:00.741 1.581s",
            "2016-09-15 21:00:00.748 2.31s",
            "2016-09-15 21:00:00.966 0.381s",
            "2016-09-15 21:00:02.066 2.62s"
        };

        System.out.println(solution(inp));
    }

    public static int solution(String[] lines) {
        int answer = 0;
        int[] timeline = new int[86400001];

        for(String s : lines) {
            String[] line = s.split(" ");
            String[] time = line[1].split(":");
            int iv = (int)(Double.parseDouble(line[2].replaceAll("s", ""))*1000);
            
            int hour = Integer.parseInt(time[0]);
            int min = Integer.parseInt(time[1]);
            double sec = Double.parseDouble(time[2]);

            int sum = (hour*3600+min*60)*1000+(int)(sec*1000);
            timeline[sum] = 1;
            timeline[sum-iv+1] = -1;
        }
        
        return answer;
    }
}
