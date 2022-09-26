class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(Node* root) {
    if (!root)
      return "";

    string s;
    queue<Node*> q{{root}};
    s += to_string(root->val) + " ";

    while (!q.empty())
      for (int sz = q.size(); sz > 0; --sz) {
        Node* node = q.front();
        q.pop();
        if (node->children.empty()) {
          s += "n";
        } else {
          for (Node* child : node->children) {
            q.push(child);
            s += to_string(child->val) + "#";
          }
        }
        s += " ";
      }

    return s;
  }

  // Decodes your encoded data to tree.
  Node* deserialize(string data) {
    if (data.empty())
      return nullptr;

    istringstream iss(data);
    string word;
    iss >> word;
    Node* root = new Node(stoi(word));
    queue<Node*> q{{root}};

    while (iss >> word) {
      Node* parent = q.front();
      q.pop();
      vector<string> kids = getKids(word);
      vector<Node*> children;
      for (const string& kid : kids) {
        if (kid == "n")
          continue;
        Node* child = new Node(stoi(kid));
        children.push_back(child);
        q.push(child);
      }
      parent->children = children;
    }

    return root;
  }

 private:
  vector<string> getKids(const string& word) {
    vector<string> kids;
    for (int i = 0, j = 0; j < word.length(); ++j)
      if (word[j] == '#') {
        kids.push_back(word.substr(i, j - i));
        i = j + 1;
      }
    return kids;
  }
};
