class Solution {
 public:
  int numTriplets(vector<int>& nums1, vector<int>& nums2) {
    return countTriplets(nums1, nums2) + countTriplets(nums2, nums1);
  }

 private:
  // Returns the number of triplet (i, j, k) if A[i]^2 == B[j] * B[k].
  int countTriplets(const vector<int>& A, const vector<int>& B) {
    int res = 0;
    unordered_map<int, int> count;

    for (const int b : B)
      ++count[b];

    for (const int a : A) {
      const long target = static_cast<long>(a) * a;
      for (const auto& [b, freq] : count) {
        if (target % b > 0 || !count.count(target / b))
          continue;
        if (target / b == b)
          res += freq * (freq - 1);
        else
          res += freq * count[target / b];
      }
    }

    return res / 2;
  }
};
