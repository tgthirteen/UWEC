#!/usr/bin/env ruby

input = gets.chomp

if input =~ /^<.+?>$/
  puts 'is an html tag '
else
  puts 'no good foobag.'
end
