class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        //row check
        for (int i=0; i<n; i++) {
            map<char,int> mpp;
            for (int j=0; j<m; j++) {
                if (board[i][j] != '.') {
                    if (mpp.find(board[i][j]) != mpp.end()) {
                        return false;
                    }
                    mpp[board[i][j]]++;
                }
            }
        }

        //col check
        for (int i=0; i<m; i++) {
            map<char,int> mpp;
            for (int j=0; j<n; j++) {
                if (board[j][i] != '.') {
                    if (mpp.find(board[j][i]) != mpp.end()) {
                        return false;
                    }
                    mpp[board[j][i]]++;
                }
            }
        }

        //square check
        for (int kr=0; kr<3; kr++) {
            for (int kc=0; kc<3; kc++) {
                map<char,int> mpp;
                for (int i=kr*(n/3); i<kr*(n/3) + 3; i++) {
                    for (int j=kc*(m/3); j<kc*(m/3) + 3; j++) {
                        if (board[i][j] != '.') {
                        if (mpp.find(board[i][j]) != mpp.end()) {
                            return false;
                        }
                        mpp[board[i][j]]++;
                        }
                    }
                }
            }
        }

        return true;
    }
};
