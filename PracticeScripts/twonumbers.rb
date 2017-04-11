#!/usr/bin/env ruby

input = gets.chomp

if input =~ /\d.*\d/
  puts 'two numbers'
else
  puts 'no good foobag.'
end
