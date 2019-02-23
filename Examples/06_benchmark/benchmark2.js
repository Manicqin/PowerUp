const addon3                    = require('../03_NAPI/index.js');
const count_words_occurrence    = require('count-words-occurrence').default;
const count_words               = require('count-words');
const loremIpsum                = require('lorem-ipsum')


suite('count words 10 lorem Ipsum words', () => {
    const data = loremIpsum({count: 10});
    benchmark('03_NAPI', () => {
        addon3.count_words(data);
    });

    benchmark('https://www.npmjs.com/package/count-words-occurrence', () => {
        count_words_occurrence(data);
    });

    benchmark('https://www.npmjs.com/package/count-words', () => {
        count_words(data);
    });
});

suite('count words 100 lorem Ipsum words', () => {
    const data = loremIpsum({count: 100});
    benchmark('03_NAPI', () => {
        addon3.count_words(data);
    });

    benchmark('https://www.npmjs.com/package/count-words-occurrence', () => {
        count_words_occurrence(data);
    });

    benchmark('https://www.npmjs.com/package/count-words', () => {
        count_words(data);
    });
});

suite('count words 1000 lorem Ipsum words', () => {
    const data = loremIpsum({count: 1000});
    benchmark('03_NAPI', () => {
        addon3.count_words(data);
    });

    benchmark('https://www.npmjs.com/package/count-words-occurrence', () => {
        count_words_occurrence(data);
    });

    benchmark('https://www.npmjs.com/package/count-words', () => {
        count_words(data);
    });
});

suite('count words 10000 lorem Ipsum words', () => {
    const data = loremIpsum({count: 10000});
    benchmark('03_NAPI', () => {
        addon3.count_words(data);
    });

    benchmark('https://www.npmjs.com/package/count-words-occurrence', () => {
        count_words_occurrence(data);
    });

    benchmark('https://www.npmjs.com/package/count-words', () => {
        count_words(data);
    });
});