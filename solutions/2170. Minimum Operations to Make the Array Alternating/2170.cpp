struct T {
  unordered_map<int, int> count;
  int mx = 0;
  int secondMax = 0;
  int maxFreq = 0;
  int secondMaxFreq = 0;
};

class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    // 0 := odd indices, 1 := even indices
    vector<T> ts(2);

    for (int i = 0; i < nums.size(); ++i) {
      T& t = ts[i % 2];
      const int freq = ++t.count[nums[i]];
      if (freq > t.maxFreq) {
        t.maxFreq = freq;
        t.mx = nums[i];
      } else if (freq > t.secondMaxFreq) {
        t.secondMaxFreq = freq;
        t.secondMax = nums[i];
      }
    }

    if (ts[0].mx == ts[1].mx)
      return nums.size() - max(ts[0].maxFreq + ts[1].secondMaxFreq,
                               ts[1].maxFreq + ts[0].secondMaxFreq);
    return nums.size() - (ts[0].maxFreq + ts[1].maxFreq);
  }
};
