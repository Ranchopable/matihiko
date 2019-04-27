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

Async functions are appropriate when they are going to take a long time to complete, so the calling code isn't blocked. It turns out that it takes a relatively long time to read or write to the filesystem (the hard drive) and the network (e.g. sending an HTTP request). In these cases, it's common to use async functions.

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

`index.js` can be pretty simple:

```javascript
const server = require('./server')
const port = process.env.PORT || 3000

server.listen(port, function () {
  console.log('Server listening on port:', port)
})
```

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

## fs.writeFile
Pointers;
-you might want to "stringify" the data befre writing it
-the second and third arguments in stringify prettify the formatting
-pass in the file you want to write to, the data you want to write, and a callbakc function (for async) in that order

```javascript
const fs = require('fs')

const data = require('./fighters.json')
const fighterWeWantToWrite =  JSON.stringify(data["fighters"][2], null, 2)

fs.writeFile('spinal.txt', fighterWeWantToWrite, (err) => {
    if (err) {
        console.log(err)
    }
})
```

## Handlebars
Because integration with Express.js requires middleware, we'll use the `express-handlebars` npm package instead of the generic Handlebars package. In the following example, assume our data is coming from a module defined in `data.js`. It's `home` property contains an object for the `home` template.

```javascript
const express = require('express')
const hbs = require('express-handlebars')

const data = require('./data')

const server = express()

server.engine('hbs', hbs(
  extname: 'hbs',
  defaultLayout: 'main'
))
server.set('view engine', 'hbs')

server.get('/', function (req, res) {
  res.render('home', data.home)
})
```
Notice how this uses res.render in our route to tell Express to use the Handlebars engine we registered for *.handlebars template files. We also told Express that our views are located in the views folder. Therefore, our / route is applying data.home to the template located at views/home.handlebars.

## server.POST
Never render, always redirect!!

If we use `post`, we must parse the body of the request. To do this, we need an additional module:

```javascript
const express = require('express')
const bodyParser = require('body-parser')

const server = express()
server.use(bodyParser.urlencoded())

...

router.post('/greetings', function (req, res) {
  const greeting = req.body.say
  const recipient = req.body.to
  ...
})
...
```
The body-parser module is Node.js middleware that parses the body of requests and places the parameters as properties on req.body.

## Separate server and routes files
https://github.com/piwakawaka-2019/student-handbook/blob/master/week2/08-express-router.md

## HTTP verbs
-GET: asks for an existing resource
-POST: sends data to create a new resource
-PUT: sends data to update existing resource
-DELETE: asks for an existing resource to be deleted

A `get` request is a read operation, and read operations shouldn't have side effects - meaning, nothing should change as the result of just reading it

If you're sending data to the server to be saved, you expect side effects - the saving of the data. That's fine, you should just be more explicit in your intent - by using `post`.

## Database Migrations
*Structure of a migration file*
There are two functions within your newly created migration file. The first is `exports.up`, which specifies the commands that should be run to make the database change that you'd like to make. Usually you'll be running one or more commands found in the schema builder section of the Knex documentation. These are things like creating database tables, adding or removing a column from a table, changing indexes, etc.

The second function within your migration file is `exports.down`. This functions goal is to do the opposite of what exports.up did. If exports.up created a table, then exports.down will drop that table. If exports.up added a column, then exports.down will remove that column. The reason to include exports.down is so that you can quickly undo a migration should you need to.

http://perkframework.com/v1/guides/database-migrations-knex.html

## Promises
...are useful when you want to run multiple asynchronous functions in a specific order. It is much tidier than nesting callback functions.

Promises have the `.then()` and ``.catch()` methods available to it

## KNEX join
```javascript
knex('dogs')
  .join('breeds', 'dogs.breed_id', '=', 'breeds.id')
  .select('dogs.name', 'breeds.name as breed')
```
"Join the dogs table and the breeds table where the breed id matches. Then return the data in two columns: "name" (the name column in the dogs table) and "breed" (the name column in the breeds table)."

## KNEX
The following katas contain lots of functions using knex;
-knex-to-do-cli
-knex-joins-stories
-knex-relationships-stories

## chmod
...basically allows you to make files executable

## Testing promises
... you *don't* need to use .catch

## React 
I needed to do the following in order to get this repo working properly on my machine https://github.com/piwakawaka-2019/react-minimal

Change package.json from...
```javascript
 "scripts": {
    "start": "node server & webpack --watch"
  },
```
...to...
```javascript
  "scripts": {
    "start": "node server",
    "build": "webpack --watch"
  },
```
...because windows terminal can;t run two commands at once.

I also needed to do some global installs;
`npm install webpack -g`
`npm install webpack-cli -g`

... and then, in separate terminals, run;
`npm build`
`npm start`

React components receive their data in the form of props.

## ES6
...added;
-`let` and `const`
-template strings
-arrow functions

## React
React components se *two* different kinds of data;
-*State* is data created within a React Component and can be changed within a component using this.setState()
-*Props* is data passed into a Component from its parent and should not be changed.

## React router
In React, we can manage client-side routing using React Router.
`npm install react-router-dom`

routing examples: https://github.com/piwakawaka-2019/student-handbook/blob/master/week4/11-react-router.md


## REVISIT THESE NOTES
https://github.com/piwakawaka-2019/student-handbook/blob/master/week4/12-react-forms.md

## Week 5
light on notes - worth revisiting notes on piwakawaka repo

## Enzyme
Enzyme is a JavaScript Testing utility for React that makes it easier to test your React Components' output.

![alt text]('./enzymeExample.png')
