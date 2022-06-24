class Solution {
 public:
  string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> count;

    for (const string& a : arr)
      ++count[a];

    for (const string& a : arr)
      if (count[a] == 1 && --k == 0)
        return a;

    return "";
  }
};
