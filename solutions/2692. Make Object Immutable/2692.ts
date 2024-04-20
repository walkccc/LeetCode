type RecursiveHandler = {
  set: <T extends object>(target: T, prop: string, value: any) => boolean;
  get: <T extends object>(target: T, prop: string) => any;
  apply: <T extends Function>(target: T, thisArg: any, argArray?: any) => any;
};

function makeImmutable<T extends object | Function>(obj: T): T {
  // a set of mutating array methods
  const methods = new Set([
    'pop',
    'push',
    'shift',
    'unshift',
    'splice',
    'sort',
    'reverse',
  ]);

  const handler: RecursiveHandler = {
    // 'set' trap prevents modifications of the object properties.
    set(target, prop, _) {
      throw Array.isArray(target)
        ? `Error Modifying Index: ${String(prop)}`
        : `Error Modifying: ${String(prop)}`;
    },
    // 'get' trap returns object properties or creates new proxies for nested
    // objects or functions
    get(target, prop) {
      // If the property is 'prototype', null, or not an object/function, return
      // it directly. We exclude 'prototype' to avoid potential issues with
      // inheritance Objects and functions are wrapped in a new proxy to
      // preserve immutability at all depths.
      const key = prop as keyof typeof target;
      return prop === 'prototype' ||
        target[key] === null ||
        (typeof target[key] !== 'object' && typeof target[key] !== 'function')
        ? target[key]
        : new Proxy(target[key], this);
    },
    // 'apply' trap prevents call of mutating methods and apply function calls.
    apply(target, thisArg, argumentsList) {
      if (methods.has((target as any).name))
        throw `Error Calling Method: ${(target as any).name}`;
      return target.apply(thisArg, argumentsList);
    },
  };

  return new Proxy(obj, handler) as T;
}
