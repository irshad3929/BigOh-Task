/**
 * Asserts if two objects are equal by comparing their string representations.
 * @param {Object} actual - The actual object to compare.
 * @param {Object} expect - The expected object to compare against.
 * @param {string} message - The message to display in case of failure.
 * @returns {void} Prints "Passed" if objects are equal, else prints a failure message.
 */
function assertObjectsEqual(actual, expect, message) {
    /**
     * String representation of the actual object.
     * @type {string}
     */
    const actualString = JSON.stringify(actual);   //object into JSON string

    /**
     * String representation of the expected object.
     * @type {string}
     */
    const expectString = JSON.stringify(expect);

    if (actualString === expectString) {
        console.log("Passed");
    } else {
        console.log(`Failed: Expected ${expectString}, but got ${actualString}`);
    }
}

// Test cases
var expected1 = { foo: 5, bar: 6 };
var actual1 = { foo: 5, bar: 6 };
assertObjectsEqual(actual1, expected1, 'detects that two objects are equal');

var expected2 = { foo: 6, bar: 5 };
var actual2 = { foo: 5, bar: 6 };
assertObjectsEqual(actual2, expected2, 'detects that two objects are equal');
