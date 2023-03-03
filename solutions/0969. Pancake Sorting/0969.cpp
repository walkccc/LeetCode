class Solution {
 public:
  vector<int> pancakeSort(vector<int>& arr) {
    vector<int> ans;

    for (int target = arr.size(); target >= 1; --target) {
      int index = find(arr, target);
      reverse(begin(arr), begin(arr) + index + 1);
      reverse(begin(arr), begin(arr) + target);
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
