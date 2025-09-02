class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<double,pair<int,int>>temp;
        int n = arr.size();

        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                double x = (double)arr[i]/arr[j];
                temp[x] = {arr[i],arr[j]};
            }
        }
        int cnt =1;
        int a,b;
        vector<int>ans;

        for(auto it:temp){
            if(cnt ==k){
                a = it.second.first;
                b = it.second.second;
                ans.push_back(a);
                ans.push_back(b);
                break;
            }
            cnt++;
        }
        return ans;
      
    }
};