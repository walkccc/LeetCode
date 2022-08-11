class Solution {
 public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> ans;
    vector<int> xors(arr.size() + 1);

    for (int i = 0; i < arr.size(); ++i)
      xors[i + 1] ^= xors[i] ^ arr[i];

    for (const auto& q : queries)
      ans.push_back(xors[q[0]] ^ xors[q[1] + 1]);

    return ans;
  }
};
