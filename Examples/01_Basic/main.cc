//
// Created by manicqin on 14/07/18.
//

#include <node.h>

#include <algorithm>
#include <string>
#include <iterator>
#include <set>
#include <cmath>

namespace demo {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Context;
    using v8::Local;

    using v8::Object;
    using v8::Array;
    using v8::String;
    using v8::Int32;
    using v8::Number;

    using v8::Value;
    using v8::Exception;

    void reverse_string(const FunctionCallbackInfo<Value>& info) {
        Isolate* isolate = info.GetIsolate();

        if (!info[0]->IsString()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Param 1 - not a string")));
            return;
        }

        String::Utf8Value param1(info[0]->ToString());
        std::string tmp = std::string(*param1);

        std::reverse(tmp.begin(),tmp.end());
        info.GetReturnValue().Set(String::NewFromUtf8(isolate, tmp.c_str()));
    }

    void sum_int(const FunctionCallbackInfo<Value>& info) {
        Isolate* isolate = info.GetIsolate();

        if (info.Length() != 2) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate,"Wrong number of arguments")));
            return;
        }

        if (!info[0]->IsNumber()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Param 1 - not an int")));
            return;
        }

        if (!info[1]->IsNumber()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Param 2 - not an int")));
            return;
        }

        int param1 = info[0]->Int32Value();
        int param2 = info[1]->Int32Value();


        info.GetReturnValue().Set(param1 + param2);
    }

    void sum_int_array(const FunctionCallbackInfo<Value>& info) {
        Isolate* isolate = info.GetIsolate();

        if (!info[0]->IsArray()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Param 1 - not an array")));
            return;
        }

        int retval = 0;

        auto tmp_array = Local<Array>::Cast(info[0]);

        auto lngth = tmp_array->Length();

        for(unsigned int idx = 0; idx < lngth; ++idx) {
            auto num = Local<Number>::Cast(tmp_array->Get(idx));
            retval += num->Value();
        }

        info.GetReturnValue().Set(retval);
    }

    void unique_sort_array(const FunctionCallbackInfo<Value>& info) {
        Isolate* isolate = info.GetIsolate();

        if (!info[0]->IsArray()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Param 1 - not an array")));
            return;
        }

        auto tmp_array = Local<Array>::Cast(info[0]);
        auto lngth = tmp_array->Length();

        std::set<int32_t>   unique_list;
        for(uint32_t idx = 0; idx < lngth; ++idx) {

            auto num = Local<Number>::Cast(tmp_array->Get(idx));
            unique_list.insert(num->Value());
        }

        Local<Array> retval = Array::New(isolate, unique_list.size());

        uint32_t idx = 0;
        for(auto elem: unique_list) {
            retval->Set(idx, Int32::New(isolate, elem));
            ++idx;
        }

        info.GetReturnValue().Set(retval);
    }

    void distance_between(const FunctionCallbackInfo<Value>& info) {
        Isolate* isolate = info.GetIsolate();

        if (info.Length() != 2) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate,"Wrong number of arguments")));
            return;
        }

        if (!info[0]->IsObject()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Param 1 - not an object")));
            return;
        }

        if (!info[1]->IsObject()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate, "Param 2 - not an object")));
            return;
        }

        auto pnt1 = Local<Object>::Cast(info[0]);
        auto pnt2 = Local<Object>::Cast(info[1]);

        auto key_x = String::NewFromUtf8(isolate, "x");
        auto key_y = String::NewFromUtf8(isolate, "y");

        if(!pnt1->Has(isolate->GetCurrentContext(), key_x).FromJust() ||
            !pnt1->Has(isolate->GetCurrentContext(), key_y).FromJust()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate,"param 1 is not of type {x:number, y:number}")));
            return;
        }

        if(!pnt2->Has(isolate->GetCurrentContext(), key_x).FromJust() ||
           !pnt2->Has(isolate->GetCurrentContext(), key_y).FromJust()) {
            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate,"param 2 is not of type {x:number, y:number}")));
            return;
        }

        double retval = 0;

        auto maybe_pnt1_x = pnt1->Get(key_x)->ToNumber(isolate->GetCurrentContext());
        auto maybe_pnt1_y = pnt1->Get(key_y)->ToNumber(isolate->GetCurrentContext());

        auto maybe_pnt2_x = pnt2->Get(key_x)->ToNumber(isolate->GetCurrentContext());
        auto maybe_pnt2_y = pnt2->Get(key_y)->ToNumber(isolate->GetCurrentContext());

        if(maybe_pnt1_x.IsEmpty() || maybe_pnt1_y.IsEmpty()) {

            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate,"point 1 is not of type {x:number, y:number}")));
            return;

        }

        if(maybe_pnt2_x.IsEmpty() || maybe_pnt2_y.IsEmpty()) {

            isolate->ThrowException(Exception::TypeError(
                String::NewFromUtf8(isolate,"point 2 is not of type {x:number, y:number}")));
            return;

        }

        double pnt1_x = maybe_pnt1_x.ToLocalChecked()->Value();
        double pnt1_y = maybe_pnt1_y.ToLocalChecked()->Value();

        double pnt2_x = maybe_pnt2_x.ToLocalChecked()->Value();
        double pnt2_y = maybe_pnt2_y.ToLocalChecked()->Value();

        double x = std::pow(pnt1_x - pnt2_x, 2);
        double y = std::pow(pnt1_y - pnt2_y, 2);

        retval = std::sqrt(x + y);


        info.GetReturnValue().Set(retval);
    }

    void init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "reverse_string", reverse_string);
        NODE_SET_METHOD(exports, "sum_int", sum_int);
        NODE_SET_METHOD(exports, "sum_int_array", sum_int_array);
        NODE_SET_METHOD(exports, "unique_sort_array", unique_sort_array);
        NODE_SET_METHOD(exports, "distance_between", distance_between);
    }

    NODE_MODULE(addon, init)

}  // namespace demo