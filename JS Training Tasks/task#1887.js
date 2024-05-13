/**
 * Generates a query string from an object and appends it to a URL.
 * @param {Object} object - The object containing key-value pairs for the query parameters.
 * @param {string} url - The base URL to which the query string will be appended.
 * @returns {string} The URL with the generated query string.
 */
function generateQueryString(object, url) {
  let queryString = "";

  for (let key in object) {
    if (object.hasOwnProperty(key)) {
      queryString += `${key}=${object[key]}&`;
    }
  }

  queryString = queryString.slice(0, -1); // Remove the last '&'

  return `${url}?${queryString}`;
}

// Example usage:
const obj = {
  keyOne: "value One",
  keyTwo: "value Two",
  keyThree: "value Three",
};

const url = "https://localhost:400";

console.log(generateQueryString(obj, url));
