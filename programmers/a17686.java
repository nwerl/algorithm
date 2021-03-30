package programmers;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class a17686 {
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] inp = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
        String[] ret = s.solution(inp);

        for(String ss : ret) {
            System.out.println(ss);
        }
    }

    public static class Solution {
        public String[] solution(String[] files) {
            String[] answer = {};
            ArrayList<FileName> fileArr = new ArrayList<>();

            for(int f=0;f<files.length;f++) {
                String file = files[f];
                int idx = 0;
                String[] fileName = {"", "", ""};
                for(int i=0;i<file.length();i++) {
                    if(idx == 0 && Character.isDigit(file.charAt(i)))
                        idx++;
                    if(idx == 1 && !Character.isDigit(file.charAt(i)))
                        idx++;
                    fileName[idx] += file.charAt(i);
                }
                fileArr.add(new FileName(fileName));
            }
            Collections.sort(fileArr);

            return fileArr.stream().map(o -> o.combine()).toArray(String[]::new);
        }

        class FileName implements Comparable<FileName>{
            public String head;
            public String tail;
            public String number;

            FileName(String[] fileName) {
                this.head = fileName[0];
                this.number = fileName[1];
                this.tail = fileName[2];
            }

            @Override
            public int compareTo(FileName o) {
                String aHead = this.head.toUpperCase();
                String bHead = o.head.toUpperCase();
                
                if(aHead.compareTo(bHead) == 0) {
                    Integer aNum = Integer.parseInt(this.number);
                    Integer bNum = Integer.parseInt(o.number);
                    if(aNum.compareTo(bNum) == 0) {
                        return 0;
                    }
                    return aNum.compareTo(bNum);
                }
                return aHead.compareTo(bHead);
            }

            public String combine() {
                return this.head + this.number + this.tail;
            }
        }
    }
}
