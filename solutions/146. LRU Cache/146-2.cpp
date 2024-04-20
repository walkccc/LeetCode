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
    if (it == keyToIterator.cend())
      return -1;

    const auto& listIt = it->second;
    // Move it to the front.
    cache.splice(cache.begin(), cache, listIt);
    return listIt->value;
  }

  void put(int key, int value) {
    // There's no capacity issue, so just update the value.
    if (const auto it = keyToIterator.find(key); it != keyToIterator.cend()) {
      const auto& listIt = it->second;
      // Move it to the front.
      cache.splice(cache.begin(), cache, listIt);
      listIt->value = value;
      return;
    }

    // Check the capacity.
    if (cache.size() == capacity) {
      const Node& lastNode = cache.back();
      // That's why we store `key` in `Node`.
      keyToIterator.erase(lastNode.key);
      cache.pop_back();
    }

    cache.emplace_front(key, value);
    keyToIterator[key] = cache.begin();
  }

 private:
  const int capacity;
  list<Node> cache;
  unordered_map<int, list<Node>::iterator> keyToIterator;
};
