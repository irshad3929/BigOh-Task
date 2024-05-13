/**
 * Calculates the minimum number of bracket reversals needed to balance an expression.
 * @param {string} expression - The expression to check.
 * @returns {number} The minimum number of reversals needed, or -1 if the expression cannot be balanced.
 */

function minReversals(expression) {
    if (expression.length % 2 !== 0) return -1; // Odd-length expressions cannot be balanced

    let open = 0; // Count of opening brackets
    let close = 0; // Count of closing brackets

    // Count the number of opening and closing brackets
    for (let i = 0; i < expression.length; i++) {
        if (expression[i] === '{') {
            open++;
        } else {
            if (open === 0) {
                close++; // Increase count of unbalanced closing brackets
            } else {
                open--; // Match the opening bracket
            }
        }
    }

    // If both open and close counts are odd, it's not possible to balance the expression
    if ((open + close) % 2 !== 0) return -1;

    // Calculate the number of reversals required
    return Math.ceil(open / 2) + Math.ceil(close / 2);
}

// Example usage:
console.log(minReversals("{{{")); // Output: -1
console.log(minReversals("{{{{}}")); // Output: 1
