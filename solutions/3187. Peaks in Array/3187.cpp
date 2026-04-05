class FenwickTree {
 public:
  FenwickTree(int n) : sums(n + 1) {}

  void add(int i, int delta) {
    while (i < sums.size()) {
      sums[i] += delta;
      i += lowbit(i);
    }
  }

  int get(int i) const {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= lowbit(i);
    }
    return sum;
  }

 private:
  vector<int> sums;

  static inline int lowbit(int i) {
    return i & -i;
  }
};

class Solution {
 public:
  vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> peak = getPeak(nums);
    FenwickTree tree(peak.size());

    for (int i = 0; i < peak.size(); ++i)
      tree.add(i + 1, peak[i]);

    // Update the peak array and Fenwick tree if the peak status of nums[i]
    // changes.
    auto update = [&](int i) {
      const int newPeak = isPeak(nums, i);
      if (newPeak != peak[i]) {
        tree.add(i + 1, newPeak - peak[i]);
        peak[i] = newPeak;
      }
    };

    for (const vector<int>& query : queries)
      if (query[0] == 1) {
        const int l = query[1];
        const int r = query[2];
        ans.push_back(r - l < 2 ? 0 : tree.get(r) - tree.get(l + 1));
      } else if (query[0] == 2) {
        const int index = query[1];
        const int val = query[2];
        nums[index] = val;
        update(index);
        if (index > 0)
          update(index - 1);
        if (index + 1 < nums.size())
          update(index + 1);
      }

    return ans;
  }

 private:
  vector<int> getPeak(const vector<int>& nums) {
    vector<int> peak(nums.size());
    for (int i = 1; i + 1 < nums.size(); ++i)
      peak[i] = nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    return peak;
  }

  bool isPeak(const vector<int>& nums, int i) {
    return i > 0 && i + 1 < nums.size() && nums[i] > nums[i - 1] &&
           nums[i] > nums[i + 1];
  }
};
