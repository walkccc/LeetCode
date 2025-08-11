interface Value {
  value: number;
  expiredAt: number;
}

class TimeLimitedCache {
  private cache = new Map<number, Value>();

  set(key: number, value: number, duration: number): boolean {
    const now = Date.now();
    const exists = this.getValue(now, key) !== undefined;
    this.cache.set(key, { value, expiredAt: now + duration });
    return exists;
  }

  get(key: number): number {
    const val = this.getValue(Date.now(), key);
    return val === undefined ? -1 : val.value;
  }

  count(): number {
    const now = Date.now();
    for (const key of this.cache.keys())
      if (this.getValue(now, key) === undefined) {
        this.cache.delete(key);
      }
    return this.cache.size;
  }

  private getValue(now: number, key: number): Value | undefined {
    const val = this.cache.get(key);
    return val && now <= val.expiredAt ? val : undefined;
  }
}
