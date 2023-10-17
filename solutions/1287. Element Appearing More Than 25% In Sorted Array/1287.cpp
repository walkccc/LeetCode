class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {
    const int n = arr.size();
    const int quarter = n / 4;

    for (int i = 0; i < n - quarter; ++i)
      if (arr[i] == arr[i + quarter])
        return arr[i];

    throw;
  }
};
