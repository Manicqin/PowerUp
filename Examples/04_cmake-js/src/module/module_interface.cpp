//
// Created by manicqin on 17/09/18.
//

#define NAPI_VERSION 3
#define NAPI_DISABLE_CPP_EXCEPTIONS 1

#include <napi.h>

#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cmath>

#include "library.h"

using namespace Napi;

std::string arg_count_error_message(const CallbackInfo &info, int arg_number) {
    std::ostringstream outmsg;

    outmsg << "Wrong number of arguments, expected: "
           << arg_number
           << " but got: "
           << info.Length();

    return std::string(outmsg.str());

}

Value reverse_string(const CallbackInfo &info) {
    Env env = info.Env();

    if (info.Length() != 1) {
        TypeError::New(env, arg_count_error_message(info, 1)).ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString()) {
        TypeError::New(env, "param 1 is not a string").ThrowAsJavaScriptException();
        return env.Null();
    }

    std::string tmp = powerup::reverse_string(info[0].As<String>());
    return String::New(env, tmp.c_str());
}

Value sum_int(const CallbackInfo &info) {
    Env env = info.Env();

    if (info.Length() != 2) {
        TypeError::New(env, arg_count_error_message(info, 2)).ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsNumber()) {
        TypeError::New(env, "param 1 is not an int").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[1].IsNumber()) {
        TypeError::New(env, "param 2 is not an int").ThrowAsJavaScriptException();
        return env.Null();
    }

    int param1 = info[0].As<Number>().Int32Value();
    int param2 = info[1].As<Number>().Int32Value();

    return Number::New(env, powerup::sum_int(param1, param2));
}

Value unique_sort_array(const CallbackInfo &info) {
    Env env = info.Env();

    if (info.Length() != 1) {
        TypeError::New(env, arg_count_error_message(info, 1)).ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsArray()) {
        TypeError::New(env, "param 1 is not an array").ThrowAsJavaScriptException();
        return env.Null();
    }

    auto tmp_array = info[0].As<Array>();
    auto lngth = tmp_array.Length();

    std::set<int32_t> unique_list;
    for (uint32_t idx = 0; idx < lngth; ++idx) {

        auto tmp = static_cast<Value>(tmp_array[idx]);
        if (tmp.IsNumber()) {
            auto num = tmp.ToNumber().Int32Value();
            unique_list.insert(num);
        }
    }

    Array retval = Array::New(env, unique_list.size());

    uint32_t idx = 0;
    for (auto elem: unique_list) {
        retval.Set(idx, Number::New(env, elem));
        ++idx;
    }

    return retval;
}

Value sum_int_array(const CallbackInfo &info) {
    Env env = info.Env();

    if (info.Length() != 1) {
        TypeError::New(env, arg_count_error_message(info, 1)).ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsArray()) {
        TypeError::New(env, "param 1 is not an array").ThrowAsJavaScriptException();
        return env.Null();
    }

    int retval = 0;

    auto tmp_array = info[0].As<Array>();

    auto lngth = tmp_array.Length();

    for (unsigned int idx = 0; idx < lngth; ++idx) {
        auto tmp = static_cast<Value>(tmp_array[idx]);
        if (tmp.IsNumber()) {

            retval += tmp.ToNumber().Int32Value();
        }
    }

    return Number::New(env, retval);
}

Value distance_between(const CallbackInfo &info) {
    Env env = info.Env();

    if (info.Length() != 2) {
        TypeError::New(env, arg_count_error_message(info, 2)).ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsObject()) {
        TypeError::New(env, "param 1 is not an object").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[1].IsObject()) {
        TypeError::New(env, "param 2 is not an object").ThrowAsJavaScriptException();
        return env.Null();
    }

    auto pnt1 = info[0].ToObject();
    auto pnt2 = info[1].ToObject();

    if (!pnt1.Has("x") || !pnt1.Has("y")) {
        TypeError::New(env, "param 1 is not of type {x:number, y:number}").ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!pnt2.Has("x") || !pnt2.Has("y")) {
        TypeError::New(env, "param 2 is not of type {x:number, y:number}").ThrowAsJavaScriptException();
        return env.Null();
    }

    double retval = 0;

    double pnt1_x = pnt1.Get("x").ToNumber().DoubleValue();
    double pnt2_x = pnt2.Get("x").ToNumber().DoubleValue();

    double pnt1_y = pnt1.Get("y").ToNumber().DoubleValue();
    double pnt2_y = pnt2.Get("y").ToNumber().DoubleValue();

    retval = powerup::distance(pnt1_x, pnt1_y, pnt2_x, pnt2_y);

    return Number::New(env, retval);

}

Promise count_words_promise(const CallbackInfo &info) {
    Env env = info.Env();

    auto deferred = Promise::Deferred::New(env);

    if (info.Length() != 2) {
        deferred.Reject(
            TypeError::New(env, arg_count_error_message(info, 2)).Value()
        );
    } else if (!info[0].IsString()) {
        deferred.Reject(TypeError::New(env, "param 1 is not a string").Value());
    } else {

        std::string  txt = info[0].As<String>();

        auto  dictionary = powerup::count_words(txt);

        auto map_object = Object::New(env);
        for(auto const& item_pair : dictionary )
        {
            map_object[item_pair.first] = item_pair.second;
        }

        deferred.Resolve(map_object);
    }

    return deferred.Promise();
}


Object Init(Env env, Object exports) {

    exports.Set(String::New(env, "reverse_string"),
                Function::New(env, reverse_string));

    exports.Set(String::New(env, "sum_int"),
                Function::New(env, sum_int));

    exports.Set(String::New(env, "sum_int_array"),
                Function::New(env, sum_int_array));

    exports.Set(String::New(env, "unique_sort_array"),
                Function::New(env, unique_sort_array));

    exports.Set(String::New(env, "distance_between"),
                Function::New(env, distance_between));

    exports.Set(String::New(env, "count_words_promise"),
                Function::New(env, count_words_promise));

    return exports;
}

NODE_API_MODULE(addon, Init)