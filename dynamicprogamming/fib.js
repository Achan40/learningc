// Recursive fib
// O(2^n) time complexity
// O(n) space complexity
const fib = (n) => {
    if (n <= 2) return 1;
    return fib(n-1) + fib(n-2);
};

// using memoization
// O(n) time complexity
// O(n) space complexity
// js object, key will be arg to fun, value will be the return value
const fibm = (n, memo = {}) => {
    if (n in memo) return memo[n];
    if (n <= 2) return 1;
    memo[n] = fib(n-1, memo) + fib(n-2, memo);
    return memo[n];
};

// using tabulation
// O(n) time complexity
// O(n) space complexity
const fibt = (n) => {
    const table = Array(n + 1).fill(0);
    table[1] = 1;
    
    // index out of bounds is undefined in javascript
    for (let i = 0; i <= n; i++){
        table[i+1] += table[i];
        table[i+2] += table[i];
    }

    return table[n]
}
console.log(fibt(5))
console.log(fibt(25))
console.log(fibt(35))
