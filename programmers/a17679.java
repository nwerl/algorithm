package programmers;

public class a17679 {
    public static void main(String[] args) {
        Solution s = new Solution();
        String[] inp = {"CCBDE", "AAADE", "AAABF", "CCBBF"};
        System.out.println(s.solution(4, 5, inp));
    }

    public static class Solution {
        int[][] dir = {{1, 0}, {0, 1}, {1, 1}};

        public void down(int n, int m, char[][] board) {

            for(int i=n-1;i>=0;i--) {
                for(int j=0;j<m;j++){
                    if(board[i][j] == ' ')  continue;
                    
                    int y = i+1;
                    while(y < n && board[y][j] == ' ') {
                        board[y][j] = board[y-1][j];
                        board[y-1][j] = ' ';
                        y++;
                    }
                }
            }
        }

        public boolean bomb(int y, int x, int n, int m, char[][] board, char[][] cpy) {
            int flag = 0;
            boolean ret = false;
            
            for(int d=0;d<3;d++) {
                int ny = y+dir[d][0];
                int nx = x+dir[d][1];

                if(ny>=0 && ny<n && nx>=0 && nx<m && cpy[y][x] == cpy[ny][nx]) {
                    flag++;
                }
            }

            if(flag>=3) {
                for(int d=0;d<3;d++) {
                    int ny = y+dir[d][0];
                    int nx = x+dir[d][1];
                    board[ny][nx] = ' ';
                }
                board[y][x] = ' ';
                ret = true;
            }

            return ret;
        }

        public int solution(int n, int m, String[] b) {
            int answer = 0;
            char[][] board = new char[n][];
            char[][] cpy = new char[n][m];
            for(int i=0;i<n;i++)
                board[i] = b[i].toCharArray();

            boolean end = true;
            while(end) {
                end = false;
                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++){
                        cpy[i][j] = board[i][j];
                    }
                }

                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        if(cpy[i][j] == ' ')
                            continue;
                        end |= bomb(i, j, n, m, board, cpy);
                    }
                }

                for(int i=0;i<n;i++) {
                    for(int j=0;j<m;j++) {
                        if(board[i][j] != cpy[i][j])
                            answer++;
                    }
                }

                down(n, m, board);
            }

            return answer;
        }
    }
}
