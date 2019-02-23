//
// Created by manicqin on 25/07/18.
//

#include <nan.h>
#include <set>
#include <cmath>

using v8::FunctionTemplate;
using v8::Handle;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Array;
using v8::Number;
using v8::Int32;

using Nan::GetFunction;
using Nan::New;
using Nan::Set;
using Nan::To;
using Nan::ThrowError;
using Nan::TypeError;

NAN_METHOD(sum_int) {

    if (!info[0]->IsNumber()) {
        return ThrowError(TypeError("param 1 is not an int"));
    }

    if (!info[1]->IsNumber()) {
        return ThrowError(TypeError("param 2 is not an int"));
    }

    int param1 = To<int>(info[0]).FromJust();
    int param2 = To<int>(info[1]).FromJust();

    info.GetReturnValue().Set(param1 + param2);
}

NAN_METHOD(sum_int_array) {

    if (!info[0]->IsArray()) {
        return ThrowError(TypeError("param 1 is not an array"));
    }

    int retval = 0;

    auto tmp_array = Local<Array>::Cast(info[0]);

    auto lngth = tmp_array->Length();

    for(unsigned int idx = 0; idx < lngth; ++idx) {
        auto maybe_num = To<int>(tmp_array->Get(idx));
        if(maybe_num.IsJust()) {
            retval += maybe_num.FromJust();
        }

    }

    info.GetReturnValue().Set(retval);
}

NAN_METHOD(reverse_string) {

    if (!info[0]->IsString()) {
        return ThrowError(TypeError("param 1 is not a string"));
    }

    std::string tmp = *String::Utf8Value(info[0]->ToString());
    std::reverse(tmp.begin(),tmp.end());

    info.GetReturnValue().Set(New<String>(tmp.c_str()).ToLocalChecked());
}

NAN_METHOD(unique_sort_array) {

    if (!info[0]->IsArray()) {
        return ThrowError(TypeError("Param 1 - not an array"));
    }

    auto tmp_array = Local<Array>::Cast(info[0]);
    auto lngth = tmp_array->Length();

    std::set<int32_t>   unique_list;
    for(uint32_t idx = 0; idx < lngth; ++idx) {

        auto num = Local<Number>::Cast(tmp_array->Get(idx));
        unique_list.insert(num->Value());
    }

    Local<Array> retval = New<Array>(unique_list.size());

    uint32_t idx = 0;
    for(auto elem: unique_list) {
        retval->Set(idx, New<Int32>(elem));
        ++idx;
    }

    info.GetReturnValue().Set(retval);
}

NAN_METHOD(distance_between) {

    if (info.Length() != 2) {
        return ThrowError(TypeError("Wrong number of arguments"));
    }

    if (!info[0]->IsObject()) {
        return ThrowError(TypeError("param 1 is not an object"));
    }

    if (!info[1]->IsObject()) {
        return ThrowError(TypeError("param 2 is not an object"));
    }

    auto pnt1 = To<Object>(info[0]).ToLocalChecked();
    auto pnt2 = To<Object>(info[1]).ToLocalChecked();

    auto key_x = New<String>("x").ToLocalChecked();
    auto key_y = New<String>("y").ToLocalChecked();

    if(!Nan::Has(pnt1, key_x).FromJust() || !Nan::Has(pnt1, key_y).FromJust()) {
        return ThrowError(TypeError("param 1 is not of type {x:number, y:number}"));
    }

    if(!Nan::Has(pnt2, key_x).FromJust() || !Nan::Has(pnt2, key_y).FromJust()) {
        return ThrowError(TypeError("param 2 is not of type {x:number, y:number}"));
    }

    double retval = 0;

    double pnt1_x = Nan::To<double>(Nan::Get(pnt1, key_x).ToLocalChecked()).FromJust();
    double pnt2_x = Nan::To<double>(Nan::Get(pnt2, key_x).ToLocalChecked()).FromJust();

    double pnt1_y = Nan::To<double>(Nan::Get(pnt1, key_y).ToLocalChecked()).FromJust();
    double pnt2_y = Nan::To<double>(Nan::Get(pnt2, key_y).ToLocalChecked()).FromJust();

    double x = std::pow(pnt1_x - pnt2_x, 2);
    double y = std::pow(pnt1_y - pnt2_y, 2);

    retval = std::sqrt(x + y);

    info.GetReturnValue().Set(retval);
}


NAN_MODULE_INIT(InitAll) {
    Set(target, New<String>("sum_int").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(sum_int)).ToLocalChecked());

    Set(target, New<String>("sum_int_array").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(sum_int_array)).ToLocalChecked());

    Set(target, New<String>("reverse_string").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(reverse_string)).ToLocalChecked());

    Set(target, New<String>("unique_sort_array").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(unique_sort_array)).ToLocalChecked());

    Set(target, New<String>("distance_between").ToLocalChecked(),
        GetFunction(New<FunctionTemplate>(distance_between)).ToLocalChecked());

}

NODE_MODULE(addon, InitAll)