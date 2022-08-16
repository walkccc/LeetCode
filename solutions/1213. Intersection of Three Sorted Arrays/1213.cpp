class Solution {
 public:
  vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                 vector<int>& arr3) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
      const int mini = min({arr1[i], arr2[j], arr3[k]});
      if (arr1[i] == mini && arr2[j] == mini && arr3[k] == mini) {
        ans.push_back(mini);
        ++i;
        ++j;
        ++k;
      } else if (arr1[i] == mini) {
        ++i;
      } else if (arr2[j] == mini) {
        ++j;
      } else {
        ++k;
      }
    }

    return ans;
  }
};
