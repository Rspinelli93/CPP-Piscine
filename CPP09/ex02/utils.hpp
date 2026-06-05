#ifndef UTILS_HPP
# define UTILS_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <bits/stdc++.h>
#include "MergeInsertion.hpp"

#define RED     "\033[31m"
#define BLACK   "\033[0m"
#define GREEN   "\033[32m"
#define PURPLE  "\033[35m"
#define YELLOW  "\033[33m"

/// @brief Function to populate <int> containers from another vector container
/// @tparam T The type of container
/// @param Container The container to populate
/// @param list The vector containing the values
template <typename T>
void populateContainer( T &Container, int ac, char **av )
{
	for( int i = 1; i < ac; i++)
		Container.push_back(std::atoi(av[i]));
}

/// @brief Function to populate <int> containers from another vector container
/// @tparam T The type of container
/// @param Container The container to populate
/// @param list The vector containing the values
template <typename T>
void populateNContainer( T &Container, int n )
{
	srand(time(0));

	for( int i = 0; i < n; i++)
		Container.push_back(rand() % 1000000);
}

bool	parseArgs( int ac, char **av );
void	printVector( std::vector<int> &V );
void	printDeque( std::deque<int> &D );
void	runTest( int n );

/// @brief Runs a void function and prints its time of execution
/// @tparam T Type of the param recieved by the function
/// @param funct Function to run
/// @param param The parameter passed to the function
template <typename T>
void timeOfExecution(void (*funct)(T&), T &param)
{
    clock_t start = clock();
    funct(param);
    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    std::cout << YELLOW << "Time taken: " << std::fixed << std::setprecision(5) << time_taken << " sec" << BLACK << std::endl;
}

#endif