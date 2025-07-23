class Solution {
 public:
  int totalNumbers(vector<int>& digits) {
    unordered_set<int> nums;
    vector<int> perm = digits;

    ranges::sort(perm);

    do {
      const int a = perm[0];
      const int b = perm[1];
      const int c = perm[2];
      if (a != 0 && c % 2 == 0)
        nums.insert(a * 100 + b * 10 + c);
    } while (next_permutation(perm.begin(), perm.end()));

    return nums.size();
  }
};
