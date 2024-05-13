/**
 * Represents user information.
 * @typedef {Object} UserInfo
 * @property {string} name - The name of the user.
 * @property {number} age - The age of the user.
 * @property {Object} social - Social media account information.
 * @property {Object} social.facebook - Facebook account information.
 * @property {string} social.facebook.acc1 - First Facebook account email.
 * @property {string} social.facebook.acc2 - Second Facebook account email.
 * @property {Object} social.twitter - Twitter account information.
 * @property {Object} social.twitter.free - Free tier Twitter account information.
 * @property {string} social.twitter.free.acc1 - Free tier Twitter account email.
 * @property {Object} social.twitter.paid - Paid tier Twitter account information.
 * @property {string} social.twitter.paid.acc2 - Paid tier Twitter account email.
 */

/**
 * Creates a deep copy of an object.
 * @param {Object} obj - The object to copy.
 * @returns {Object} The deep copy of the object.
 */

function makeDeepCopy(obj) {
  if (typeof obj !== "object" || obj == null) {
    return obj;  // Base case: return primitive values as is
  }

  // Initialize a new object or array for the copied value
  var copiedval = Array.isArray(obj) ? [] : {};

  // Iterate through the keys of the object
  var keys = Object.keys(obj);
  for (var i = 0; i < keys.length; i++) {
    // Recursively copy each property
    copiedval[keys[i]] = makeDeepCopy(obj[keys[i]]);
  }
  
  return copiedval;
}

// Example usage
const userInfo = {
  name: "irshad",
  age: 27,
  social: {
    facebook: {
      acc1: "some1@gmail.com",
      acc2: "some2@gmail.com",
    },
    twitter: {
      free: {
        acc1: "twit1@gmail.com",
      },
      paid: {
        acc2: "twit2@gmail.com",
      },
    },
  },
};

const copy = makeDeepCopy(userInfo);
console.log(copy);

// Modify original object
userInfo.social.facebook.acc1 = "changed";

// Print original and copied objects
console.log(userInfo);
console.log(copy);


//we create a deep copy

//method 2

//  var obj2 = JSON.parse(JSON.stringify(obj));

//   obj2.social.facebook.acc1 = "changed";

//      console.log(obj);
//      console.log(obj2);

