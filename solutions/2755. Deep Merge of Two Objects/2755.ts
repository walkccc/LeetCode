type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };

function deepMerge(obj1: JSONValue, obj2: JSONValue): JSONValue {
  if (typeof obj1 !== 'object' || typeof obj2 !== 'object') {
    return obj2;
  }
  if (obj1 === null || obj2 === null) {
    return obj2;
  }
  if (Array.isArray(obj1) !== Array.isArray(obj2)) {
    return obj2;
  }
  const ans = obj1;
  for (const key in obj2) {
    if (key in ans) {
      ans[key] = deepMerge(ans[key], obj2[key]);
    } else {
      ans[key] = obj2[key];
    }
  }
  return ans;
}
