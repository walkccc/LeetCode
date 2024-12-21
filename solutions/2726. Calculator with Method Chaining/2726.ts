class Calculator {
  private cur: number;

  constructor(value: number) {
    this.cur = value;
  }

  add(value: number): Calculator {
    this.cur += value;
    return this;
  }

  subtract(value: number): Calculator {
    this.cur -= value;
    return this;
  }

  multiply(value: number): Calculator {
    this.cur *= value;
    return this;
  }

  divide(value: number): Calculator {
    if (value === 0) throw new Error('Division by zero is not allowed');
    this.cur /= value;
    return this;
  }

  power(value: number): Calculator {
    this.cur **= value;
    return this;
  }

  getResult(): number {
    return this.cur;
  }
}
