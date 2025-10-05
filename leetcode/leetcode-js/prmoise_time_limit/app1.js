/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function (fn, t) {

    return async function (...args) {
        return new Promise((resolve, reject) => {

            let timerId;
            fn(...args)
                .then(result => resolve(result))
                .catch(error => reject(error))
                .finally(() => clearTimeout(timerId));

            timerId = setTimeout(() => {
                reject('Time Limit Exceeded');
            }, t);
        })
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */

const fn = async (n) => {
    await new Promise((res) => {
        setTimeout(res, 100);
    });
    return n * n;
}

const args = [5];
const timeout = 150;

const limited = timeLimit(fn, timeout);
limited(args)
    .then(console.log)
    .catch(console.log);