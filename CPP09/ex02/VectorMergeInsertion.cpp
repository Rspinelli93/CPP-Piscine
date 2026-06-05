#include "MergeInsertion.hpp"

static void	CheckUneven( int &uneven, bool &isUneven, std::vector<int> &X );
static void	PopulatePairs( std::vector<std::pair<int, int> > &pairs, std::vector<int> &X );
static void PushWinners( std::vector<std::pair<int, int> > &pairs, std::vector<int> &X );
static void	insertBiggesLoser( std::vector<std::pair<int, int> > &pairs, std::vector<int> &X );
static void ReorderLosers( std::vector<std::pair<int, int> > &left_losers, std::vector<std::pair<int, int> > &pairs, std::vector<int> &X );
static void	JacobsthalSequence( std::vector<int> &jacob, int size );
static void PushLeftLosers( std::vector<std::pair<int, int> > &left_losers, std::vector<int> &jacob, std::vector<int> &X );
static void binaryInsertion( std::vector<int> &X, int val, std::vector<int>::iterator limit );

void VectorMergeInsertion( std::vector<int> &X )
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

	//+ Recursive call of VectorMergeInsertion now only with the winners of the pairs +//
	VectorMergeInsertion(X);

	insertBiggesLoser(pairs, X);

	std::vector<std::pair<int, int> > left_losers;
	ReorderLosers( left_losers, pairs, X );

	std::vector<int>	jacob;
	JacobsthalSequence(jacob, (int)left_losers.size());

	PushLeftLosers(left_losers, jacob, X);

	if (isUneven)
		binaryInsertion(X, uneven, X.end());
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
	if (left_losers.empty())
		return ;
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
			limit = find(X.begin(), X.end(), i_losers->first);
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
static void JacobsthalSequence( std::vector<int> &jacob, int losers_size )
{
    int max_target = losers_size + 1; 
    int curr = 3;
    int prev = 1;

    if (curr > max_target)
    {
        jacob.push_back(max_target);
        return ;
    }
    jacob.push_back(curr);
	while (curr < max_target)
    {
        int next_num = curr + 2 * prev;
        prev = curr;
        curr = next_num;
        
        if (curr > max_target)
            jacob.push_back(max_target);
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
	std::vector<std::pair<int, int> >::iterator i_pairs = pairs.begin();

	while (i_X != X.end())
	{
		while (i_pairs != pairs.end())
		{
			std::pair<int, int> temp;
			if (i_pairs->first == *i_X)
			{
				temp = std::make_pair(i_pairs->first, i_pairs->second);
				left_losers.push_back(temp);
				break ;
			}
			i_pairs++;
		}
		i_pairs = pairs.begin();
		i_X++;
	}
}

/// @brief This function will create and push pairs of numbers, specifically from both ends into the middle of the vector
///        (The reason is to do less iterations).
/// @param pairs The vector of pairs to be populated
/// @param X The main vector
static void	PopulatePairs( std::vector<std::pair<int, int> > &pairs, std::vector<int> &X )
{
	std::vector<int>::iterator i_X = X.begin();
	std::vector<int>::iterator i_X2 = X.end() - 1;

	while (i_X < i_X2)
	{
		std::pair<int, int> temp;
		if (*i_X > *i_X2)
			temp = std::make_pair(*i_X, *i_X2);
		else
			temp = std::make_pair(*i_X2, *i_X);
		pairs.push_back(temp);
		i_X++;
		i_X2--;
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
