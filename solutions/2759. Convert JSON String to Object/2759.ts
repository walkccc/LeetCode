type JSONValue =
  | null
  | boolean
  | number
  | string
  | JSONValue[]
  | { [key: string]: JSONValue };

class JSONParser {
  private str: string;
  private i: number;

  constructor(str: string) {
    this.str = str;
    this.i = 0;
  }

  public parse(): JSONValue {
    return this.parseValue();
  }

  private parseValue(): JSONValue {
    switch (this.str[this.i]) {
      case '{':
        return this.parseObject();
      case '[':
        return this.parseArray();
      case 't': // true
      case 'f': // false
      case 'n': // null
        return this.parseLiteral();
      case '"':
        return this.parseString();
      default:
        return this.parseNumber();
    }
  }

  private parseObject(): JSONValue {
    ++this.i;

    const ans: JSONValue = {};

    while (this.i < this.str.length && this.str[this.i] !== '}') {
      const key = this.parseString();
      this.expectChar(':');
      const value = this.parseValue();

      ans[key] = value;
      if (this.str[this.i] === ',') {
        ++this.i;
      }
    }

    ++this.i;
    return ans;
  }

  private parseArray(): JSONValue[] {
    ++this.i;

    const ans: JSONValue[] = [];

    while (this.i < this.str.length && this.str[this.i] !== ']') {
      const value = this.parseValue();
      ans.push(value);
      if (this.str[this.i] === ',') {
        ++this.i;
      }
    }

    ++this.i;
    return ans;
  }

  private parseLiteral(): boolean | null {
    if (this.str.startsWith('true', this.i)) {
      this.i += 4;
      return true;
    }
    if (this.str.startsWith('false', this.i)) {
      this.i += 5;
      return false;
    }
    if (this.str.startsWith('null', this.i)) {
      this.i += 4;
      return null;
    }
    throw new Error(`Unexpected token at position ${this.i}`);
  }

  private parseString(): string {
    let ans = '';
    ++this.i;

    while (this.i < this.str.length && this.str[this.i] !== '"') {
      ans += this.str[this.i];
      ++this.i;
    }

    ++this.i;
    return ans;
  }

  private parseNumber(): number {
    let start = this.i;

    if (this.str[this.i] === '-') {
      ++this.i;
    }

    while (this.i < this.str.length && this.isDigit(this.str[this.i])) {
      ++this.i;
    }

    if (this.str[this.i] === '.') {
      ++this.i;
      while (this.i < this.str.length && this.isDigit(this.str[this.i])) {
        ++this.i;
      }
    }

    return Number(this.str.slice(start, this.i));
  }

  private isDigit(n: string): boolean {
    return n >= '0' && n <= '9';
  }

  private expectChar(char: string): void {
    if (this.str[this.i] !== char) {
      throw new Error(`Expected '${char}' at position ${this.i}`);
    }
    ++this.i;
  }
}

function jsonParse(str: string): JSONValue {
  const parser = new JSONParser(str);
  return parser.parse();
}
