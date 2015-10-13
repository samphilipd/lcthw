puts "Finding max args using binary search..."

MAX_ARGS = 1_000_000

arg_n = MAX_ARGS
change = arg_n / 2


def call_with_args(n)
  strargs = (0...n).map {|n| "arg#{n}"}.join(' ')
  system("./ex10 #{strargs} &>/dev/null")
end


loop do
  if change == 0
    puts "\n\n-----\n"
    puts "found max args: #{arg_n}"
    break
  end

  if call_with_args(arg_n) # its smaller than the max
    puts "#{arg_n} args are OK, increasing to #{arg_n += change}"
  else # its too big
    puts "#{arg_n} args are too many, decreasing to #{arg_n -= change}"
  end
  change /= 2
end
