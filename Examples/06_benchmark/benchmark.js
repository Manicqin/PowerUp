const addon1     = require('../01_Basic/index.js');
const addon2     = require('../02_Compatible/index.js');
const addon3     = require('../03_NAPI/index.js');

suite('sum int', () => {

    benchmark('V8', () => {
        addon1.sum_int(1,2);
    });

    benchmark('Nan', () => {
        addon2.sum_int(1,2);
    });

    benchmark('Napi', () => {
        addon3.sum_int(1,2);
    });
});

suite('sum int array', () => {

    benchmark('V8', () => {
        addon1.sum_int_array([1,2,3]);
    });

    benchmark('Nan', () => {
        addon2.sum_int_array([1,2,3]);
    });

    benchmark('Napi', () => {
        addon3.sum_int_array([1,2,3]);
    });
});

suite('reverse_string', () => {

    benchmark('V8', () => {
        addon1.reverse_string("1234");
    });

    benchmark('Nan', () => {
        addon2.reverse_string("1234");
    });

    benchmark('Napi', () => {
        addon3.reverse_string("1234");
    });
});

suite('distance_between', () => {

    benchmark('V8', () => {
        addon1.distance_between({x:1,y:1},{x:5,y:4});
    });

    benchmark('Nan', () => {
        addon2.distance_between({x:1,y:1},{x:5,y:4});
    });

    benchmark('Napi', () => {
        addon3.distance_between({x:1,y:1},{x:5,y:4});
    });
});

suite('unique sort array', () => {

    benchmark('V8', () => {
        addon1.unique_sort_array([1, 1, 3, 3 ,2]);
    });

    benchmark('Nan', () => {
        addon2.unique_sort_array([1, 1, 3, 3 ,2]);
    });

    benchmark('Napi', () => {
        addon3.unique_sort_array([1, 1, 3, 3 ,2]);
    });
});

