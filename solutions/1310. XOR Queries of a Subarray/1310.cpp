class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> xors(arr.size() + 1);

    for (int i = 0; i < arr.size(); ++i)
      xors[i + 1] = xors[i] ^ arr[i];

    for (const vector<int>& query : queries) {
      const int left = query[0];
      const int right = query[1];
      ans.push_back(xors[left] ^ xors[right + 1]);
    }

    return ans;
  }
};
