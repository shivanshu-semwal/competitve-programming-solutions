    var TimeLimitedCache = function () {
        this.cache = {}
    };

    /** 
     * @param {number} key
     * @param {number} value
     * @param {number} duration time until expiration in ms
     * @return {boolean} if un-expired key already existed
     */
    TimeLimitedCache.prototype.set = function (key, val, duration) {
        let flag = false;
        if (this.cache[key]) {
            clearTimeout(this.cache[key].timeId);
            flag = true;
        }
        const timer = setTimeout(() => {
            this.cache[key].timeId = undefined;
        }, duration);
        this.cache[key] = { value: val, timeId: timer };
        return flag;
    };

    /** 
     * @param {number} key
     * @return {number} value associated with key
     */
    TimeLimitedCache.prototype.get = function (key) {
        if (this.cache[key] && this.cache[key].timeId !== undefined) {
            return this.cache[key].value;
        }
        return -1;
    };

    /** 
     * @return {number} count of non-expired keys
     */
    TimeLimitedCache.prototype.count = function () {
        return Object.keys(this.cache).filter(
            key => this.cache[key].timeId !== undefined
        ).length
    };

    /**
     * const timeLimitedCache = new TimeLimitedCache()
     * timeLimitedCache.set(1, 42, 1000); // false
     * timeLimitedCache.get(1) // 42
     * timeLimitedCache.count() // 1
     */