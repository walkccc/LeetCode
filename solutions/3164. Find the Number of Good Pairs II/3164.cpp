class Solution {
 public:
  long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    unordered_map<int, int> count;
    long ans = 0;

    for (const int num : nums2)
      ++count[num * k];

    for (const int num : nums1)
      for (int divisor = 1; divisor <= sqrt(num); ++divisor)
        if (num % divisor == 0) {
          ans += count.contains(divisor) ? count[divisor] : 0;
          if (num / divisor != divisor)
            ans += count.contains(num / divisor) ? count[num / divisor] : 0;
        }

    return ans;
  }
};
