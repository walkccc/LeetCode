class Solution {
 public:
  int findLucky(vector<int>& arr) {
    vector<int> count(arr.size() + 1);

    for (const int a : arr)
      if (a <= arr.size())
        ++count[a];

    for (int i = arr.size(); i >= 1; --i)
      if (count[i] == i)
        return i;

    return -1;
  }
};
