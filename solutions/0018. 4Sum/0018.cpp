class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
       
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i = 0;i < nums.size();i++){
            for(int j = i+1;j < nums.size();j++ ){
                int l = j+1;
                int r = nums.size()-1;
                
                while(l<r){
                    if((long)nums[i]+nums[j]+nums[l]+nums[r] > target){
                        r--;
                    }
                    
                    else if((long)nums[i]+nums[j]+nums[l]+nums[r] < target){
                        l++;
                    }
                    
                    else{
                        s.insert({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l<r and nums[l] == nums[l-1]) l++;
                        while(l<r and nums[r] == nums[r+1]) r--;
                    }
                }
            }
        }
        
        for(auto b : s){
            ans.push_back(b);
        }
        return ans;
    }
};
