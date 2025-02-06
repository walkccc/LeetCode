type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type Obj = JSONValue | Record<string, JSONValue> | Array<JSONValue>;

function deepFilter(obj: Obj, fn: (x: JSONValue) => boolean): Obj | undefined {
  if (Array.isArray(obj)) {
    const filteredArr = obj
      .map((item) => deepFilter(item, fn))
      .filter((item) => item !== undefined);
    return filteredArr.length > 0 ? filteredArr : undefined;
  }

  if (typeof obj === 'object' && obj !== null) {
    const filteredObj: Record<string, JSONValue> = {};
    for (const key in obj) {
      const filteredValue = deepFilter(obj[key], fn);
      if (filteredValue !== undefined) {
        filteredObj[key] = filteredValue;
      }
    }
    return Object.keys(filteredObj).length > 0 ? filteredObj : undefined;
  }

  return fn(obj) ? obj : undefined;
}
