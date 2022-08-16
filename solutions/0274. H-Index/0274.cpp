class Solution {
 public:
  int hIndex(vector<int>& citations) {
    const int n = citations.size();
    int accumulate = 0;
    vector<int> count(n + 1);

    for (const int citation : citations)
      ++count[min(citation, n)];

    // to find the largeset h-index, loop from back to front
    // i is the candidate h-index
    for (int i = n; i >= 0; --i) {
      accumulate += count[i];
      if (accumulate >= i)
        return i;
    }

    throw;
  }
};
