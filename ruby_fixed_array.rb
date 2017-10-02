class RubyFixedArray

  def initialize(size, default = nil)

    @array = Array.new(size)

    if !default.nil?

      for i in 0..(size-1)
        insert(i, default)
      end

    end

  end

  def insert(index, obj)
    @array[index] = obj
  end

  def each_iterator

    @array.each do |a|
      yield(a)
    end

    @array
  end

  def sum

    sum = 0

    each_iterator do |elem|
      sum += elem
    end

    sum
  end

  def to_s
    @array.to_s
  end

end