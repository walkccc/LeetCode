class Solution {
 public:
  int kIncreasing(vector<int>& arr, int k) {
    int ans = 0;

    for (int i = 0; i < k; ++i) {
      vector<int> arr;
      for (int j = i; j < arr.size(); j += k)
        arr.push_back(arr[j]);
      ans += numReplaced(arr);
    }

    return ans;
  }

 private:
  int numReplaced(const vector<int>& arr) {
    vector<int> tails;
    for (const int a : arr)
      if (tails.empty() || tails.back() <= a)
        tails.push_back(a);
      else
        tails[firstGreater(tails, a)] = a;
    return arr.size() - tails.size();
  }

  int firstGreater(const vector<int>& arr, int target) {
    return ranges::upper_bound(arr, target) - arr.begin();
  }
};
