/**
 * Calculator object containing basic arithmetic operations.
 * @type {Object}
 */
const calculator = {
  /**
   * Adds two numbers.
   * @param {number} a - The first number.
   * @param {number} b - The second number.
   * @returns {number} The sum of the numbers.
   */
  "+": (a, b) => a + b,

  /**
   * Subtracts two numbers.
   * @param {number} a - The first number (minuend).
   * @param {number} b - The second number (subtrahend).
   * @returns {number} The difference between the numbers.
   */
  "-": (a, b) => a - b,

  /**
   * Multiplies two numbers.
   * @param {number} a - The first number.
   * @param {number} b - The second number.
   * @returns {number} The product of the numbers.
   */
  "*": (a, b) => a * b,

  /**
   * Divides two numbers.
   * @param {number} a - The dividend.
   * @param {number} b - The divisor.
   * @returns {number|undefined} The result of division or undefined if the divisor is zero.
   */
  "/": (a, b) =>
    b == 0 ? console.log("denominator should be greater than zero ") : a / b,

  /**
   * Returns the remainder of dividing two numbers.
   * @param {number} a - The dividend.
   * @param {number} b - The divisor.
   * @returns {number|undefined} The remainder of the division or undefined if the divisor is zero.
   */
  "%": (a, b) =>
    b == 0 ? console.log("denominator should be greater than zero ") : a % b,
};

/**
 * Performs a calculation using the specified operator and operands.
 * @param {string} operator - The arithmetic operator ('+', '-', '*', '/', '%').
 * @param {number} num1 - The first operand.
 * @param {number} num2 - The second operand.
 * @returns {void} Prints the result of the calculation or an error message.
 */
function calculate(operator, num1, num2) {
  if (!Object.keys(calculator).includes(operator)) {
    console.log("Operator not supported");
    return;
  }

  if (typeof num1 !== "number" || typeof num2 !== "number") {
    console.log("Invalid input. Both operands must be numbers.");
    return;
  }

  const operation = calculator[operator];
  const result = operation(num1, num2);
  console.log(`Result of ${num1} ${operator} ${num2} is ${result}`);
}

// Test our code
calculate("+", 5, 3);
calculate("-", 10, 4);
calculate("*", 6, 2);
calculate("/", 15, 0);
calculate("%", 10, 2);
calculate("+", "5", 3);
calculate("&", 3, 8);
