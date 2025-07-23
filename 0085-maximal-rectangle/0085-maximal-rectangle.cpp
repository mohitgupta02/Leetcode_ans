class Solution {
public:
    int largestRectangleArea(vector<int>& mat) {
        int n = mat.size();
        stack<int>st;
        int maxi = 0;

        for(int i =0;i<n;i++){
            while(!st.empty() && mat[st.top()] > mat[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1:st.top();
                maxi = max(maxi, mat[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1: st.top();
            maxi= max(maxi , mat[element] * (nse-pse-1));
        }
        return maxi;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>mat(n,vector<int>(m,0));

        for(int j =0;j<m;j++){
            int sum =0;
            for(int i =0;i<n;i++){
                sum += matrix[i][j] == '1' ? 1:0;
                if(matrix[i][j] == '0') sum=0;
                mat[i][j] = sum;
            }
        }
        int maxi = 0;
        for(int i =0;i<n;i++){
            maxi = max(maxi, largestRectangleArea(mat[i]));
        }
        return maxi;
    }
};