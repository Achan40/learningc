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

console.log(fibm(25))
