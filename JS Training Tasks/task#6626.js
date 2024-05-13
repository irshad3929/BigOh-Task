/**
 * Counts the number of combinations of elements in the array that sum up to the target.
 * @param {number[]} arr - The array of integers.
 * @param {number} sum - The current sum.
 * @param {number} index - The current index in the array.
 * @param {number} target - The target sum to achieve.
 * @returns {number} The number of combinations that sum up to the target.
 */

function countSumCombinations(arr, sum, index, target) {
    // Base case
    if (sum === target) {
        return 1;
    }

    if (index >= arr.length) {
        return 0;
    }

    if (index === arr.length - 1) {
        if (sum + arr[index] === target || sum - arr[index] === target) {
            return 1;
        }
        return 0;
    }

    // Recursive cases: Explore both possibilities (including/notpick the current element)
    let includePlus = countSumCombinations(arr, sum + arr[index], index + 1, target); 
    let includeMinus = countSumCombinations(arr, sum - arr[index], index + 1, target);
    let notpick = countSumCombinations(arr, sum, index + 1, target);

    return includePlus + includeMinus + notpick;
}

// Example usage
const arr = [-1, 9, 8, -3, 4];
const target = 5;
const sum = 0;

const result = countSumCombinations(arr, sum, 0, target);
console.log(result);
