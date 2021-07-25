// return array containing any combination of elements that add up to the targetSum
// O(n^m * m) time complexity
// O(m) space complexity
const howSum = (targetSum, numbers) => {
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;

    for (let num of numbers) {
        const remainder = targetSum - num;
        const remainderResult = howSum(remainder, numbers);
        if (remainderResult !== null) {
            return [...remainderResult, num];
        }
    }

    return null;
}

// Using memoization
// O(n*m^2)
// O(m*m)
const howSumM = (targetSum, numbers, memo={}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;

    for (let num of numbers) {
        const remainder = targetSum - num;
        const remainderResult = howSumM(remainder, numbers, memo);
        if (remainderResult !== null) {
            memo[targetSum] = [...remainderResult, num];
            return memo[targetSum];
        }
    }

    memo[targetSum] = null;
    return null;
}

console.log(howSum(7, [2,3])); // [3,2,2]
console.log(howSum(7, [5,3,4,7])); // [4,3]
console.log(howSum(7, [2,4])) // null
console.log(howSum(8, [2,3,5])) // [2,2,2,2]
// console.log(howSum(300, [7,14])) // null

console.log(howSumM(7, [5,3,4,7])); // [4,3]
console.log(howSumM(7, [2,4])) // null
console.log(howSumM(8, [2,3,5])) // [2,2,2,2]
console.log(howSumM(300, [7,14])) // null