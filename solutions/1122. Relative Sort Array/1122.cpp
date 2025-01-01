class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> ans;
    vector<int> count(1001);

    for (int a : arr1)
      ++count[a];

    for (int a : arr2)
      while (count[a]-- > 0)
        ans.push_back(a);

    for (int num = 0; num < 1001; ++num)
      while (count[num]-- > 0)
        ans.push_back(num);

    return ans;
  }
};
