## NPM 
Download and install Node https://nodejs.org/en/download/ 

npm init -y
npm install colors

npm install jest
npm install supertest
    "test": "jest --watchAll --noStackTrace --color(s?)"
    npm test
    filename.test.js
    npx jest --watch --noStackTrace

npm install express
npm install --save-dev nodemon (auto refreshes server)
    npm start
    "start": "node index.js" (index being the page that runs the server)


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
  expect(2+2 === 4).toBeTruthy()
  expect(3*3).toBe(9)

  const testArray = ['dave', 'sharon']
  testArray.push('flora')

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
