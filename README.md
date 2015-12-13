# Sorting
Some sorting algorithms for practice in C++

Contains a quick sort and a merge sort, both allow for parameterized less than functions that can define how objects will be sorted.

The merge sort utilizes an algorithm I designed that allows for in place merge utilizing a third auxilary pointer which cleverly
keeps track of an auxilary list by placing itself between iter_1 and iter_2.  iter_1 will iterate through the merge and populate it
with sorted values while at max 2 additional sorted lists will be kept track of at the end of the array.

I understand that this algorithm has most likely already been derived but I created this algorithm independently for practice.
