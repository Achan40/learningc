// cansum, determine if integers in a list can sum to some x
// O(n^m) time complexity
// O(m) space complexity
const cansum = (targetSum, numbers) => {
    if (targetSum === 0) return true;
    if (targetSum < 0) return false;

    for (let num of numbers) {
        const remainder = targetSum - num;
        if (cansum(remainder, numbers) === true) {
            return true;
        };
    }
   return false;
}

// memoized
// O(m*n) time complexity
// O(m) space complexity
const cansumM = (targetSum, numbers, memo={}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return true;
    if (targetSum < 0) return false;

    for (let num of numbers) {
        const remainder = targetSum - num;
        if (cansumM(remainder, numbers, memo) === true) {
            memo[targetSum] = true;
            return true;
        };
    }
    memo[targetSum] = false;
   return false;
}

console.log(cansum(7, [2,3])); // true 
console.log(cansum(7, [5,3,4,7])); // true
console.log(cansum(7, [2,4])) // false
console.log(cansum(8, [2,3,5])) // true
// console.log(cansum(300, [7,14])) // false

console.log(cansumM(7, [2,3])); // true 
console.log(cansumM(7, [5,3,4,7])); // true
console.log(cansumM(7, [2,4])) // false
console.log(cansumM(8, [2,3,5])) // true
// console.log(cansum(300, [7,14])) // false