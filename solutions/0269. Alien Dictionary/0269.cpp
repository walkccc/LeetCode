class Solution {
 public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    vector<int> inDegree(26);
    buildGraph(graph, words, inDegree);
    return topology(graph, inDegree);
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
        const char u = first[j];
        const char v = second[j];
        if (u != v) {
          if (!graph[u].count(v)) {
            graph[u].insert(v);
            ++inDegree[v - 'a'];
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

  string topology(unordered_map<char, unordered_set<char>>& graph,
                  vector<int>& inDegree) {
    string s;
    queue<char> q;

    for (const auto& [c, _] : graph)
      if (inDegree[c - 'a'] == 0)
        q.push(c);

    while (!q.empty()) {
      const char u = q.front();
      q.pop();
      s += u;
      for (const char v : graph[u])
        if (--inDegree[v - 'a'] == 0)
          q.push(v);
    }

    // words = ["z", "x", "y", "x"]
    return s.length() == graph.size() ? s : "";
  }
};
