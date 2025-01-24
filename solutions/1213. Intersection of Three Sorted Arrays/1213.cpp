class Solution {
 public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                 vector<int>& arr3) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
      const int mn = min({arr1[i], arr2[j], arr3[k]});
      if (arr1[i] == mn && arr2[j] == mn && arr3[k] == mn) {
        ans.push_back(mn);
        ++i;
        ++j;
        ++k;
      } else if (arr1[i] == mn) {
        ++i;
      } else if (arr2[j] == mn) {
        ++j;
      } else {
        ++k;
      }
    }

    return ans;
  }
};
