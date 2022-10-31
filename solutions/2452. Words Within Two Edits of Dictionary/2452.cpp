class Solution {
 public:
  vector<string> twoEditWords(vector<string>& queries,
                              vector<string>& dictionary) {
    vector<string> ans;

    for (const string& q : queries)
      for (const string& word : dictionary)
        if (inner_product(begin(q), end(q), begin(word), 0, plus<>(),
                          not_equal_to<char>()) < 3) {
          ans.push_back(q);
          break;
        }

    return ans;
  }
};
