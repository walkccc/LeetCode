type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function deepFilter(obj: Obj, fn: Function): Obj | undefined {
  const dfs = (data: any): any => {
    if (Array.isArray(data)) {
      const res = data.map(dfs).filter((item: any) => item !== undefined);
      return res.length > 0 ? res : undefined;
    }
    if (typeof data === 'object' && data !== null) {
      const res: Record<string, any> = {};
      for (const key in data) {
        if (data.hasOwnProperty(key)) {
          const filteredValue = dfs(data[key]);
          if (filteredValue !== undefined) {
            res[key] = filteredValue;
          }
        }
      }
      return Object.keys(res).length > 0 ? res : undefined;
    }
    return fn(data) ? data : undefined;
  };

  return dfs(obj);
}
