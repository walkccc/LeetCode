class Solution {
 public:
  vector<long long> getDistances(vector<int>& arr) {
    const int n = arr.size();
    vector<long long> ans(n);
    vector<long> prefix(n);
    vector<long> suffix(n);
    unordered_map<int, vector<int>> numToIndices;

    for (int i = 0; i < n; ++i)
      numToIndices[arr[i]].push_back(i);

    for (const auto& [_, indices] : numToIndices) {
      for (int i = 1; i < indices.size(); ++i) {
        const int currIndex = indices[i];
        const int prevIndex = indices[i - 1];
        prefix[currIndex] += prefix[prevIndex] + i * (currIndex - prevIndex);
      }
      for (int i = indices.size() - 2; i >= 0; --i) {
        const int currIndex = indices[i];
        const int prevIndex = indices[i + 1];
        suffix[currIndex] += suffix[prevIndex] +
                             (indices.size() - i - 1) * (prevIndex - currIndex);
      }
    }

    for (int i = 0; i < n; ++i)
      ans[i] = prefix[i] + suffix[i];

    return ans;
  }
};
