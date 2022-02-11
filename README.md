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
![main branch](https://github.com/smu-cs-3353/22s-pa01-kate/actions/workflows/build.yml/badge.svg)

## Tests
Tested with datasets in "data" folder named '4-paintings', '10-paintings', '20-paintings', '50-paintings', and '100-paintings'
Brute force stops being optimal after 20 paintings 

## Usage Instructions
* The program should accept a single command-line argument representing the name of the input file.
  - If the project is not executed with the correct number of arguments, output an error message that includes the proper formatting for running the program.
* The program should produce 3 output files named based on directions in the Output section above.
* The implementation should be object oriented.  

For example, if your input was "paintings.txt", your command-line argument would look like
`./<PATH TO THIS DIRECTORY>/cmake-build-debug/22s-pa01-kate ./<PATH TO INPUT FILE>/paintings.txt` after running the cmake executable to configure the project.

## Data Analysis
Below is a table that compares the different algorithms to the total painting values (in dollars) they were able to produce with data sets of size 4, 10, 20, 50, and 100.


|  Data Set Size| Brute Force Algorithm | Most Expensive First Algorithm | My Personal Heuristic |
|---------------|-----------------------|--------------------------------|-----------------------|
| 4 paintings   |         350           |             300                |          300          |
| 10 paintings  |         2630          |             1850               |          2630         |
| 20 paintings  |         n/a           |             1674               |          1674         |
| 50 paintings  |         n/a           |             2436               |          3462         |
| 100 paintings |         n/a           |             1357               |          5136         |



Below are graphs (3 different perspectives of the same graph) that compares the different algorithms to their runtime on datasets ranging from 1 to 100,000.

![Image](data/graph-1.png)
This graph shows the brute force algorithm increasing its time rapidly. The brute force has a time complexity of O(n!), as it generates every potential permutation of a dataset and generating combinations have a factorial runtime. 
The brute force algorithm cannot run past a dataset of 11 paintings. It takes nearly two minutes to compute a dataset of 11, compared to 5 seconds for a dataset of 10, and any dataset larger than 11 will cause the program to fault out.

![Image](data/graph-2.png)
This is fullest, least zoomed rendition of the graph. You can see the thin brute force line on the very far left axis, while the other two algorithms progress at approximately the same rate.
This is because my custom heuristic and the priciest first heuristic follow much of the same logic, and they are structured nearly identically.
The priciest-first heuristic sorts paintings in descending order according to price into a vector using selection sort.
The custom heuristic does the same thing, except instead of looking at price, it looks at a predetermined value that I calculated for each painting, which has to do more with their price relative to width than their cost overall.
Since both the priciest-first heuristic and my custom heuristic utilize selection sort as their main method, they have a runtime of O(n<sup>2</sup>).

![Image](data/graph-3.png)
This final graph merely allows for a closer comparison between the priciest first heuristic and the custom heuristic by lowering the range of the vertical axis.
The two are very close, but my custom heuristic takes slightly longer on average. This is due to the extra calculation of dividing price<sup>2</sup> by width in order to calculate the value of the painting.