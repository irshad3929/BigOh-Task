/**
 * Converts JSON data into grouped data based on the 'batch_id' field.
 * @param {Array<Object>} jsonData - The JSON data to be converted.
 * @returns {Array<Object>} An array of objects containing grouped data.
 */
function convertData(jsonData) {
  /**
   * Grouped data object.
   * @type {Object.<string, Array<Object>>}
   */
  const groupedData = {};

  for (const item of jsonData) {
    const { batch_id, ...rest } = item;
    if (!groupedData[batch_id]) {
      groupedData[batch_id] = [];
    }
    groupedData[batch_id].push(rest);
  }

  /**
   * Resulting array of grouped data objects.
   * @type {Array<Object>}
   */
  const result = Object.keys(groupedData).map((key) => ({
    [key]: groupedData[key],
  }));
  return result;
}

// Source data
const jsonData = [
  {
    batch_id: "123",
    name: "Tony",
    contact: "9872276210",
  },
  {
    batch_id: "231",
    name: "Steve",
    contact: "7876543210",
  },
  {
    batch_id: "123",
    name: "Bruce",
    contact: "6776543210",
  },
  {
    batch_id: "321",
    name: "Clint",
    contact: "8954643210",
  },
  {
    batch_id: "123",
    name: "Peter",
    contact: "7666543210",
  },
  {
    batch_id: "231",
    name: "Phil",
    contact: "8896543210",
  },
  {
    batch_id: "321",
    name: "Nick",
    contact: "9876521210",
  },
];

const convertedData = convertData(jsonData);

// Print all objects
console.log(JSON.stringify(convertedData, null, 2));
