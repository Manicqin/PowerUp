const addon = require('./build/Release/example04_module');
//require("bindings")("example04_module");

addon.reverse_string("1234")

module.exports = {
    reverse_string: function (value) {
        return addon.reverse_string(value);
    },
    sum_int: function (value1, value2) {
        return addon.sum_int(value1, value2);
    },
    sum_int_array: (arr_val) => {
        return addon.sum_int_array(arr_val);
    },
    unique_sort_array: (arr_val) => {
        return addon.unique_sort_array(arr_val);
    },
    distance_between: function (value1, value2) {
        return addon.distance_between(value1, value2);
    },
    count_words_promise: function (value1, value2) {
        return addon.count_words_promise(value1, value2);
    },
};

