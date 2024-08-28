#!/bin/bash

if [ "$1" == "book" ]; then
  g++ ./implementations/book_impl.cpp -o ./out/book_impl
  ./out/book_impl >> ./out/results/book_result.txt
elif [ "$1" == "mt" ]; then
  g++ ./implementations/mt_block_impl.cpp -o ./out/mt_block_impl
  ./out/mt_block_impl >> ./out/results/mt_result.txt

  g++ ./implementations/mt_default_impl.cpp -o ./out/mt_default_impl
  ./out/mt_default_impl >> ./out/results/mt_result.txt
else
  echo "Invalid argument. Use 'book' or 'mt'."
fi