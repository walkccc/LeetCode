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
    vector<int> tail;
    for (const int a : A)
      if (tail.empty() || tail.back() <= a)
        tail.push_back(a);
      else
        tail[firstGreater(tail, a)] = a;
    return A.size() - tail.size();
  }

  int firstGreater(const vector<int>& tail, int target) {
    return upper_bound(begin(tail), end(tail), target) - begin(tail);
  }
};
