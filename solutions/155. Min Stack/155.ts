interface Item {
    min: number;
    val: number;
}

class MinStack {
    items: Item[];

    constructor() {
        this.items = [];
    }

    private last(): Item | undefined {
        return this.items[this.items.length - 1];
    }

    push(val: number): void {
        const last = this.last();
        this.items.push({
            val,
            min: !last || val < last.min ? val : last.min,
        });
    }

    pop(): void {
        this.items.pop();
    }

    top(): number | undefined {
        return this.last()?.val;
    }

    getMin(): number | undefined {
        return this.last()?.min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
