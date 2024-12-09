type Fn = (...params: any) => any;

function memoize(fn: Fn): Fn {
  const root = new Map(); // trie
  const ansKey = {};
  return function (...params) {
    let node = root;
    for (const param of params) {
      let next = node.get(param);
      if (next === undefined) {
        next = new Map();
        node.set(param, next);
      }
      node = next;
    }

    // Check if `ansKey` has been set.
    if (node.has(ansKey)) return node.get(ansKey);
    const ans = fn(...params);
    node.set(ansKey, ans);
    return ans;
  };
}
