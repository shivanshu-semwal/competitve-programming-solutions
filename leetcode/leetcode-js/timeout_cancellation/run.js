/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function (fn, args, t) {
    const timeoutId = setTimeout(() => {
        console.log(fn.apply(null, args))
    }, t);

    const cancleFn = () => {
        console.log("stoping function");
        clearTimeout(timeoutId);
    }

    return cancleFn;
};

console.log("calling cancellable");
var a = cancellable((a, b) => a + b, [1, 2], 1000 * 2);
console.log("cancellable called")

console.log("cancelling the running function...")
setTimeout(() => a(), 1000);
