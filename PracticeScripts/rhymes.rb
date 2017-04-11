#!/usr/bin/env ruby

require 'json'
require 'open-uri'

url = "http://rhymebrain.com/talk?function=getRhymes&word=#{ARGV[0]}/"

json = open(url).read

rhymes = JSON.parse(json)

rhymes.each do |rhyme|

  puts rhyme['word'] if rhyme['score'] >= 300  

end
