type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };

function createObject(
  keysArr: JSONValue[],
  valuesArr: JSONValue[]
): Record<string, JSONValue> {
  let ans: Record<string, JSONValue> = {};
  keysArr.forEach((key, index) => {
    let stringKey: string = typeof key === 'string' ? key : String(key);
    if (!(stringKey in ans)) {
      ans[stringKey] = valuesArr[index];
    }
  });
  return ans;
}
