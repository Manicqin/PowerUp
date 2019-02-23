const   addon           = require('../index.js');

let     chai            = require('chai');
const   {assert}        = chai;

const   chaiAsPromised  = require("chai-as-promised");
chai.use(chaiAsPromised);
chai.should();

describe('Testing the methods of the module', function () {

    it('Reversing a string', function () {
        assert.equal(addon.reverse_string("1234"), "4321");
    });

    it('Adding two numbers', function () {
        assert.equal(addon.sum_int(1, 2), 3);
    });

    it('Adding array of numbers', function () {
        assert.equal(addon.sum_int_array([1, 2, 3]), 6);
    });

    it('Filtering and sorting list of numbers', function () {
        assert.deepEqual(addon.unique_sort_array([1, 1, 3, 3, 2]), [1, 2, 3]);
    });

    it('Distance between 2 "Point" objects', function () {
        assert.deepEqual(addon.distance_between({x: 0, y: 0}, {x: 4, y: 3}), 5.0);
    });

    it('Count Words ', function () {
        assert.deepEqual(addon.count_words("boom boom boom bam"), {"boom":3, "bam":1});
    });

    it('Count Words Promise', () => {
        return addon.count_words_promise("boom boom boom bam").should.eventually.deep.equal({"boom":3, "bam":1});
    });

});




