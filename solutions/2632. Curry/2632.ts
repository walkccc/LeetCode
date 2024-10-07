function curry(fn: Function): Function {
  return function curried(...args: any[]): any {
    return args.length >= fn.length
      ? fn.apply(this, args)
      : curried.bind(this, ...args);
  };
}
