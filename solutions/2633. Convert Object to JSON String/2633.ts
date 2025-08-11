type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };

function jsonStringify(object: JSONValue): string {
  if (object === null) {
    return 'null';
  }
  if (typeof object === 'boolean' || typeof object === 'number') {
    return String(object);
  }
  if (typeof object === 'string') {
    return `"${object}"`;
  }
  if (Array.isArray(object)) {
    const elems = object.map((elem) => jsonStringify(elem));
    return `[${elems.join(',')}]`;
  }
  // typeof object === 'object'
  const pairs = Object.keys(object).map(
    (key) => `"${key}":${jsonStringify(object[key])}`
  );
  return `{${pairs.join(',')}}`;
}
