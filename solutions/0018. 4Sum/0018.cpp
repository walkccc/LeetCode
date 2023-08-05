class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        if(nums.size()<4) return v;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                int start=j+1;
                int end=nums.size()-1;
                while(start<end){
                    long long int sum=(long long int)nums[i]+(long long int)nums[j]+(long long int)nums[start]+(long long int)nums[end];
                    if(sum>target) end--;
                    else if(sum<target) start++;
                    else{
                        v.push_back({nums[i], nums[j], nums[start], nums[end]});
                        while(start<end-1 && nums[end]==nums[end-1]) end--;
                        while(start+1<end && nums[start]==nums[start+1]) start++;
                        start++;
                        end--;
                    }
                }
                while(j+1<nums.size() && nums[j+1]==nums[j]) j++;
            }
            while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
