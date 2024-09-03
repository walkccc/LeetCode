type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function invertObject(obj: Obj): Record<string, JSONValue> {
  const ans: Record<string, JSONValue> = {};

  for (const [key, value] of Object.entries(obj)) {
    const valueKey = value as string;
    if (ans.hasOwnProperty(valueKey)) {
      const curr = ans[valueKey];
      if (!Array.isArray(curr)) {
        ans[valueKey] = [curr];
      }
      (ans[valueKey] as JSONValue[]).push(key);
    } else {
      ans[valueKey] = key;
    }
  }

  return ans;
}
