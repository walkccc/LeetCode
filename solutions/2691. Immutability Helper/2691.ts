type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };
type InputObj = Record<string, JSONValue> | Array<JSONValue>;

type RecursiveHandler = {
  set: (target: any, prop: string, value: any) => boolean;
  get: (target: any, prop: string) => unknown;
};

const isObject = (o: any) => o !== null && typeof o === 'object';

// Access history of properties
class AccessHistory {
  value: JSONValue | null = null;
  props: Map<string, AccessHistory> = new Map();
}

class ImmutableHelper {
  private obj: InputObj;

  constructor(obj: InputObj) {
    this.obj = obj;
  }

  produce(mutator: (obj: InputObj) => void): InputObj {
    // Creates a proxied object to track property access history.
    function createProxiedObj(
      obj: InputObj,
      accessHistory: AccessHistory
    ): InputObj {
      const handler: RecursiveHandler = {
        // 'set' trap intercepts property assignment.
        set(_, prop, value) {
          if (!accessHistory.props.has(prop)) {
            accessHistory.props.set(prop, new AccessHistory());
          }
          accessHistory.props.get(prop)!.value = value;
          return true;
        },
        // 'get' trap intercepts property access.
        get(_, prop) {
          if (accessHistory.value !== null) {
            return accessHistory.value;
          }
          if (!accessHistory.props.has(prop)) {
            accessHistory.props.set(prop, new AccessHistory());
          }
          if (accessHistory.props.get(prop)!.value !== null) {
            return accessHistory.props.get(prop)!.value;
          }
          if (isObject(obj[prop])) {
            // Recursively create a proxed object for object property.
            return createProxiedObj(
              obj[prop] as InputObj,
              accessHistory.props.get(prop)! as AccessHistory
            );
          }
          return obj[prop];
        },
      };
      return new Proxy(obj, handler);
    }

    // Returns true if there are mutated properties in the access history;
    // otherwise, returns false and deletes the unnecessary properties.
    function deleteUnmutatedProps(accessHistory: AccessHistory): boolean {
      if (accessHistory.value !== null) {
        return true;
      }
      let hasMutation = false;
      for (const [prop, childAccessHistory] of [...accessHistory.props]) {
        if (deleteUnmutatedProps(childAccessHistory)) {
          hasMutation = true;
        } else {
          accessHistory.props.delete(prop);
        }
      }
      return hasMutation;
    }

    // Function to transform the original object based on the access history
    function transform(obj: InputObj, accessHistory: AccessHistory): InputObj {
      if (accessHistory.value !== null) {
        return accessHistory.value as InputObj;
      }
      if (accessHistory.props.size === 0) {
        return obj;
      }
      if (!isObject(obj)) {
        return obj;
      }
      let clone = Array.isArray(obj) ? [...obj] : { ...obj };
      for (const [prop, childAccessHistory] of [...accessHistory.props]) {
        clone[prop] = transform(obj[prop] as InputObj, childAccessHistory);
      }
      return clone;
    }

    const accessHistory = new AccessHistory();
    const proxiedObj = createProxiedObj(this.obj, accessHistory);
    // Apply the mutator function on the proxied object. This will also record
    // the property access history in `accessHistory`.
    mutator(proxiedObj);
    // Simplify the access history.
    deleteUnmutatedProps(accessHistory);
    // Transform the original object based on the simplified access history.
    return transform(this.obj, accessHistory);
  }
}
