package programmers;

public class a1 {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] gift_cards = {1, 2, 4, 5, 6, 7}; int[] wants = {4, 1, 5, 2, 6, 7};
        System.out.println(s.solution(gift_cards, wants));
    }

    public static class Solution {
        public int solution(int[] gift_cards, int[] wants) {
            int answer = 0;
            int[] giftNum = new int[100001];

            for(int i : gift_cards) giftNum[i]++;

            for(int i : wants) {
                if(giftNum[i]-1 < 0)    answer++;
                else    giftNum[i]--;
            }

            return answer;
        }
    }
}
