struct Node {
  int count;
  unordered_set<string> keys;
};

class AllOne {
 public:
  void inc(string key) {
    if (const auto it = keyToIterator.find(key); it == keyToIterator.end())
      addNewKey(key);
    else
      incrementExistingKey(it, key);
  }

  void dec(string key) {
    const auto it = keyToIterator.find(key);
    // It is guaranteed that key exists in the data structure before the
    // decrement.
    decrementExistingKey(it, key);
  }

  string getMaxKey() {
    return nodeList.empty() ? "" : *nodeList.back().keys.begin();
  }

  string getMinKey() {
    return nodeList.empty() ? "" : *nodeList.front().keys.begin();
  }

 private:
  list<Node> nodeList;  // list of nodes sorted by count
  unordered_map<string, list<Node>::iterator> keyToIterator;

  // Adds a new node with count 1.
  void addNewKey(const string& key) {
    if (nodeList.empty() || nodeList.front().count > 1)
      nodeList.push_front({1, {key}});
    else  // nodeList.front().count == 1
      nodeList.front().keys.insert(key);
    keyToIterator[key] = nodeList.begin();
  }

  // Increments the count of the key by 1.
  void incrementExistingKey(
      unordered_map<string, list<Node>::iterator>::iterator it,
      const string& key) {
    const auto listIt = it->second;

    auto nextIt = next(listIt);
    const int newCount = listIt->count + 1;
    if (nextIt == nodeList.end() || nextIt->count > newCount)
      nextIt = nodeList.insert(nextIt, {newCount, {key}});
    else  // Node with count + 1 exists.
      nextIt->keys.insert(key);

    keyToIterator[key] = nextIt;
    remove(listIt, key);
  }

  // Decrements the count of the key by 1.
  void decrementExistingKey(
      unordered_map<string, list<Node>::iterator>::iterator it,
      const string& key) {
    const auto listIt = it->second;
    if (listIt->count == 1) {
      keyToIterator.erase(it);
      remove(listIt, key);
      return;
    }

    auto prevIt = prev(listIt);
    const int newCount = listIt->count - 1;
    if (listIt == nodeList.begin() || prevIt->count < newCount)
      prevIt = nodeList.insert(listIt, {newCount, {key}});
    else  // Node with count - 1 exists.
      prevIt->keys.insert(key);

    keyToIterator[key] = prevIt;
    remove(listIt, key);
  }

  // Removes the key from the node list.
  void remove(list<Node>::iterator it, const string& key) {
    it->keys.erase(key);
    if (it->keys.empty())
      nodeList.erase(it);
  }
};
