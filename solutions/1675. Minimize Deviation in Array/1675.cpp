class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        for(auto&n: nums)
        {
            if(n%2)
                n *=2;
            mx = mx>=n?mx:n;
            mn = mn<=n?mn:n;
        }

        priority_queue<int> mxHeap;
        for(auto&n:nums)
            mxHeap.push(n);

        int mnDiff=mx-mn;

        while(mxHeap.top()%2==0) {
            int top = mxHeap.top();
            mxHeap.pop();
            top/=2;
            mxHeap.push(top);
            mn = min(mn,top);
            mx = mxHeap.top();
            mnDiff = min(mnDiff,mx-mn);
        }
        return mnDiff;    
    }
};