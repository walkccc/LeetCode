class Solution {
 public:
  long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
    return min(noSortCost(arr, brr), sortCost(arr, brr) + k);
  }

 private:
  long long noSortCost(const vector<int>& arr, const vector<int>& brr) {
    long res = 0;
    for (int i = 0; i < arr.size(); ++i)
      res += abs(arr[i] - brr[i]);
    return res;
  }

  long long sortCost(vector<int>& arr, vector<int>& brr) {
    ranges::sort(arr);
    ranges::sort(brr);
    long res = 0;
    for (int i = 0; i < arr.size(); ++i)
      res += abs(arr[i] - brr[i]);
    return res;
  }
};
