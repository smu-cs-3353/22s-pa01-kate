# The Art Gallery
Programming Assignment 1 for CS 3353

## Project Description

The programmer is working to increase revenue for art galleries by optimizing which art pieces get displayed in the gallery.
Art pieces are aligned along the centerline of the wall as below.

![Image](https://media.lumas.com/inspiration/haengetipps_kachel/kantenhaengung-595x380.jpg)

There is a limited amount of space on the wall and the program must choose which combination of artworks that fit will sell for the highest total amount.

### Additional Points:
- Art pieces cannot be rotated
- When an art piece sells, the empty space on the wall will not be replaced. 
- The program only needs to work for 1 wall
- Every art piece is guaranteed to fit on the wall. 

### Input:
The input will be in a text file whose formatting will be the same as the following:
```
1024 768
4
12 300 1023 767
9 200 300 100
23 250 800 700
1 100 100 100
```

* _Line 1_ contains two integers separated by a space representing the length and height of the wall, respectively
* _Line 2_ contains a single integer n that represents the total number of art pieces to follow
* _Lines 3 to (3 + (n-1))_ contain 4 integers each separated by spaces:
   - first integer is the picture ID
   - second integer is the value of the picture
   - third integer is the width of the picture
   - fourth integer is the height of the picture. 

### Measurements:
* The max width and height of a wall will be 1,000,000 units. 
* The max width and height of an image will be 1,000,000 units. 
* The max number of images to choose from will be 100,000. 

## Algorithms
There are 3 placement algorithms implemented: 
* **Brute Force**: Find the optimal solution by trying every possible combination and returning that with the highest value
* **Most Expensive Picture First**: Sort the pictures in decreasing order by value. Add them to the wall in order, skipping over any pieces that won’t fit. 
* ** Self-designed heuristic **: Design a strategy that produces a result faster than brute force and that attempts to outperform the most-expensive-first algorithm in terms of total value on wall. 

## Output
The output will consist of 3 text files, one for each placement algorithm.  These files are named by appending “-bruteforce”, “-highvalue”, and “-custom” to the name of the input file.  For example, if the name of the input file is test.txt, the output files will be test-bruteforce.txt, test-highvalue.txt, and test-custom.txt. 

Each output file should be formatted as follows: 
* The first line should contain a single integer representing the cumulative value of all pieces of art placed on the wall for this particular algorithm.
  - Each additional line represents a picture and should consist of 4 integers, each separated by a space
    * First integer is the picture id
    * Second integer is the value of that picture
    * Third integer is the width of that picture
    * Fourth integer is the height of that picture

## Build Status
![main branch](https://github.com/katebouis/22s-pa01-kate/actions/workflows/build.yml/badge.svg)

## Tests
Tested with datasets in "data" folder named '4-paintings', '10-paintings', '20-paintings', '50-paintings', '100-paintings', and '2000-paintings'
Brute force stops being optimal after 20 paintings 

## Usage Instructions
* The program should accept a single command-line argument representing the name of the input file.
  - If the project is not executed with the correct number of arguments, output an error message that includes the proper formatting for running the program.
* The program should produce 3 output files named based on directions in the Output section above.
* The implementation should be object oriented.
