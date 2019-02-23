const addon     = require('../index.js');
const assert    = require('assert');


describe('Testing the methods of the module', function() {

    it('Reversing a string', function() {
        assert.equal(addon.reverse_string("1234"), "4321");
    });

    it('Adding two numbers', function() {
        assert.equal(addon.sum_int(1,2), 3);
    });

    it('Adding array of numbers', function() {
        assert.equal(addon.sum_int_array([1,2,3]), 6);
    });

    it('Filtering and sorting list of numbers', function() {
        assert.deepEqual(addon.unique_sort_array([1, 1, 3, 3 ,2]), [1,2,3]);
    });

    it('Distance between 2 "Point" objects', function() {
        assert.deepEqual(addon.distance_between({x:1,y:1},{x:5,y:4}), 5.0);
    });
});




