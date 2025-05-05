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
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    const int n = nums1.size();
    long ans = 0;
    unordered_map<int, int> numToIndex;
    vector<int> arr;
    // leftSmaller[i] := the number of arr[j] < arr[i], where 0 <= j < i
    vector<int> leftSmaller(n);
    // rightLarger[i] := the number of arr[j] > arr[i], where i < j < n
    vector<int> rightLarger(n);
    FenwickTree tree1(n);  // Calculates `leftSmaller`.
    FenwickTree tree2(n);  // Calculates `rightLarger`.

    for (int i = 0; i < n; ++i)
      numToIndex[nums1[i]] = i;

    // Remap each number in `nums2` to the according index in `nums1` as `arr`.
    // So the problem is to find the number of increasing tripets in `arr`.
    for (const int num : nums2)
      arr.push_back(numToIndex[num]);

    for (int i = 0; i < n; ++i) {
      leftSmaller[i] = tree1.get(arr[i]);
      tree1.add(arr[i] + 1, 1);
    }

    for (int i = n - 1; i >= 0; --i) {
      rightLarger[i] = tree2.get(n) - tree2.get(arr[i]);
      tree2.add(arr[i] + 1, 1);
    }

    for (int i = 0; i < n; ++i)
      ans += static_cast<long>(leftSmaller[i]) * rightLarger[i];

    return ans;
  }
};
