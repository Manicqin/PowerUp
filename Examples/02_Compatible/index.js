const addon = require('./build/Release/addon');

module.exports = {
    reverse_string : function(value) { return addon.reverse_string(value); },
    sum_int : function(value1, value2) { return addon.sum_int(value1, value2); },
    sum_int_array : (arr_val) => { return addon.sum_int_array(arr_val); },
    unique_sort_array : (arr_val) => { return addon.unique_sort_array(arr_val); },
    distance_between : function(value1, value2) { return addon.distance_between(value1, value2); }

};
