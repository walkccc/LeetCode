class Solution {
 public:
  vector<int> elementInNums(vector<int>& nums, vector<vector<int>>& queries) {
    vector<int> ans;

    for (const vector<int>& query : queries) {
      const int time = query[0];
      const int index = query[1];
      ans.push_back(f(nums, time % (2 * nums.size()), index));
    }

    return ans;
  }

 private:
  int f(const vector<int>& A, int time, int index) {
    const int n = A.size();
    if (time < n) {  // [0, 1, 2] -> [1, 2] -> [2]
      index += time;
      return index >= n ? -1 : A[index];
    } else {  // [] -> [0] -> [0, 1]
      return index >= time - n ? -1 : A[index];
    }
  }
};
