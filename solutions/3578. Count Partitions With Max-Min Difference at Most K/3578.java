class Solution {
    public int countPartitions(int[] nums, int k) {

        int n = nums.length;
        int MOD = 1_000_000_007;

        int[] dp = new int[n + 1];
        dp[0] = 1;

        int[] prefixSum = new int[n + 2];
        prefixSum[1] = 1;

        java.util.Deque<Integer> maxDq = new java.util.ArrayDeque<>();
        java.util.Deque<Integer> minDq = new java.util.ArrayDeque<>();
        int j = 0;

        for (int i = 1; i <= n; i++) {
            int val = nums[i - 1];

            while (!maxDq.isEmpty() && nums[maxDq.peekLast()] <= val) {
                maxDq.pollLast();
            }
            maxDq.offerLast(i - 1);

            while (!minDq.isEmpty() && nums[minDq.peekLast()] >= val) {
                minDq.pollLast();
            }
            minDq.offerLast(i - 1);

            while (nums[maxDq.peekFirst()] - nums[minDq.peekFirst()] > k) {
                if (maxDq.peekFirst() == j) maxDq.pollFirst();
                if (minDq.peekFirst() == j) minDq.pollFirst();
                j++;
            }

            int count = (prefixSum[i] - prefixSum[j]);
            if (count < 0) count += MOD;

            dp[i] = count;
            prefixSum[i + 1] = (prefixSum[i] + count) % MOD;
        }

        return dp[n];
    }
}
