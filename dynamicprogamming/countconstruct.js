// how many times can we construct a target by concatenating element of the wordBank array (we can reuse)
// m = target.length
// n = wordBank.length
// O(n^m * m) time 
// O(m^2) space
const countConstruct = (target, wordBank) => {
    if (target === '') {
        return 1;
    }

    let totalCount = 0;

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const numWaysForRest = countConstruct(target.slice(word.length), wordBank);
            totalCount += numWaysForRest;
        }
    }

    return totalCount;
}

// memoized
// O(n * m^2) time complexity
// O(m^2) space complexity
const countConstructM = (target, wordBank, memo ={}) => {
    if (target in memo) return memo[target];
    if (target === '') {
        return 1;
    }

    let totalCount = 0;

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const numWaysForRest = countConstructM(target.slice(word.length), wordBank, memo);
            totalCount += numWaysForRest;
        }
    }

    memo[target] = totalCount;
    return totalCount;
}

console.log(countConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // 1
console.log(countConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk","boar"])); // 0
console.log(countConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o","t"])); // 4
//console.log(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeeeeee", "eeeeeeeee", "eeeeeeeeeeee"])); // 0


console.log(countConstructM("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // 1
console.log(countConstructM("skateboard", ["bo", "rd", "ate", "t", "ska", "sk","boar"])); // 0
console.log(countConstructM("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o","t"])); // 4
console.log(countConstructM("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeeeeee", "eeeeeeeee", "eeeeeeeeeeee"])); // 0
