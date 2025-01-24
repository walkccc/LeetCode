type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type Value =
  | undefined
  | null
  | boolean
  | number
  | string
  | Value[]
  | { [key: string]: Value };

type Obj1 = Record<string, Value> | Array<Value>;
type Obj2 = Record<string, JSONValue> | Array<JSONValue>;

function undefinedToNull(obj: Obj1): Obj2 {
  if (obj === undefined || obj === null) {
    return null;
  }
  if (
    typeof obj === 'boolean' ||
    typeof obj === 'number' ||
    typeof obj === 'string'
  ) {
    return obj;
  }
  for (const key in obj) {
    obj[key] = undefinedToNull(obj[key]);
  }
  return obj;
}
