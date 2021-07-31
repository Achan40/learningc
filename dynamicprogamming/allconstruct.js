// function should return all ways to create target, a collection of arrays
// m = target.length
// n = wordBank.length
// O(n^m) time 
// O(m) space
const allConstruct = (target, wordBank) => {
    if (target === '') return [[]];

    const result = [];

    for (let word of wordBank) {
        if (target.indexOf(word) === 0){
            const suffix = target.slice(word.length);
            const suffixWays = allConstruct(suffix, wordBank);
            const targetWays = suffixWays.map(way => [word, ...way]);
            result.push(...targetWays);
        }
    }
    return result;
}

// memoized doesn't do too much here
const allConstructM = (target, wordBank, memo = {}) => {
    if (target in memo) return memo[target];
    if (target === '') return [[]];

    const result = [];

    for (let word of wordBank) {
        if (target.indexOf(word) === 0){
            const suffix = target.slice(word.length);
            const suffixWays = allConstruct(suffix, wordBank, memo);
            const targetWays = suffixWays.map(way => [word, ...way]);
            result.push(...targetWays);
        }
    }
    memo[target] = result;
    return result;
}

// tabulation
// O(n^m) time
// O(n^m) size
const allConstructT = (target, wordBank) => {
    const table = Array(target.length+1).fill().map(() => []);
    table[0] = [[]];

    for (let i = 0; i <= target.length; i++){
        for (let word of wordBank) {
            if (target.slice(i, i + word.length) === word) {
                const newCombinations = table[i].map(subArray => [...subArray, word]);
                table[i + word.length].push(...newCombinations);
            }
        }
    }
    return table[target.length];
}


// console.log(allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); 
// console.log(allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk","boar"])); 
// console.log(allConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o","t"])); 
//console.log(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeeeeee", "eeeeeeeee", "eeeeeeeeeeee"])); 


// console.log(allConstructM("abcdef", ["ab", "abc", "cd", "def", "abcd"])); 
// console.log(allConstructM("skateboard", ["bo", "rd", "ate", "t", "ska", "sk","boar"])); 
// console.log(allConstructM("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o","t"])); 
// console.log(allConstructM("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeeeeee", "eeeeeeeee", "eeeeeeeeeeee"])); 


console.log(allConstructT("abcdef", ["ab", "abc", "cd", "def", "abcd"])); 
console.log(allConstructT("skateboard", ["bo", "rd", "ate", "t", "ska", "sk","boar"])); 
console.log(allConstructT("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o","t"])); 
