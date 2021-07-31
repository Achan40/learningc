// can we construct a target by concatenating element of the wordBank array (we can reuse)
// m = target.length
// n = wordBank.length
// O(n^m * m)
// O(m^2)
const canConstruct = (target, wordBank) => {
    if (target === '') {
        return true;
    }

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const suffix = target.slice(word.length);
            if (canConstruct(suffix, wordBank) === true) {
                return true;
            }
        }
    }

    return false;
}

// memoized
// O(n * m^2) time complexity
// O(m^2) space complexity
const canConstructM = (target, wordBank, memo={}) => {
    if (target in memo) return memo[target];
    if (target === '') {
        return true;
    }

    for (let word of wordBank) {
        if (target.indexOf(word) === 0) {
            const suffix = target.slice(word.length);
            if (canConstructM(suffix, wordBank, memo) === true) {
                memo[target] = true;
                return true;
            }
        }
    }

    memo[target] = false;
    return false;
}

// tabulation
// O(m*n*m)
// O(m)
const canConstructT = (target, wordBank) => {
    const table = Array(target.length + 1).fill(false);
    table[0] = true;

    for (let i = 0; i < target.length; i++){
        if (table[i] === true) {
            for (word of wordBank){
                // if the word matches the character at position i
                if (target.slice(i,i + word.length) === word) {
                    table[i + word.length] = true;
                }
            }
        }
    }
    
    return table[target.length];
}

// console.log(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // true
// console.log(canConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk","boar"])); // false
// console.log(canConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o","t"])); // true
// // console.log(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeeeeee", "eeeeeeeee", "eeeeeeeeeeee"])); // false

// console.log(canConstructM("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // true
// console.log(canConstructM("skateboard", ["bo", "rd", "ate", "t", "ska", "sk","boar"])); // false
// console.log(canConstructM("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o","t"])); // true
// console.log(canConstructM("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeeeeee", "eeeeeeeee", "eeeeeeeeeeee"])); // false

console.log(canConstructT("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // true
console.log(canConstructT("skateboard", ["bo", "rd", "ate", "t", "ska", "sk","boar"])); // false
console.log(canConstructT("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o","t"])); // true
console.log(canConstructT("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeeeeee", "eeeeeeeee", "eeeeeeeeeeee"])); // false