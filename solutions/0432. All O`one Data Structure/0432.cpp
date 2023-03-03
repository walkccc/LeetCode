class AllOne {
 public:
  void inc(string key) {
    const auto it = keyToIterator.find(key);

    // doesn't find the key
    if (it == cend(keyToIterator)) {
      if (l.empty() || l.front().value > 1)
        l.push_front({1, {key}});
      else
        l.front().keys.insert(key);
      keyToIterator[key] = begin(l);
      return;
    }

    const auto lit = it->second;  // List iterator
    auto nit = next(lit);         // Next iterator

    if (nit == end(l) || nit->value > lit->value + 1)
      nit = l.insert(nit, {lit->value + 1, {key}});
    else  // Nit->value == lit->value + 1
      nit->keys.insert(key);
    keyToIterator[key] = nit;  // Reset the mapping

    // Remove the key in keys set
    lit->keys.erase(key);
    if (lit->keys.empty())
      l.erase(lit);
  }

  void dec(string key) {
    const auto it = keyToIterator.find(key);

    // doens't find the key
    if (it == cend(keyToIterator))
      return;

    const auto lit = it->second;  // List iterator

    if (lit->value == 1) {  // No need to find prev iterator in this case
      keyToIterator.erase(key);
    } else {
      auto pit = prev(lit);  // Prev iterator

      if (lit == begin(l) || pit->value < lit->value - 1)
        pit = l.insert(lit, {lit->value - 1, {key}});
      else  // Pit->value == lit-value - 1
        pit->keys.insert(key);
      keyToIterator[key] = pit;  // Reset the mapping
    }

    // Remove the key in keys set
    lit->keys.erase(key);
    if (lit->keys.empty())
      l.erase(lit);
  }

  string getMaxKey() {
    return l.empty() ? "" : *cbegin(l.back().keys);
  }

  string getMinKey() {
    return l.empty() ? "" : *cbegin(l.front().keys);
  }

 private:
  struct Node {
    int value;
    unordered_set<string> keys;
  };

  list<Node> l;
  unordered_map<string, list<Node>::iterator> keyToIterator;
};
