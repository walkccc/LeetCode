#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int MOD = 1e9 + 7;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> prefixSum(n + 2, 0);
        prefixSum[1] = 1;

        deque<int> maxDq;
        deque<int> minDq;
        int j = 0;

        for (int i = 1; i <= n; ++i) {
            int val = nums[i - 1];

            while (!maxDq.empty() && nums[maxDq.back()] <= val) {
                maxDq.pop_back();
            }
            maxDq.push_back(i - 1);

            while (!minDq.empty() && nums[minDq.back()] >= val) {
                minDq.pop_back();
            }
            minDq.push_back(i - 1);

            while (nums[maxDq.front()] - nums[minDq.front()] > k) {
                if (maxDq.front() == j) maxDq.pop_front();
                if (minDq.front() == j) minDq.pop_front();
                j++;
            }

            int count = (prefixSum[i] - prefixSum[j]);
            if (count < 0) count += MOD;

            dp[i] = count;
            prefixSum[i + 1] = (prefixSum[i] + count) % MOD;
        }

        return dp[n];
    }
};
