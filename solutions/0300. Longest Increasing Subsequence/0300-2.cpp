class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    // tail[i] := the minimum tail of all increasing subseqs having length i + 1
    // it's easy to see that tail must be an increasing array
    vector<int> tail;

    for (const int num : nums) {
      if (tail.empty() || num > tail.back()) {
        tail.push_back(num);
        continue;
      }
      int l = 0;
      int r = tail.size();
      // find the first index l in tail s.t. tail[l] >= num
      while (l < r) {
        const int m = l + (r - l) / 2;
        if (tail[m] >= num)
          r = m;
        else
          l = m + 1;
      }
      tail[l] = num;
    }

    return tail.size();
  }
};
