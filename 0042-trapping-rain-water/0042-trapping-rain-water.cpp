class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>leftMax(n,0);
        vector<int>rightMax(n,0);
        leftMax[0]=0;
        for(int i =1;i<n;i++){
            int maxi = max(leftMax[i-1],height[i-1]);
            leftMax[i] = maxi;
        }
        rightMax[n-1]=0;
        for(int i =n-2;i>=0;i--){
            int maxi = max(rightMax[i+1],height[i+1]);
            rightMax[i]= maxi;
        }
        int total=0;
        for(int i =0;i<n;i++){
            if(height[i] < leftMax[i] && height[i] < rightMax[i]){
                total += min(leftMax[i],rightMax[i]) - height[i];
            }
        }
        return total;

    }
};