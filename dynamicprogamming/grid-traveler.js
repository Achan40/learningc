// number of paths that can be taken to go from top left corner of m,n grid to bottom right corner
// can only move down and to the right
// recursive implementation
// O(2^n+m) time complexity
// O(n+m) space complexity
const gridTraveler = (m, n) => {
    if (m === 1 && n === 1) return 1;
    if (m === 0 || n === 0) return 0;
    return gridTraveler(m - 1, n) + gridTraveler(m, n - 1);
}

// console.log(gridTraveler(1,1));
// console.log(gridTraveler(2,3));
// console.log(gridTraveler(3,2));
// console.log(gridTraveler(3,3));
// console.log(gridTraveler(18,18));

// using memonization
// O(m*n) time complexity 
// O(n+m) space complexity
const gridTravelerm = (m, n, memo = {}) => {
    // are the args in the memo
    const key = m + ',' + n;

    if (key in memo) return memo[key]
    if (m === 1 && n === 1) return 1;
    if (m === 0 || n === 0) return 0;
    memo[key] = gridTravelerm(m - 1, n, memo) + gridTravelerm(m, n - 1, memo);
    return memo[key];
}
// console.log(gridTravelerm(1,1));
// console.log(gridTravelerm(2,3));
// console.log(gridTravelerm(3,2));
// console.log(gridTravelerm(3,3));
// console.log(gridTravelerm(18,18));

// using tabulation
// O(m*n) time complexity 
// O(n+m) space complexity
const gridTravelerT = (m, n) => {
    // create an array w subarrays, fill w zeros
    const table = Array(m + 1).fill().map(() => Array(n+1).fill(0));
    table[1][1] = 1;

    for(let i = 0; i <= m; i++){
        for(let j = 0; j <= n; j++){
            const current = table[i][j];
            if (j+1 <= n) table[i][j+1] += current;
            if (i+1 <= m) table[i + 1][j] += current;
        }
    }

    return table[m][n]
}
console.log(gridTravelerT(3,2));
console.log(gridTravelerT(3,5));
console.log(gridTravelerT(3,7));
console.log(gridTravelerT(18,18));