type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function compactObject(obj: Obj): Obj {
  return dfs(obj) as Obj;
}

function dfs(value: JSONValue): JSONValue {
  if (value === null) {
    return null;
  }
  if (Array.isArray(value)) {
    return value.filter(Boolean).map(dfs);
  }
  if (typeof value === 'object') {
    for (const key of Object.keys(value)) {
      if (Boolean(value[key])) {
        value[key] = dfs(value[key]);
      } else {
        delete value[key];
      }
    }
  }
  return value;
}
