class Solution {
 public:
  int maximumGroups(vector<int>& grades) {
    // Sort grades, then we can seperate the students into groups of sizes 1, 2,
    // 3, ..., k, s.t. i-th group < (i + 1)-th group for both sum and size.
    // So, we can rephrase the problem into:
    //   Find the max k s.t. 1 + 2 + 3 + ... + k <= n

    //  1 + 2 + 3 + ... + k <= n
    //         k(k + 1) / 2 <= n
    //              k^2 + k <= 2n
    //   (k + 0.5)^2 - 0.25 <= 2n
    //          (k + 0.5)^2 <= 2n + 0.25
    //                    k <= sqrt(2n + 0.25) - 0.5
    return sqrt(grades.size() * 2 + 0.25) - 0.5;
  }
};
