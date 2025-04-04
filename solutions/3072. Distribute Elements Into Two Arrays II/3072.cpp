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
  vector<int> resultArray(vector<int>& nums) {
    vector<int> arr1;
    vector<int> arr2;
    const unordered_map<int, int> ranks = getRanks(nums);
    FenwickTree tree1(ranks.size());
    FenwickTree tree2(ranks.size());

    add(nums[0], arr1, tree1, ranks);
    add(nums[1], arr2, tree2, ranks);

    for (int i = 2; i < nums.size(); ++i) {
      const int greaterCount1 = arr1.size() - tree1.get(ranks.at(nums[i]));
      const int greaterCount2 = arr2.size() - tree2.get(ranks.at(nums[i]));
      if (greaterCount1 > greaterCount2)
        add(nums[i], arr1, tree1, ranks);
      else if (greaterCount1 < greaterCount2)
        add(nums[i], arr2, tree2, ranks);
      else if (arr1.size() > arr2.size())
        add(nums[i], arr2, tree2, ranks);
      else
        add(nums[i], arr1, tree1, ranks);
    }

    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
  }

 private:
  unordered_map<int, int> getRanks(const vector<int>& nums) {
    unordered_map<int, int> ranks;
    set<int> sorted(nums.begin(), nums.end());
    int rank = 0;
    for (const int num : sorted)
      ranks[num] = ++rank;
    return ranks;
  }

  void add(int num, vector<int>& arr, FenwickTree& tree,
           const unordered_map<int, int>& ranks) {
    arr.push_back(num);
    tree.add(ranks.at(num), 1);
  };
};
