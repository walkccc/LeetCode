class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    // tail[i] := the minimum tail of all increasing subseqs having length i + 1
    // it's easy to see that tail must be an increasing array
    vector<int> tail;

    for (const int num : nums)
      if (tail.empty() || num > tail.back())
        tail.push_back(num);
      else
        tail[firstGreaterEqual(tail, num)] = num;

    return tail.size();
  }

 private:
  // find the first index l s.t A[l] >= target
  // return A.size() if can't find
  int firstGreaterEqual(const vector<int>& A, int target) {
    return lower_bound(begin(A), end(A), target) - begin(A);
  }
};
