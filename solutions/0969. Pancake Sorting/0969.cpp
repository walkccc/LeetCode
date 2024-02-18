class Solution {
 public:
  vector<int> pancakeSort(vector<int>& arr) {
    vector<int> ans;

    for (int target = arr.size(); target >= 1; --target) {
      int index = find(arr, target);
      reverse(arr.begin(), arr.begin() + index + 1);
      reverse(arr.begin(), arr.begin() + target);
      ans.push_back(index + 1);
      ans.push_back(target);
    }

    return ans;
  }

 private:
  int find(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i)
      if (arr[i] == target)
        return i;
    throw;
  }
};
