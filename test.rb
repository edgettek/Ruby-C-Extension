require './ruby_fixed_array'
require './CFixedArray.bundle'


class Test

  print "*** Testing C Extension Class ***\n\n"

  print "\t*Test #1:\n\t[1,1,1,1,1]\n\tInsert 10 at index 0 => [10,1,1,1,1]\n\tSum should be 14\n\n"


  c_fixed_array = FixedArray.new(5, 1)

  c_fixed_array.insert_value(0, 10)

  sum = c_fixed_array.sum

  print "\tSum of [10, 1, 1, 1, 1] == " + sum.to_s

  print "\n\n\tPrinting out array using C each implementation: "

  c_fixed_array.each_itr {|element| print "#{element}, "}

  print "\n\n\t*Test #2:\n\tArray of length 1,000,000 filled with 253\n\n"

  t_before_c = Time.now

  c_fixed_array2 = FixedArray.new(1000000, 253)

  sum2 = c_fixed_array2.sum

  t_after_c = Time.now

  c_execution_time = t_after_c - t_before_c

  print "\tSum of [253, 253, 253, ...] == " + sum2.to_s

  print "\n\n\tTime for C Version: " + c_execution_time.to_s

  print "\n\n*** Testing Ruby Fixed Array Class ***\n\n"

  print "\tTest #1:\n\tArray of length 1,000,000 filled with 253\n\n"

  t_before_ruby = Time.now

  fixed_array = RubyFixedArray.new(1000000, 253)

  sum3 = fixed_array.sum

  t_after_ruby = Time.now

  ruby_execution_time = t_after_ruby - t_before_ruby

  print "\tSum of [253, 253, 253, ...] == " + sum3.to_s

  print "\n\n\tTime for Ruby Version: " + ruby_execution_time.to_s + "\n\n"

end