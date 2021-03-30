package programmers;

public class a17683 {
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] inp = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};
        System.out.println(s.solution("CC#BCC#BCC#BCC#B", inp));
    }


    static public class Solution {
        public String converter(String s) {
            StringBuffer sb = new StringBuffer();

            for(int i=0;i<s.length();i++) {
                if(s.charAt(i) == '#') {
                    sb.setCharAt(sb.length()-1, (char)(sb.charAt(sb.length()-1)+32));
                } else {
                    sb.append(s.charAt(i));
                }
            }

            return sb.toString();
        }

        public String solution(String m, String[] musicinfos) {
            m = converter(m);
            int maxDuration = 0;
            String answer = "(None)";
            for(int i=musicinfos.length-1;i>=0;i--) {
                String[] s = musicinfos[i].split(",");
                String key = s[2];
                int beginTime = Integer.parseInt(s[0].split(":")[0])*60 + Integer.parseInt(s[0].split(":")[1]);
                int endTime = Integer.parseInt(s[1].split(":")[0])*60 + Integer.parseInt(s[1].split(":")[1]);
                int duration = endTime - beginTime;
                String song = converter(s[3]);
                
                String music = "";
                for(int idx=0;idx<duration;idx++) {
                    music += song.charAt(idx%song.length());
                }

                if(music.contains(m)) {
                    if(!answer.equals("(None)") && maxDuration > duration) {
                        continue;
                    }
                    maxDuration = duration;
                    answer = key;
                }
            }
            
            return answer;
        }
    }
}
