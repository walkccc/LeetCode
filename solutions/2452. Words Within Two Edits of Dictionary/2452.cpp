class Solution {
 public:
  vector<string> twoEditWords(vector<string>& queries,
                              vector<string>& dictionary) {
    vector<string> ans;

    for (const string& query : queries)
      for (const string& word : dictionary)
        if (inner_product(query.begin(), query.end(), word.begin(), 0, plus<>(),
                          not_equal_to<char>()) < 3) {
          ans.push_back(q);
          break;
        }

    return ans;
  }
};
