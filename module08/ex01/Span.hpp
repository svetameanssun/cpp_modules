/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:38:48 by stitovsk          #+#    #+#             */
/*   Updated: 2026/03/31 17:38:49 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>
#include <exception>


//std::set provides bidirectional iterators, NOT random-acceess iterators, 
class Span{
	public:
		Span(unsigned int number);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
		
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void fillInSet(std::set <int>::iterator begin, std::set <int>::iterator end);
		//void addRandNumbers(unsigned int amount);

		class NotEnoughElementsException : public std::exception{
			public:
				const char *what() const throw();
		};

		class OutOfRangeException :public std::exception{
			const char * what() const throw();
		};

		const std::set <int> getSet();
		void printSet();
	

	private:
		unsigned int N;// s[0...N-1]
		std::set<int> _set;
};


#endif