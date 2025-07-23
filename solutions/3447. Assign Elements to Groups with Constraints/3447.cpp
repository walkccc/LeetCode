class Solution {
 public:
  vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
    vector<int> ans;
    unordered_map<int, int> elementToMinIndex;

    for (int i = 0; i < elements.size(); ++i)
      if (!elementToMinIndex.contains(elements[i]))
        elementToMinIndex[elements[i]] = i;

    for (const int num : groups)
      ans.push_back(getMinIndex(num, elementToMinIndex));

    return ans;
  }

 private:
  int getMinIndex(int num, const unordered_map<int, int>& elementToMinIndex) {
    int res = INT_MAX;
    for (int i = 1; i * i <= num; ++i) {
      if (num % i != 0)
        continue;
      if (elementToMinIndex.contains(i))
        res = min(res, elementToMinIndex.at(i));
      if (num / i != i && elementToMinIndex.contains(num / i))
        res = min(res, elementToMinIndex.at(num / i));
    }
    return res == INT_MAX ? -1 : res;
  }
};
