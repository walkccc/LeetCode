class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr(arr);
    unordered_map<int, int> rank;

    ranges::sort(sortedArr);

    for (const int a : sortedArr)
      if (!rank.contains(a))
        rank[a] = rank.size() + 1;

    for (int& a : arr)
      a = rank[a];

    return arr;
  }
};
