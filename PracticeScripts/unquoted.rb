#!/usr/bin/env ruby

html = File.read(ARGV[0])

html.gsub!(/=([^"]\S*?)d/ , 
