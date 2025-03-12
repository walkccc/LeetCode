type Fn = () => Promise<any>;

function delayAll(functions: Fn[], ms: number): Fn[] {
  return functions.map((fn) => {
    return async () => {
      await new Promise((resolve) => setTimeout(resolve, ms));
      try {
        const result = await fn();
        return Promise.resolve(result);
      } catch (error) {
        return Promise.reject(error);
      }
    };
  });
}
