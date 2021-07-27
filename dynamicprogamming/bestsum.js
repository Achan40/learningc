// function returns array conatining the shortest combination of numbers that add up to exactly the targetSum
// m = targetsum
// n = numbers.length
// O(n^m * m) time complexity
// O(m^2) space complexity
const bestSum = (targetSum, numbers) => {
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;
    
    let shortestCombination = null;

    for (let num of numbers) {
        const remainder = targetSum - num;
        const remainderCombination = bestSum(remainder, numbers);
        if (remainderCombination !== null) {
            const combination = [...remainderCombination, num];
            // if the combination is shorter than the current shortest, update it
            if (shortestCombination === null ||combination.length < shortestCombination.length) {
                shortestCombination = combination;
            }
        }
    }

    return shortestCombination;
}

// memoized
// O(m^2 * n) time complexity
// O(m^2)
const bestSumM = (targetSum, numbers, memo={}) => {
    if (targetSum in memo) return memo[targetSum];
    if (targetSum === 0) return [];
    if (targetSum < 0) return null;
    
    let shortestCombination = null;

    for (let num of numbers) {
        const remainder = targetSum - num;
        const remainderCombination = bestSumM(remainder, numbers, memo);
        if (remainderCombination !== null) {
            const combination = [...remainderCombination, num];
            // if the combination is shorter than the current shortest, update it
            if (shortestCombination === null ||combination.length < shortestCombination.length) {
                shortestCombination = combination;
            }
        }
    }

    memo[targetSum] = shortestCombination;
    return shortestCombination;
}


console.log(bestSum(7, [5,3,4,7]));
console.log(bestSum(8, [2,3,5]));
console.log(bestSum(8, [1,4,5]));
// console.log(bestSum(100, [1,2,3,25]));

console.log(bestSumM(7, [5,3,4,7]));
console.log(bestSumM(8, [2,3,5]));
console.log(bestSumM(8, [1,4,5]));
console.log(bestSumM(100, [1,2,3,25]));
