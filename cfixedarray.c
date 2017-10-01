//
// Created by Kyle Edgette on 10/1/17.
//

// Include the Ruby headers and goodies
#include "ruby.h"

// Defining a space for information and references about the module to be stored internally
VALUE MyTest = Qnil;

// Prototype for the initialization method - Ruby calls this, not you
void Init_cfixedarray();

// Prototype for our method 'test1' - methods are prefixed by 'method_' here
VALUE method_test1(VALUE self);

// The initialization method for this module
void Init_cfixedarray() {
    VALUE CFixedArray = rb_define_module("CFixedArray");
    rb_define_method(CFixedArray, "test1", method_test1, 0);
}

// Our 'test1' method.. it simply returns a value of '10' for now.
VALUE method_test1(VALUE self) {
    int x = 10;
    return INT2NUM(x);
}

