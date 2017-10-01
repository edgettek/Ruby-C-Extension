require './ruby_fixed_array'
require './cfixedarray.bundle'

class Test

  print " *** Testing C Extension Class ***\n\n"

# MyTest is now a module, so we need to include it
  include CFixedArray

  puts test1


  print " *** Testing Ruby Fixed Array Class ***\n"

  t_before_ruby = Time.now

  fixed_array = RubyFixedArray.new(1000000, 253)

  sum = fixed_array.sum

  t_after_ruby = Time.now

  ruby_execution_time = t_after_ruby - t_before_ruby

  print "Time for Ruby version (to calculate the sum of an array of size 1,000,000 filled with 253): " + ruby_execution_time.to_s
  print "\n\nSum: " + sum.to_s
end