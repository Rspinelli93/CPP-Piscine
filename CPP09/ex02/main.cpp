
int main( void )
{
	//https://medium.com/@toukmati2000/cpp09-ford-johnson-algorithm-e6ad43288d4b
}


/*
~MergeInsertionSort(std::vector<int> &X)
~binary_insert(Container &S, int element_to_insert, Iterator upper_bound)

* Merge-Insertion Sort (Ford-Johnson) Recursive Structure

* 1. Check the base case: If the sequence has 1 or 0 elements, return it immediately.

* 2. Prepare local storage for this recursion level:
	+ A container to hold the pairs (winner and loser linked together).
	+ A variable to store a potential unpaired element.
	+ A boolean flag to remember if there is an unpaired element.

* 3. Handle odd number of elements:
	+ If the sequence size is odd, isolate the last element into the unpaired variable.
	+ Remove it from the current sequence so you are left with an even number.
	+ Set your boolean flag to true.

* 4. Create the pairs:
	+ Iterate through the remaining sequence two by two.
	+ Compare the two elements: identify the larger (winner) and the smaller (loser).
	+ Store them physically bound together in your pairs container.

* 5. Extract winners for the next level:
	+ Create a fresh container dedicated solely to the winners.
	+ Loop through your pairs container and extract just the winners into this new container.

* 6. The Recursive Dive:
	+ Call this exact sorting function, passing it the container of winners.
	+ Store the returned, sorted result in a new container (this becomes your 'S' or main chain).

* 7. The First Insertion (Zero-cost):
	+ Look at the very first element of your newly sorted main chain (the smallest winner).
	+ Find its original linked loser in your pairs container.
	+ Push this loser to the very front of the main chain.

* 8. Prepare for Jacobsthal Insertions:
	+ Generate or calculate the Jacobsthal sequence numbers needed for your remaining uninserted elements (the rest of the losers + the unpaired element).
	+ Map these numbers into your group sizes.

* 9. Execute Binary Insertions:
	+ Iterate through each Jacobsthal group.
	+ Inside each group, iterate in reverse order.
	+ For each element to insert:
		- a. Find the current iterator/position of the winner it originally lost to. This becomes your strict upper boundary for the search. (For the unpaired element, the boundary is the end of the chain).
		- b. Perform a binary search strictly between the start of the chain and that specific boundary.
		- c. Insert the element at the iterator returned by your binary search.

* 10. Return the fully built main chain to unwind the recursion.

However, since you are writing this in C++98, we use the upgraded, safer version of a pointer: a reference.
Approach	Function Signature	Verdict
Pass by Value (The Trap)	std::vector<int> sort(std::vector<int> X)	Fail. Copies the entire array on every single recursive return. Kills performance.
Pass by Pointer (Your Idea)	void sort(std::vector<int>* X)	Good. Avoids copies. But requires constant dereferencing (X->size(), (*X)[i]), and pointers can technically be NULL, requiring extra safety checks.
Pass by Reference (C++ Way)	void sort(std::vector<int>& X)	Best. Modifies the original memory directly. Cannot be NULL. Syntax remains clean (X.size(), X[i]).

By passing your container by reference (&), the function doesn't need to return anything. It simply modifies the container "in place" from the perspective of the caller.

Now, looking ahead at the requirements for this specific task, you usually have to implement this exact logic using two entirely different C++ containers.

If you choose std::vector for the first one, binary search is easy because it has contiguous memory and you can jump straight to the middle using indexes (S[mid]).

If you choose std::list for the second one, it only allows sequential access (you cannot do S[mid], you have to iterate node by node). How are you going to perform a fast binary search on a std::list without ruining your time complexity
 ------
Concept	The std::list Reality
The Problem	You cannot calculate the middle with pointer arithmetic like S.begin() + mid. The compiler will throw an error because std::list only provides Bidirectional Iterators, not Random Access Iterators.
The C++98 Tool	You use std::lower_bound from the <algorithm> library.
How it Works	You pass it your begin iterator, your calculated upper_bound iterator, and the value to insert. It calculates the middle using std::advance and std::distance, returning the exact iterator where the element should be inserted.
The PmergeMe Loophole	Because it has to traverse node by node to reach the middle, the actual time complexity degrades to O(n). However, std::lower_bound still guarantees O(logn) comparisons.
Since the algorithm's goal is strictly to minimize data comparisons, this fulfills the theoretical requirement completely.

    Note: If you try to write your own custom binary search using loops and std::advance, it will do the exact same thing as std::lower_bound, just with more lines of code.

To use std::lower_bound effectively, you must pass it an exact upper boundary (the iterator of the winner that your current loser originally fought).

Since you cannot do a standard search for the winner without adding forbidden comparisons to your count, how do you plan to find the winner's current iterator position in the std::list so you can set that boundary?
 */