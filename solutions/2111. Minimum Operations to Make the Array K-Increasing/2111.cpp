class Solution {
 public:
  int kIncreasing(vector<int>& arr, int k) {
    int ans = 0;

    for (int i = 0; i < k; ++i) {
      vector<int> A;
      for (int j = i; j < arr.size(); j += k)
        A.push_back(arr[j]);
      ans += numReplaced(A);
    }

    return ans;
  }

 private:
  int numReplaced(const vector<int>& A) {
    vector<int> tails;
    for (const int a : A)
      if (tails.empty() || tails.back() <= a)
        tails.push_back(a);
      else
        tails[firstGreater(tails, a)] = a;
    return A.size() - tails.size();
  }

  int firstGreater(const vector<int>& A, int target) {
    return ranges::upper_bound(A, target) - A.begin();
  }
};
