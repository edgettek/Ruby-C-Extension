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
VALUE method_insert(int argc, VALUE* argv, VALUE self);
VALUE method_each(int argc, VALUE* argv, VALUE self);
VALUE method_sum(VALUE self);
VALUE my_block(VALUE block_arg, VALUE data, int argc, VALUE* argv);

// The initialization method for this module
void Init_CFixedArray() {


    CFixedArray = rb_define_class("FixedArray", rb_cObject);

    rb_define_method(CFixedArray, "initialize", method_new_array, -1);
    rb_define_method(CFixedArray, "insert_value", method_insert, -1);
    rb_define_method(CFixedArray, "each_itr", method_each, -1);
    rb_define_method(CFixedArray, "sum", method_sum, 0);

}

// Our 'test1' method.. it simply returns a value of '10' for now.
//VALUE method_test1(VALUE self) {
//    int x = 10;
//    return INT2NUM(x);
//}

VALUE method_new_array(int argc, VALUE* argv, VALUE self) {

    VALUE array = rb_ary_new2(argv[0]);

    rb_iv_set(CFixedArray, "@size", argv[0]);

    if(argc == 2) {
        long i;

        for(i = 0; i < NUM2LONG(argv[0]); i++) {
            //printf("i: %d INSERTING\n", i);
            rb_ary_store(array, i, argv[1]);
        }

    }
    rb_iv_set(CFixedArray, "@array", array);


    return array;
}

VALUE method_insert(int argc, VALUE* argv, VALUE self) {

    VALUE array = rb_iv_get(CFixedArray, "@array");

    long i = NUM2LONG(argv[0]);

    rb_ary_store(array, i, argv[1]);

    rb_iv_set(CFixedArray, "@array", array);

    return array;
}

VALUE method_each(int argc, VALUE* argv, VALUE self) {

//    VALUE block;
//
//    rb_scan_args(argc, argv, "0&", &block);
//
//    VALUE array = rb_iv_get(CFixedArray, "@array");
//
//    //VALUE result = rb_funcall_with_block(obj, rb_each(array), 0, NULL, block);
//
//    rb_funcall(block, rb_intern("call"),0);

    VALUE array = rb_iv_get(CFixedArray, "@array");

    long i;

    VALUE size = rb_iv_get(CFixedArray, "@size");

    for(i = 0; i < FIX2LONG(size); i++) {
        //printf("i: %d INSERTING\n", i);
        rb_yield(rb_ary_entry(array, i));
    }


    return Qnil;

}

VALUE method_sum(VALUE self) {

    long sum = 0;

    long i;

    VALUE size = rb_iv_get(CFixedArray, "@size");

    VALUE array = rb_iv_get(CFixedArray, "@array");

    for(i = 0; i < FIX2LONG(size); i++) {

        sum += FIX2LONG(rb_ary_entry(array, i));

    }

    return LONG2NUM(sum);

}
