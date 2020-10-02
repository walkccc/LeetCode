class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
       // contribution of each element in subarrrays = (i+1) * (n-i) 
        // i.e, hoe many left indexes for start (including a[i]) * how many right indexes to end ( including a[i])
        // for odd length, just divide by 2
        // now, we have element and it's contribution number, add number * contribution to your answer
        int ans =0,n=arr.size();
        for(int i =0;i<n;i++)
		{
            int contribution = ceil((i+1)*(n-i)/2.0);
            ans+=(contribution*arr[i]);
        }
        return ans;
    }
};