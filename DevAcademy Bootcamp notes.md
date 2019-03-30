## NPM 
Download and install Node https://nodejs.org/en/download/ 

npm init -y
npm install colors

npm install jest
npm install supertest --save-dev
    "test": "jest --watchAll --noStackTrace --color(s?)"
    npm test
    filename.test.js
    npx jest --watch --noStackTrace

npm install express
npm install --save-dev nodemon (auto refreshes server)
    npm start
    "start": "node index.js" (index being the page that runs the server)

use npx for "one-off" commands that aren't in a script

## Git
$ git checkout --track origin/newsletter
Branch newsletter set up to track remote branch newsletter from origin.
Switched to a new branch 'newsletter'

## JavaScript
The lines of code below allow the secon file to call myFunction
```javascript
function myFunction () {
    console.log("This is my function")
}

module.exports = myFunction
```
```javascript
var myFunction = require('./myFunction.js')
```

Jest testing structure;
```javascript
test("test some basic js", () => {
  //arrange
  expect(2+2 === 4).toBeTruthy()
  expect(3*3).toBe(9)
  
  //assert
  const testArray = ['dave', 'sharon']
  testArray.push('flora')

  //act
  expect(testArray).toEqual(['dave', 'sharon', 'flora'])
})
```


## Miscellaneous
1. Ugly works > Pretty doesn't work
2. Pretty works > Ugly works
3. Don't stay ugly longer than one to three days!


## Testing
Pillars of testing'
RED // GREEN // REFACTOR

The flow;
-Create a branch for your new feature
-Write a test and watch it fail
-Implement the functionality and watch your test pass
-Review the codebase and refactor as necessary
-Review your changes using git diff
-Stage and commit your changes (and issue a pull request or merge as appropriate)
-Rinse and repeat ;)


## Express
online tutorial https://www.youtube.com/watch?v=9TSBKO59u0Y

Example of a simple web server;
```javascript
// server.js
const express = require('express')

const port = 3000
const server = express()

server.get('/', (req, res) => {
  res.send('<h1>Hello world</h1>')
})

server.listen(port, () => {
  console.log('The server is listening on port', port)
})
```

To see this in action, start the server by running node server in your terminal, and visit http://localhost:3000 in your browser. You can also `run curl http://localhost:3000` in another terminal tab or window.

Below is a line of middleware.
```javascript
server.use(express.static('public'))
```
## Asynchronous server testing
Below is a template/sample for asynchronous server tests
```javascript
test('Includes correct artist name in correct area of artworks page', done => {
  superTest(server).get('/artworks/1').end((err, res) => {

    const expected = 'Ben';
    const $ = cheerio.load(res.text);

    const actual = $('.artist').text();

    expect(actual).toContain(expected);

    done()
  })
})
```

## Debug Node in DevTools
https://medium.com/@paul_irish/debugging-node-js-nightlies-with-chrome-devtools-7c4a1b95ae27

## Node fs
EVERY function in the fs module has a synchronous *and* asynchronous form.
fs (filesystem) is a core module of node.

Sync vs. async;
https://www.youtube.com/watch?v=GdBgP71CSow

## Testing asyncshronous code with jest
It's common in JavaScript for code to run asynchronously. When you have code that runs asynchronously, Jest needs to know when the code it is testing has completed, before it can move on to another test. Jest has several ways to handle this.

### Callbacks
The most common asynchronous pattern is callbacks.

For example, let's say that you have a fetchData(callback) function that fetches some data and calls callback(data) when it is complete. You want to test that this returned data is just the string 'peanut butter'.

By default, Jest tests complete once they reach the end of their execution. That means this test will not work as intended:

// Don't do this!
``` javascript 
test('the data is peanut butter', () => {
  function callback(data) {
    expect(data).toBe('peanut butter');
  }

  fetchData(callback);
});
```

The problem is that the test will complete as soon as fetchData completes, before ever calling the callback.

There is an alternate form of test that fixes this. Instead of putting the test in a function with an empty argument, use a single argument called done. Jest will wait until the done callback is called before finishing the test.

```javascript
test('the data is peanut butter', done => {
  function callback(data) {
    expect(data).toBe('peanut butter');
    done();
  }

  fetchData(callback);
});
```

If done() is never called, the test will fail, which is what you want to happen.

## HBS
Save your partials in a partials folder, and call them like this
```handlebars
{{>apple}}
```

Save things like headers, footers etc. in a layouts folder.

## Express
Create a file each for;
-index
-server
-routes

## Supertest
Example supertest;
```javascript
const request = require('supertest')
 
const server = require('../server.js')

test('/example returns WOMBAT', done => {
  // Arrange
  const expected = 'WOMBAT'

  // Act
  request(server)
    .get('/example')
    .end((err, res) => {
      // Assert
      expect(res.text).toBe(expected)
      done()
    })
})
```
Note how the function `done` is passed as an argument and called at the end of the test. This is and example of asynchronous testing.

You can also send data to supertest;
```javascript
require(server).post('/form').send({name=test}).end( done=> {...)
```

