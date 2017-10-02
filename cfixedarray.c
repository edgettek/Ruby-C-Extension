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
    rb_define_method(CFixedArray, "each_itr", method_each, -1);
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

VALUE method_each(int argc, VALUE* argv, VALUE self) {

    VALUE block;

    rb_scan_args(argc, argv, "&", &block);

    VALUE array = rb_iv_get(CFixedArray, "@array");

    VALUE result = rb_block_call(obj, rb_each(array), 0, NULL, block, Qnil);

    return result;

}

VALUE method_sum(VALUE self) {

    long sum = 0;

    // call each with a block

    rb_funcall(VALUE recv, ID id, int argc, ...)




}

VALUE my_block(VALUE block_arg, VALUE data, int argc, VALUE* argv)
{
	return FIX2LONG(data)+ FIX2LONG(block_arg)

	/* data will be the last argument you passed to rb_block_call */
	/* if multiple values are yielded, use argc/argv to access them */
}
