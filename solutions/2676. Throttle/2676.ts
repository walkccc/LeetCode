type F = (...args: any[]) => void;

function throttle(fn: F, t: number): F {
  let timeout: ReturnType<typeof setTimeout> | undefined;
  let nextTimeToCallFn = 0;
  return function (...args) {
    const delay = Math.max(0, nextTimeToCallFn - Date.now());
    clearTimeout(timeout);
    timeout = setTimeout(() => {
      fn(...args);
      nextTimeToCallFn = Date.now() + t;
    }, delay);
  };
}
