/**
 * Flattens a nested object into a single-level object with dot-separated keys.
 * @param {Object} jsonData - The JSON data to be flattened.
 * @param {string} parent - The parent key for the initial level (default is empty string).
 * @returns {Object} A single-level object with dot-separated keys.
 */
function flattenObject(jsonData, parent) {
  /**
   * Final flattened object.
   * @type {Object}
   */
  const finalObj = {};

  /**
   * Recursively generates a flat object from nested object.
   * @param {Object} jsonData - The JSON data to be flattened.
   * @param {string} parent - The parent key for the current level.
   */
  const generateFlatObj = (jsonData, parent) => {
    for (let key in jsonData) {
      const newParent = parent + key;
      const value = jsonData[key];
      if (typeof value === "object") {
        generateFlatObj(value, newParent + "."); // recursive call for nested object
      } else {
        finalObj[newParent] = value;
      }
    }
  };

  generateFlatObj(jsonData, parent);
  return finalObj;
}

// Sample JSON data
const jsonData = {
  "keyOne": "value One",
  "keyTwo": "value Two",
  "keyThree": "value Three",
  "keyFour": {
    "keyA": true,
    "keyB": false,
    "keyC": {
      "keyCOne": "key C one value",
      "keyCTwo": "key C two value",
      "keyCThree": 1234
      // "keyCFour" : [7,8,9] //own test case
    }
  }
};

// Flatten the object
const ans = flattenObject(jsonData, "");

console.log(JSON.stringify(ans, null, 2));
