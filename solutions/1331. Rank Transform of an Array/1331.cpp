class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr(arr);
    unordered_map<int, int> rank;

    sort(begin(sortedArr), end(sortedArr));

    for (const int a : sortedArr)
      if (!rank.count(a))
        rank[a] = rank.size() + 1;

    for (int& a : arr)
      a = rank[a];

    return arr;
  }
};
