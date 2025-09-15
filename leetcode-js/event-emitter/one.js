class EventEmitter {

    constructor() {
        this.subscribers = new Map();
    }

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {

        // create empty array for eventName
        if (!this.subscribers.has(eventName)) {
            this.subscribers.set(eventName, []);
        }
        let len = this.subscribers.get(eventName).length;
        this.subscribers.get(eventName).push({
            fn: callback,
            state: {
                active: true,
                unsubscribe: function(){
                    this.active = false;
                }
            }
        });

        return this.subscribers.get(eventName)[len].state;
    }

    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {
        let ans = [];
        if (!this.subscribers.has(eventName)) return [];
        for (const item of this.subscribers.get(eventName)) {
            console.log(item, ...args);
            if (item.state.active) {
                ans.push(item.fn(...args))
            }
        }

        return ans;
    }
}


const emitter = new EventEmitter();
const sub1 = emitter.subscribe("firstEvent", x => x + 1);
const sub2 = emitter.subscribe("firstEvent", x => x + 2);
sub1.unsubscribe(); // undefined
console.log(emitter.emit("firstEvent", [5])); // [7]