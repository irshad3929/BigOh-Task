/**
 * Calculator object with basic arithmetic operations and validation.
 * @type {Object}
 */
const calculator = {
  /**
   * Adds two numbers.
   * @param {number} a - The first number.
   * @param {number} b - The second number.
   * @returns {number|string} The sum of the numbers or an error message if arguments are invalid.
   */
  add: (a, b) =>
    validate(a, b) ? a + b : "Error: Invalid arguments for addition.",

  /**
   * Subtracts two numbers.
   * @param {number} a - The first number (minuend).
   * @param {number} b - The second number (subtrahend).
   * @returns {number|string} The difference between the numbers or an error message if arguments are invalid.
   */
  subtract: (a, b) =>
    validate(a, b) ? a - b : "Error: Invalid arguments for subtraction.",

  /**
   * Multiplies two numbers.
   * @param {number} a - The first number.
   * @param {number} b - The second number.
   * @returns {number|string} The product of the numbers or an error message if arguments are invalid.
   */
  multiply: (a, b) =>
    validate(a, b) ? a * b : "Error: Invalid arguments for multiplication.",
  
  /**
   * Divides two numbers.
   * @param {number} a - The dividend.
   * @param {number} b - The divisor.
   * @returns {number|string} The result of division or an error message if arguments are invalid or division by zero is attempted.
   */
  divide: (a, b) => {
    if (!validate(a, b)) return "Error: Invalid arguments for division.";
    if (b === 0) return "Error: Division by zero.";
    return a / b;
  },
};

/**
* Validates arguments for arithmetic operations.
* @param {...number} args - The arguments to validate.
* @returns {boolean} True if all arguments are numbers, false otherwise.
*/
const validate = (...args) => {
  return args.every((arg) => typeof arg === "number" && !isNaN(arg));
};

// Example usage
console.log(calculator.add(2, 3)); // 5
console.log(calculator.add(2, "3")); // Error: Invalid arguments for addition.
console.log(calculator.subtract(10, 5)); // 5
console.log(calculator.subtract(10)); // Error: Invalid arguments for subtraction.
console.log(calculator.multiply(3, 4)); // 12
console.log(calculator.multiply(3, "4")); // Error: Invalid arguments for multiplication.
console.log(calculator.divide(10, 2)); // 5
console.log(calculator.divide(10, 5)); // 2
console.log(calculator.divide(10, 0)); // Error: Division by zero.
