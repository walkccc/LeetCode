class Solution {
 public:
  vector<int> replaceElements(vector<int>& arr) {
    int maxOfRight = -1;
    for (int i = arr.size() - 1; i >= 0; --i)
      maxOfRight = max(maxOfRight, exchange(arr[i], maxOfRight));
    return arr;
  }
};
