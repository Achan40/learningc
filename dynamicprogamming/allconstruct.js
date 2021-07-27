// function should return all ways to create target, a collection of arrays
// m = target.length
// n = wordBank.length
// O(n^m * m) time 
// O(m^2) space
const allConstruct = (target, wordBank) => {

}

// memoized
// O(n * m^2) time complexity
// O(m^2) space complexity
const allConstructM = (target, wordBank) => {

}

console.log(allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // 1
console.log(allConstruct("skateboard", ["bo", "rd", "ate", "t", "ska", "sk","boar"])); // 0
console.log(allConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o","t"])); // 4
//console.log(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeeeeee", "eeeeeeeee", "eeeeeeeeeeee"])); // 0


console.log(allConstructM("abcdef", ["ab", "abc", "cd", "def", "abcd"])); // 1
console.log(allConstructM("skateboard", ["bo", "rd", "ate", "t", "ska", "sk","boar"])); // 0
console.log(allConstructM("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o","t"])); // 4
console.log(allConstructM("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeeeeee", "eeeeeeeee", "eeeeeeeeeeee"])); // 0
