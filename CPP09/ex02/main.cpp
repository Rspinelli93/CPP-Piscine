#include <iostream>
#include <vector>
#include <algorithm>

void MergeInsertion( std::vector<int> &X);
void printVector( std::vector<int> &V );

int main( void )
{
	std::vector<int> myVector;

	myVector.push_back(5);
	myVector.push_back(4);
	myVector.push_back(10);
	myVector.push_back(3);
	myVector.push_back(7);
	myVector.push_back(9);
	myVector.push_back(1);
	printVector(myVector);
	MergeInsertion(myVector);
	printVector(myVector);
	//https://medium.com/@toukmati2000/cpp09-ford-johnson-algorithm-e6ad43288d4b
}

void printVector( std::vector<int> &V )
{
	std::vector<int>::iterator it = V.begin();
	while (it != V.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << "\n";
}

/// @brief Find a number in X
/// @param toFind The number to find
/// @return A vector in that position
static std::vector<int>::iterator findInt( std::vector<int>::iterator beg, std::vector<int>::iterator end, int toFind )
{
    std::vector<int>::iterator ret = beg;
    
    while (ret != end && *ret != toFind)
        ret++;
    return (ret);
}

/// @brief Binary search for the insertion of an int inside a vector<int>
/// @param X The main vector
/// @param val The value to be added
/// @param limit Max position to search though (the position of that number pair winner)
static void binaryInsertion( std::vector<int> &X, int val, std::vector<int>::iterator limit )
{
    std::vector<int>::iterator it = std::lower_bound(X.begin(), limit, val);
    X.insert(it, val);
}

/// @brief This functions end the whole logic. By using the index determinated by the Jacobsthal number
///        The algorithm iterates though the left_losers one by one. For each of them, it calls binaryInsertion
///        Function used to binary serch the right position to the number (limit that number pair winner)
///        And then placing the number inside X on the right position.
/// @param left_losers The left organized losers
/// @param jacob A vector containing the numbers from the sequence
/// @param X The Main Vector
static void PushLeftLosers( std::vector<std::pair<int, int> > &left_losers, std::vector<int> &jacob, std::vector<int> &X )
{
	std::vector<std::pair<int, int> >::iterator  i_losers;
	std::vector<int>::iterator                   i_jacob = jacob.begin();
	std::vector<int>::iterator                   limit;

	int prevJSnum = -1;
	while (i_jacob != jacob.end())
	{
		int JSnum = *i_jacob - 2;
		int temp = JSnum;
		while (JSnum > prevJSnum)
		{
			i_losers = left_losers.begin() + JSnum;
			limit = findInt(X.begin(), X.end(), i_losers->first);
			binaryInsertion(X, i_losers->second, limit);
			JSnum--;
		}
		prevJSnum = temp;
		i_jacob++;
	}
}

/// @brief Calculate the Jacobsthal sequence (Jn = J{n-1} + 2J{n-2}).
///        Sequence follows: (3, 5, 7, 11, ...) based on left_losers size.
///        The algorithm uses these numbers to know from which index
///        it should push left_losers into X, via left_losers[*it_jacob - 2].
///        In human terms :), it pushes:
///        1,0 -> 3,2 -> 9,8,7,6,5,4 -> and so forth.
///        The iteration will be run on an offset of 2 (considering pos 1 is [0], + the first loser has already been pushed before
/// @param jacob A vector to store the Jacobsthal sequence numbers.
/// @param size  The size of the container containing the left losers.
static void	JacobsthalSequence( std::vector<int> &jacob, int size )
{
	int					curr = 3;
	int					prev = 1;

	jacob.push_back(curr);
	while (curr < size)
	{
		int next_num = curr + 2 * prev;
		prev = curr;
		curr = next_num;
		if (next_num > size)
			jacob.push_back(size);
		else
			jacob.push_back(curr);
	}
}

/// @brief Reorder pairs for later push into X (following Jacobsthal Sequence).
/// @param left_losers New vector of pairs that will contain at the end of the iteration
///                    the same pairs from <pairs> but following the order of the .first now located in X in the right order.
/// @param pairs The original pairs, pushed at the begining of the recursion in no particular oder.
/// @param X The main vector containing the numbers, now only containing winners in order + biggest loser.
static void ReorderLosers( std::vector<std::pair<int, int> > &left_losers, std::vector<std::pair<int, int> > &pairs, std::vector<int> &X )
{
	std::vector<int>::iterator i_X = X.begin() + 2; // Skip the first pair (biggest loser, smaller winner)
	std::vector<std::pair<int, int> >::iterator i_losers = left_losers.begin();
	std::vector<std::pair<int, int> >::iterator i_pairs = pairs.begin();

	while (i_X != X.end())
	{
		while (i_pairs != pairs.end())
		{
			if (i_pairs->first == *i_X)
			{
				left_losers.insert(i_losers, *i_pairs);
				i_losers++;
			}
			i_pairs++;
		}
		i_X++;
	}
}

/// @brief This function will create and push pairs of numbers, specifically from both ends into the middle of the vector
///        (The reason is to do less iterations).
/// @param pairs The vector of pairs to be populated
/// @param X The main vector
void	PopulatePairs( std::vector<std::pair<int, int> > &pairs, std::vector<int> &X )
{
	std::vector<int>::iterator i_X = X.begin();
	std::vector<int>::iterator i_X2 = X.end() - 1;
	std::vector<std::pair<int, int> >::iterator i_pairs = pairs.begin();

	while (i_X < i_X2)
	{
		if (*i_X > *i_X2)
			*i_pairs = std::make_pair(*i_X, *i_X2);
		else
			*i_pairs = std::make_pair(*i_X2, *i_X);
		i_X++;
		i_X2--;
		i_pairs++;
	}
}

/// @brief This function will push the winners into vector X in no particular order
/// @param pairs A vector of unordered pairs
/// @param X The main vector
static void PushWinners( std::vector<std::pair<int, int> > &pairs, std::vector<int> &X )
{
	std::vector<std::pair<int, int> >::iterator i_pairs = pairs.begin();
	i_pairs = pairs.begin();
	while (i_pairs != pairs.end())
	{
		X.push_back(i_pairs->first);
		i_pairs++;
	}
}

/// @brief This function will iterate though the pairs until it finds the pair with the key at X[0]
///        aka. the biggest loser (or the loser of the smallest winner)
///        then it will push it at the begining of the vector X
/// @param pairs A vector of unordered pairs
/// @param X The main vector
static void	insertBiggesLoser( std::vector<std::pair<int, int> > &pairs, std::vector<int> &X )
{
	std::vector<std::pair<int, int> >::iterator i_pairs = pairs.begin();

	i_pairs = pairs.begin();
	while (i_pairs != pairs.end())
	{
		if (i_pairs->first == *(X.begin()))
		{
			X.insert(X.begin(), i_pairs->second);
			pairs.erase(i_pairs);
			break ;
		}
		i_pairs++;
	}
}

/// @brief This function checks if the size of the main vector is uneven,
///        the algo needs even numbers for the rest of the execution until basically the end
///        If there is an uneven amount of numbers, its store it in an int and removed from the main vector,
/// @param uneven The interger removed from X, stored here.
/// @param isUneven True if is there is an uneven amount of numbers (for future checking)
/// @param X The main vector
static void	CheckUneven( int &uneven, bool &isUneven, std::vector<int> &X )
{
	if ( (X.size() % 2) != 0 )
	{
		isUneven = true;
		uneven = X.back();
		X.pop_back();
	}
}

void MergeInsertion( std::vector<int> &X )
{
	//+ Base case, if the vector has only one number or no numbers +//
	if ((X.size() < 2))
		return ;

	int		uneven;
	bool	isUneven = false;
	CheckUneven(uneven, isUneven, X);

	std::vector<std::pair<int, int> > pairs;
	PopulatePairs(pairs, X);

	//+ Clear the vector and push the winners +//
	X.clear();
	PushWinners(pairs, X);

	//+ Recursive call of MergeInsertion now only with the winners of the pairs +//
	MergeInsertion(X);

	insertBiggesLoser(pairs, X);

	std::vector<std::pair<int, int> > left_losers;
	ReorderLosers( left_losers, pairs, X );

	std::vector<int>	jacob;
	JacobsthalSequence(jacob, (int)left_losers.size());

	PushLeftLosers(left_losers, jacob, X);

	if (isUneven)
		binaryInsertion(X, uneven, X.end());
}

































/*
	* The golden rule of binary search: It is most efficient when the size of the array you are searching
	* is exactly 1 less than a power of 2 (sizes 1, 3, 7, ...). Searching an array of size 3 takes exactly
	* 2 comparisons. Searching an array of size 4 takes up to 3 comparisons.
	*/
	/*
	*print array of pairs
	for (int i = 0; i < (int)X.size() / 2; i++)
		std::cout << "First" << pairs[i].first << " - Second:" << pairs[i].second << std::endl;
	std::cout << uneven << std::endl;
	*/

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