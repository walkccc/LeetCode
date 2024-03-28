class Solution {
 public:
  int edgeScore(vector<int>& edges) {
    vector<long long> scores(edges.size());
    for (int i = 0; i < edges.size(); ++i)
      scores[edges[i]] += i;
    return ranges::max_element(scores) - scores.begin();
  }
};
