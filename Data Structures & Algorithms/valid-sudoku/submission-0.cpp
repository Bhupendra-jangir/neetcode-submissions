class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> st;
            for(int j=0;j<9;j++){
                char ch = board[i][j];
                if(ch!='.' && st.find(ch) != st.end()) return false;
                st.insert(ch);
            }
        }
       
        for(int i=0;i<9;i++){
            unordered_set<char> st;
            for(int j=0;j<9;j++){
                char ch = board[j][i];
                if(ch!='.' && st.find(ch) != st.end()) return false;
                st.insert(ch);
            }
        }   

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                unordered_set<char> st;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        char ch = board[k+i*3][l+j*3];
                        if(ch!='.' && st.find(ch) != st.end()) return false;
                        st.insert(ch);
                    }
                }
            }
        }
        return true;
    }
};
