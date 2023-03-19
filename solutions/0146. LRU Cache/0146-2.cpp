struct Node {
  int key;
  int value;
  Node(int key, int value) : key(key), value(value) {}
};

class LRUCache {
 public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    const auto it = keyToIterator.find(key);
    if (it == cend(keyToIterator))
      return -1;

    const auto& listIt = it->second;
    // Move it to the front
    cache.splice(begin(cache), cache, listIt);
    return listIt->value;
  }

  void put(int key, int value) {
    // No capacity issue, just update the value
    if (const auto it = keyToIterator.find(key); it != cend(keyToIterator)) {
      const auto& listIt = it->second;
      // Move it to the front
      cache.splice(begin(cache), cache, listIt);
      listIt->value = value;
      return;
    }

    // Check the capacity
    if (cache.size() == capacity) {
      const Node& lastNode = cache.back();
      // that's why we store `key` in `Node`
      keyToIterator.erase(lastNode.key);
      cache.pop_back();
    }

    cache.emplace_front(key, value);
    keyToIterator[key] = begin(cache);
  }

 private:
  const int capacity;
  list<Node> cache;
  unordered_map<int, list<Node>::iterator> keyToIterator;
};
