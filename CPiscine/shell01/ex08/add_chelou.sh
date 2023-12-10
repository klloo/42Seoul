#!/bin/bash

num1=$(echo $FT_NBR1 | tr "'" '0' | tr '\' '1' | tr '"' '2' | tr '?' '3' | tr '!' '4')
num2=$(echo $FT_NBR2 | tr 'mrdoc' '01234')

result=$(echo "obase=13; ibase=5;$num1+$num2" | bc)

echo $result | tr '0123456789ABC' 'gtaio luSnemf'
