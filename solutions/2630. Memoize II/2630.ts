type Fn = (...params: any) => any;

function memoize(fn: Fn): Fn {
  const root = new Map(); // trie
  const resultKey = {};
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

    // Check if `resultKey` has been set.
    if (node.has(resultKey)) return node.get(resultKey);
    const result = fn(...params);
    node.set(resultKey, result);
    return result;
  };
}
