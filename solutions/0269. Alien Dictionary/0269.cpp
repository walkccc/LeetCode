class Solution {
 public:
  string alienOrder(vector<string>& words) {
    vector<int> inDegree(26);
    unordered_map<char, unordered_set<char>> graph;

    buildGraph(graph, words, inDegree);

    return bfs(graph, inDegree);
  }

 private:
  void buildGraph(unordered_map<char, unordered_set<char>>& graph,
                  const vector<string>& words, vector<int>& inDegree) {
    // create node for each character in each word
    for (const string& word : words)
      for (const char c : word)
        if (!graph.count(c))
          graph[c] = unordered_set<char>();

    for (int i = 1; i < words.size(); ++i) {
      const string& first = words[i - 1];
      const string& second = words[i];
      const int length = min(first.length(), second.length());
      for (int j = 0; j < length; ++j) {
        const char out = first[j];
        const char in = second[j];
        if (out != in) {
          if (!graph[out].count(in)) {
            graph[out].insert(in);
            ++inDegree[in - 'a'];
          }
          break;  // later characters' order are meaningless
        }
        // first = "ab", second = "a" -> invalid
        if (j == length - 1 && first.length() > second.length()) {
          graph.clear();
          return;
        }
      }
    }
  }

  string bfs(unordered_map<char, unordered_set<char>>& graph,
             vector<int>& inDegree) {
    string s;
    queue<char> q;

    for (const auto& [c, _] : graph)
      if (inDegree[c - 'a'] == 0)
        q.push(c);

    while (!q.empty()) {
      const char out = q.front();
      q.pop();
      s += out;
      for (const char in : graph[out])
        if (--inDegree[in - 'a'] == 0)
          q.push(in);
    }

    // words = ["z", "x", "y", "x"]
    return s.length() == graph.size() ? s : "";
  }
};
