Normal "sorting" is the sorting with floats, "sorting_algorithms" are normal ints and "sortingwithclock" only shows on screen the time that the algorithms took to sort, "sortinginput" is where you choose how many elements you sort and the time

Notes for the first observations:

------
10k elements and less:
alogrithms are fast, best still are merge and quick because of complexity

100k elements:

insertion sort: 2945 ms (~3 seconds)
bubble sort: 19316 ms (~19 seconds)
selection sort 4316 ms (~4 seconds)
merge sort: 16 ms
quick sort: 21 ms

Other observations:

1 million elements does not work as I have not implemented a heap, algorithms with n^2 complexity will freeze and quick sort can break because of the rand() function.
For sorting a list with unknown number of elements, the list needs to be implemented with <vector>.
Have not tried sorting with strings.
------
