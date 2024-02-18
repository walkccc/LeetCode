class AllOne {
 public:
  void inc(string key) {
    const auto it = keyToIterator.find(key);

    // Doesn't find the key.
    if (it == keyToIterator.cend()) {
      if (l.empty() || l.front().value > 1)
        l.push_front({1, {key}});
      else
        l.front().keys.insert(key);
      keyToIterator[key] = l.begin();
      return;
    }

    const auto lit = it->second;  // list iterator
    auto nit = next(lit);         // next iterator

    if (nit == l.end() || nit->value > lit->value + 1)
      nit = l.insert(nit, {lit->value + 1, {key}});
    else  // nit->value == lit->value + 1
      nit->keys.insert(key);
    keyToIterator[key] = nit;  // Reset the mapping.

    // Remove the key in the keys set.
    lit->keys.erase(key);
    if (lit->keys.empty())
      l.erase(lit);
  }

  void dec(string key) {
    const auto it = keyToIterator.find(key);

    // Doens't find the key.
    if (it == keyToIterator.cend())
      return;

    const auto lit = it->second;  // list iterator

    if (lit->value == 1) {
      // no need to find the previous iterator in this case.
      keyToIterator.erase(key);
    } else {
      auto pit = prev(lit);  // the previous iterator

      if (lit == l.begin() || pit->value < lit->value - 1)
        pit = l.insert(lit, {lit->value - 1, {key}});
      else  // pit->value == lit-value - 1
        pit->keys.insert(key);
      keyToIterator[key] = pit;  // Reset the mapping.
    }

    // Remove the key in the keys set.
    lit->keys.erase(key);
    if (lit->keys.empty())
      l.erase(lit);
  }

  string getMaxKey() {
    return l.empty() ? "" : *l.back(.cbegin().keys);
  }

  string getMinKey() {
    return l.empty() ? "" : *l.front(.cbegin().keys);
  }

 private:
  struct Node {
    int value;
    unordered_set<string> keys;
  };

  list<Node> l;
  unordered_map<string, list<Node>::iterator> keyToIterator;
};
