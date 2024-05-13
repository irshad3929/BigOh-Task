/**
 * Performs basic arithmetic operations: addition, subtraction, multiplication, division, or modulo.
 * @param {string} op - The operation to perform ('add', 'sub', 'mul', 'div', or 'mod').
 * @param {...number} numbers - The numbers on which the operation will be performed.
 * @returns {void} Result of the operation is logged to the console.
 */
function calculator(op, ...numbers) {
  let ans = 0;

  switch (op) {
    case 'add':
      ans = numbers.reduce((acc, curr) => acc + curr, 0);
      break;

    case 'sub':
      ans = numbers.reduce((acc, curr) => acc - curr);
      break;

    case 'mul':
      ans = numbers.reduce((acc, curr) => acc * curr, 1);
      break;

    case 'div':
      ans = numbers.reduce((acc, curr) => acc / curr);
      break;

    case 'mod':
      ans = numbers.reduce((acc, curr) => acc % curr);
      break;

    default:
      console.log("Invalid Operation");
      return;

  }
  console.log(`Result of ${op} `, ans);
}

// Example usage:
calculator('add', 1, 5, 3, 6, 7);
calculator('sub', 6, 3);
calculator('mul', 5, 6, 2);
calculator('div', 10, 2, 2);
calculator('mod', 13, 3);
