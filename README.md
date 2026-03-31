Normal "sorting" is the sorting with floats, "sorting_algorithms" are normal ints and "sortingwithclock" only shows on screen the time that the algorithms took to sort, "sortinginput" is where you choose how many elements you sort and the time.
All the lists are randomly generated on the spot.

Notes for the first observations: (in average on random lists)

------
500 elements:

insertion sort: <1 ms
bubble sort: <1 ms
selection sort: <1 ms
merge sort: <1 ms
quick sort: <1 ms
Important to note, on small elements some of the higher complexity algorithms can reproduce faster results depending on the list.

5k elements:

insertion sort: 8 ms
bubble sort: 31 ms
selection sort: 16 ms
merge sort: 2 ms
quick sort: 1 ms

10k elements:

insertion sort: 32 ms
bubble sort: 125 ms
selection sort: 52 ms
merge sort: 3 ms
quick sort: 1 ms

50k elements:

insertion sort: 725 ms
bubble sort: 4597 ms (~4 seconds)
selection sort: 1080 ms (~1 second)
merge sort: 15 ms
quick sort: 7 ms

100k elements:

insertion sort: 2945 ms (~3 seconds)
bubble sort: 19316 ms (~19 seconds)
selection sort 4316 ms (~4 seconds)
merge sort: 16 ms
quick sort: 21 ms

On higher number of elements we can see how the algorithms with smaller complexity perform much better than the bigger complexity algorithms.
Another thing to note is how quick sort consistently performs better than merge sort.
Insertion sort is one of the better algorithms with bigger complexity.
Bubble sort consistently reaches the slowest results, can see why it is mostly used for education purposes.

Other observations:

1 million elements does not work as I have not implemented a heap, algorithms with n^2 complexity will freeze and quick sort can break because of the rand() function.
For sorting a list with unknown number of elements, the list needs to be implemented with <vector>.
Have not tried sorting with strings.
------
