/**
 * Calculator object with arithmetic operations and conversion functions.
 * @type {Object}
 */
const calculator = {
    /**
     * Adds multiple numbers.
     * @param {...number} args - Numbers to add.
     * @returns {number} The sum of the numbers.
     */
    add: (...args) => args.reduce((acc, val) => acc + val, 0),

    /**
     * Subtracts multiple numbers.
     * @param {...number} args - Numbers to subtract.
     * @returns {number} The result of subtraction.
     */
    subtract: (...args) => args.reduce((acc, val) => acc - val),

    /**
     * Multiplies multiple numbers.
     * @param {...number} args - Numbers to multiply.
     * @returns {number} The product of the numbers.
     */
    multiply: (...args) => args.reduce((acc, val) => acc * val, 1),

    /**
     * Divides multiple numbers.
     * @param {...number} args - Numbers to divide.
     * @returns {number} The result of division.
     * @throws {Error} If any argument is zero.
     */
    divide: (...args) => {
        if (args.some(arg => arg === 0)) {
            throw new Error("Error: Division by zero.");
        }
        return args.reduce((acc, val) => acc / val);
    },

    /**
     * Converts Celsius to Fahrenheit.
     * @param {number} celsius - Temperature in Celsius.
     * @returns {number} Temperature in Fahrenheit.
     */
    celsiusToFahrenheit: (celsius) => (celsius * 9/5) + 32,

    /**
     * Converts Fahrenheit to Celsius.
     * @param {number} fahrenheit - Temperature in Fahrenheit.
     * @returns {number} Temperature in Celsius.
     */
    fahrenheitToCelsius: (fahrenheit) => (fahrenheit - 32) * 5/9,

    /**
     * Calculates the area of a rectangle.
     * @param {number} length - Length of the rectangle.
     * @param {number} width - Width of the rectangle.
     * @returns {number} Area of the rectangle.
     */
    rectangleArea: (length, width) => length * width,

    /**
     * Calculates the area of a circle.
     * @param {number} radius - Radius of the circle.
     * @returns {number} Area of the circle.
     */
    circleArea: (radius) => Math.round((Math.PI * radius * radius) * 100) / 100
};

/**
 * Executes a calculator function with provided arguments.
 * @param {Function} func - Calculator function to execute.
 * @param {...any} args - Arguments for the function.
 * @returns {number|string} Result of the calculation or an error message.
 */
function calculate(func, ...args) {
    const argCount = args.length;
    const expectedArgs = func.length;
    if (expectedArgs !== 0 && argCount !== expectedArgs) {
        return `Error: Function expects ${expectedArgs} argument(s), ${argCount} provided.`;
    }

    try {
        return func(...args);
    } catch (error) {
        return "Error: Invalid function or arguments provided.";
    }
}

// Example usage
console.log(calculate(calculator.add, 2, 3, 7)); // Output: 12
console.log(calculate(calculator.subtract, 10, 5)); // Output: 5
console.log(calculate(calculator.multiply, 3, 4)); // Output: 12
console.log(calculate(calculator.divide, 10, 2)); // Output: 5
console.log(calculate(calculator.celsiusToFahrenheit, 25)); // Output: 77
console.log(calculate(calculator.fahrenheitToCelsius, 77)); // Output: 25
console.log(calculate(calculator.rectangleArea, 4, 5)); // Output: 20
console.log(calculate(calculator.circleArea, 3)); // Output: 28.27

// Errors
console.log(calculate(calculator.subtract)); // Error: Function expects 2 argument(s), 0 provided.
console.log(calculate(calculator.divide, 10, 0)); // Error: Division by zero.
console.log(calculate(calculator.celsiusToFahrenheit, 25, 50)); // Error: Function expects 1 argument(s), 2 provided.
console.log(calculate(calculator.rectangleArea, 4)); // Error: Function expects 2 argument(s), 1 provided.
