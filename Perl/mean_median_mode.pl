#! /usr/bin/env perl
#
# Short description for mean_median_mode.pl
# Displays the mean median mode of randomly generated numbers.
# Author Jecsan Blanco <jblancolicano1@buffs.wtamu.edu>
# Version 0.1
# Copyright (C) 2018 Jecsan Blanco <jblancolicano1@buffs.wtamu.edu>
# Modified On 2018-10-30 16:09
# Created  2018-10-30 16:09
#
use strict;
use  5.18.0;
use warnings;
use POSIX;


main(@ARGV);

sub main{
    my @random_numbers;
    my $size_of_array = 10;
    my $min = 0;
    my $max = 100;
    for( my $i = 0; $i <$size_of_array; $i = $i + 1){
        push @random_numbers , getRandom($min,$max);
    }
    my @ordered_numbers = bubbleSort(@random_numbers);;

    my $mean = mean(@random_numbers);
    my $median = median(@random_numbers);
    my @mode = mode(@random_numbers);

    say "Given numbers:";
    say "@random_numbers";

    printf("Mean: %.1f\n",$mean);

    say "Sorted numbers:";
    say "@ordered_numbers";

    say "Median: $median ";

    foreach my $num (@mode){say "Mode: $num"};
}
sub mean{
    my @array = @_;
    my $sum = 0;
    foreach my  $num (@array){
        $sum = $sum + $num;
    }
    return $sum / scalar @array;

}
sub median{

    my @array =  bubbleSort(@_);
    my $array_len = scalar @array;
    my $mid =  floor($array_len /2);
    my $is_even = !($array_len % 2);
    my $ans = $array[$mid];
    if($is_even){
        $ans = $array[$mid] + $array[$mid+1];
        $ans = $ans / 2;
    }
    return $ans;
}
sub mode{
    my @orginal = @_;
    my @array = bubbleSort(@_);
    my %nums;
    my $top = 1;
    # setup the hashmap that holds how many times each number repeats
    foreach my $i (@array){
        if(!exists($nums{$i})){
            $nums{$i} =  (1);
        }else{
            my $temp = $nums{$i} + 1;
            $nums{$i} =$temp;
            $top = $temp > $top ? $temp : $top;
        }
    }
    # find the keys that have the top values
    my @most = ();
    my @one = ();
    $one[0]   = $orginal[0];
    foreach my $key (keys  %nums){
        if($nums{$key} == $top){
            push @most, $key;
        }
    }

    return ($top > 1) ? @most : @one;
}

# returns a random number between X and Y inclusive.
sub getRandom{
    my $X = shift;
    my $Y = shift;
    return int( rand( $Y-$X+1 ) ) + $X;
}
#bubble sort 
sub bubbleSort {
    my @array   = @_;
    my $sorted = 0;

    while ( not $sorted ) {
        $sorted = 1; # Innocent until proven guilty.

        for my $current ( 1 .. $#array ) {
            my $previous = $current - 1;

            if ( $array[$current] < $array[$previous] ) {
                ($array[$current], $array[$previous]) = 
                                        ($array[$previous], $array[$current]);

                $sorted = 0;
            }
        }
    }
    return @array;
}
