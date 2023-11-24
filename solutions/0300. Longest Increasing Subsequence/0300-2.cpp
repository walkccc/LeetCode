class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    // tail[i] := the min tail of all increasing subseqs having length i + 1
    // It's easy to see that tail must be an increasing array.
    vector<int> tail;

    for (const int num : nums)
      if (tail.empty() || num > tail.back())
        tail.push_back(num);
      else
        tail[firstGreaterEqual(tail, num)] = num;

    return tail.size();
  }

 private:
  int firstGreaterEqual(const vector<int>& A, int target) {
    return ranges::lower_bound(A, target) - A.begin();
  }
};
