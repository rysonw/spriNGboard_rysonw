#!/usr/bin/env perl

use strict;

for my $seed (0..50)
{
  my $cmd = "./src/game_runner/trivia $seed > ../test/regression/golden_data/seed_$seed.txt";
  `$cmd`;
}
