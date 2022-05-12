struct TrieNode {
  unordered_map<string, TrieNode*> children;
  bool deleted = false;
};

class Solution {
 public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
    vector<vector<string>> ans;
    vector<string> path;
    unordered_map<string, vector<TrieNode*>> subtreeToNodes;

    sort(begin(paths), end(paths));

    for (const auto& path : paths) {
      TrieNode* node = &root;
      for (const auto& s : path) {
        if (!node->children.count(s))
          node->children[s] = new TrieNode;
        node = node->children[s];
      }
    }

    buildSubtreeToRoots(&root, subtreeToNodes);

    for (const auto& [_, nodes] : subtreeToNodes)
      if (nodes.size() > 1)
        for (const auto& node : nodes)
          node->deleted = true;

    constructPath(&root, path, ans);
    return ans;
  }

 private:
  TrieNode root;

  string buildSubtreeToRoots(
      TrieNode* node,
      unordered_map<string, vector<TrieNode*>>& subtreeToNodes) {
    string subtree = "(";
    for (const auto& [s, child] : node->children)
      subtree += s + buildSubtreeToRoots(child, subtreeToNodes);
    subtree += ")";
    if (subtree != "()")
      subtreeToNodes[subtree].push_back(node);
    return subtree;
  }

  void constructPath(TrieNode* node, vector<string>& path,
                     vector<vector<string>>& ans) {
    for (const auto& [s, child] : node->children)
      if (!child->deleted) {
        path.push_back(s);
        constructPath(child, path, ans);
        path.pop_back();
      }
    if (!path.empty())
      ans.push_back(path);
  }
};
