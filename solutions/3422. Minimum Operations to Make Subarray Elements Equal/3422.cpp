struct SumMultiset {
  multiset<int> nums;
  long sum = 0;

  void insert(int val) {
    nums.insert(val);
    sum += val;
  }

  void erase(int val) {
    nums.erase(nums.find(val));
    sum -= val;
  }
};

class MedianTracker {
 public:
  MedianTracker(int k) : k(k) {}

  void add(int val) {
    below.insert(val);
    balance();
  }

  void remove(int val) {
    if (const auto it = below.nums.find(val); it != below.nums.cend())
      below.erase(val);
    else
      above.erase(val);
  }

  long getCost() const {
    return above.sum - below.sum - (k % 2 == 1 ? *above.nums.begin() : 0);
  }

 private:
  SumMultiset below;
  SumMultiset above;
  const int k;

  void balance() {
    // Move excessive numbers from `below` to `above`.
    while (below.nums.size() > k / 2) {
      const int mx = *prev(below.nums.end());
      below.erase(mx);
      above.insert(mx);
    }

    // Balance `below` and `above`.
    while (!above.nums.empty()) {
      const int mx = *prev(below.nums.end());
      const int mn = *above.nums.begin();
      if (mx <= mn)
        break;
      below.erase(mx);
      above.erase(mn);
      below.insert(mn);
      above.insert(mx);
    }
  }
};

class Solution {
 public:
  long long minOperations(vector<int>& nums, int k) {
    MedianTracker tracker(k);

    for (int i = 0; i < k; ++i)
      tracker.add(nums[i]);

    long ans = tracker.getCost();

    for (int i = k; i < nums.size(); ++i) {
      tracker.remove(nums[i - k]);
      tracker.add(nums[i]);
      ans = min(ans, tracker.getCost());
    }

    return ans;
  }
};
