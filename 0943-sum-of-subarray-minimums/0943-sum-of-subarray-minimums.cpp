class Solution {
public:
    vector<int> nsee(vector<int>&arr,int n){
        stack<int>st;
        vector<int>nse(n,0);

        for(int  i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();

            }
            nse[i]= st.empty() ? n:st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> psee(vector<int>&arr,int n){
        vector<int>pse(n,0);
        stack<int>st;
        for(int i =0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i]= st.empty() ? -1:st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int mod = 1e9 +7;
        vector<int>nse =  nsee(arr,n);
        vector<int>pse= psee(arr,n);
        int total =0;
        for(int i =0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i]-i;
            total = (total + (left * right * 1ll * arr[i])%mod)%mod;
        }
        return total;
    }
};