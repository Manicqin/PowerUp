const addon3                    = require('../03_NAPI/index.js');
//const count_words_occurrence    = require('count-words-occurrence').default;
const count_words               = require('count-words');

let fs = require('fs');
const filename = 'WarAndPeace.txt';
const data =fs.readFileSync(filename, 'utf8');

console.time("NAPI");
addon3.count_words(data);
console.timeEnd("NAPI");

//count-words-occurrence takes over 10 minutes ...
// console.time("count_words_occurrence");
// count_words_occurrence(data);
// console.timeEnd("count_words_occurrence");

console.time("count_words");
count_words(data);
console.timeEnd("count_words");

const Runner = require('benchr');
const runner = new Runner({    delay       : 0,
    minTime     : 0,
    maxTime     : 5,
    progress    : true,
    verbose     : true,},[ "benchmark.js", "benchmark2.js"]);
runner.run();