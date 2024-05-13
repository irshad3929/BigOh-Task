/**
 * A calculator object with various mathematical functions.
 * @type {Object}
 */
const calculator = {
  /**
   * Calculates the square of a number.
   * @param {number} num - The number to square.
   * @returns {number|string} The square of the number or an error message if the number is negative.
   */
  square: (num) => {
    if (num < 0) return "Error: Negative number";
    return num * num;
  },

  /**
   * Calculates the square root of a number.
   * @param {number} num - The number to find the square root of.
   * @returns {number|string} The square root of the number or an error message if the number is negative.
   */
  squareRoot: (num) => {
    if (num < 0) return "Error: Negative number";
    return Math.sqrt(num);
  },

  /**
   * Calculates the base-10 logarithm of a number.
   * @param {number} num - The number to calculate the logarithm of.
   * @returns {number|string} The base-10 logarithm of the number or an error message if the number is less than or equal to 0.
   */
  log: (num) => {
    if (num <= 0) return "Error: Invalid input";
    return Math.log10(num);
  },

  /**
   * Calculates the natural logarithm of a number.
   * @param {number} num - The number to calculate the natural logarithm of.
   * @returns {number|string} The natural logarithm of the number or an error message if the number is less than or equal to 0.
   */
  naturalLog: (num) => {
    if (num <= 0) return "Error: Invalid input";
    return Math.log(num);
  },

  /**
   * Calculates the sine of an angle.
   * @param {number} angle - The angle in radians.
   * @returns {number} The sine of the angle.
   */
  sin: (angle) => Math.sin(angle),

  /**
   * Calculates the cosine of an angle.
   * @param {number} angle - The angle in radians.
   * @returns {number} The cosine of the angle.
   */
  cos: (angle) => Math.cos(angle),

  /**
   * Calculates the tangent of an angle.
   * @param {number} angle - The angle in radians.
   * @returns {number} The tangent of the angle.
   */
  tan: (angle) => Math.tan(angle),

  /**
   * Calculates the result of raising a base to an exponent.
   * @param {number} base - The base number.
   * @param {number} exponent - The exponent to raise the base to.
   * @returns {number} The result of raising the base to the exponent.
   */
  power: (base, exponent) => Math.pow(base, exponent),

  /**
   * Calculates the area of a circle given its radius.
   * @param {number} radius - The radius of the circle.
   * @returns {number|string} The area of the circle or an error message if the radius is negative.
   */
  circleArea: (radius) => {
    if (radius < 0) return "Error: Negative radius";
    return Math.PI * radius * radius;
  },
};

// Example usage
console.log(calculator.square(5));
console.log(calculator.squareRoot(25));
console.log(calculator.log(100));
console.log(calculator.naturalLog(10));
console.log(calculator.sin(Math.PI / 2));
console.log(calculator.cos(0));
console.log(calculator.tan(Math.PI / 4));
console.log(calculator.power(2, 3));
console.log(calculator.circleArea(5));

console.log(calculator.square(-5)); // Test case for negative number
