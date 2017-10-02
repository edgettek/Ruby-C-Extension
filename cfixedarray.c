//
// Created by Kyle Edgette on 10/1/17.
//

// Include the Ruby headers and goodies
#include "ruby.h"

// Defining a space for information and references about the module to be stored internally
VALUE CFixedArray = Qnil;

// Prototype for the initialization method - Ruby calls this, not you
void Init_CFixedArray();

// Prototype for our method 'test1' - methods are prefixed by 'method_' here
VALUE method_test1(VALUE self);
VALUE method_new_array(int argc, VALUE* argv, VALUE self);
VALUE method_insert(VALUE index, VALUE val, VALUE self);

// The initialization method for this module
void Init_CFixedArray() {


    CFixedArray = rb_define_module("FixedArray");

    rb_define_method(CFixedArray, "new_array", method_new_array, -1);
    rb_define_method(CFixedArray, "insert_value", method_insert, 2);
}

// Our 'test1' method.. it simply returns a value of '10' for now.
//VALUE method_test1(VALUE self) {
//    int x = 10;
//    return INT2NUM(x);
//}

VALUE method_new_array(int argc, VALUE* argv, VALUE self) {

    VALUE array = rb_ary_new2(argv[0]);

    if(argc == 2) {
        long i;

        for(i = 0; i < FIX2LONG(argv[0]); i++) {
            //printf("i: %d INSERTING\n", i);
            rb_ary_store(array, i, argv[1]);
        }

    }
    rb_iv_set(CFixedArray, "@array", array);


    return array;
}

VALUE method_insert(VALUE index, VALUE val, VALUE self) {

    printf("Entered the method");

    VALUE array = rb_iv_get(CFixedArray, "@array");

    printf("Able to retrieve array");

    VALUE temp = rb_ary_entry(array, FIX2LONG(index));

    return array;
}
