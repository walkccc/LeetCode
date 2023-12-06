type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function chunk(arr: Obj[], size: number): Obj[][] {
  const ans: Obj[][] = [];
  for (let i = 0; i < arr.length; i += size) {
    ans.push(arr.slice(i, i + size));
  }
  return ans;
}
