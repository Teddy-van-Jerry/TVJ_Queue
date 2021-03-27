/*
 * File: TVJ_Queue.h
 * --------------------------
 *
 * @author: Teddy van Jerry
 * @licence: The MIT Licence
 * @compiler: at least C++/11 (tested on MSVC and MinGW)
 * @reliance: TVJ_Forward_List.h version 1.1
 *
 * @version 1.0 2021/03/27
 * - initial version
 *
 */

#pragma once
#include "TVJ_Forward_List.h"

namespace tvj
{
	template<typename Elem>
	class queue : protected forward_list<Elem>
	{
	public:

		/**
		 * brief: size
		 * param: (void)
		 * return: size_t
		 */
		using forward_list<Elem>::size;

		/**
		 * brief: check if it is empty
		 * param: (void)
		 * return: bool
		 */
		using forward_list<Elem>::empty;

		/**
		 * brief: front (the first element)
		 * param: (void)
		 * return: the element type
		 */
		Elem front();

		/**
		 * brief: back (the last element)
		 * param: (void)
		 * return: the element type
		 */
		Elem back();

		/**
		 * brief: push an element into queue
		 * param: the element
		 * return: void
		 */
		void push(const Elem& elem) noexcept;

		/**
		 * brief: pop an element from queue
		 * param: the element
		 * return: void
		 */
		void pop();

		/**
		 * brief: clear the queue
		 * param: (void)
		 * return: void
		 */
		using forward_list<Elem>::clear;
	};

	template<typename Elem>
	inline Elem queue<Elem>::front()
	{
#ifndef NDEBUG
		if (empty()) throw std::underflow_error("Call front function with an empty queue of tvj::queue");
#endif
		return *forward_list<Elem>::front();
	}

	template<typename Elem>
	inline Elem queue<Elem>::back()
	{
#ifndef NDEBUG
		if (empty()) throw std::overflow_error("Call back function with an empty queue of tvj::queue");
#endif
		return *forward_list<Elem>::back();
	}

	template<typename Elem>
	inline void queue<Elem>::push(const Elem& elem) noexcept
	{
		this->push_front(elem);
	}

	template<typename Elem>
	inline void queue<Elem>::pop()
	{
#ifndef NDEBUG
		if (empty()) throw std::underflow_error("Call pop function with an empty queue of tvj::queue");
#endif
		this->pop_back();
	}
}

// ALL RIGHTS RESERVED (C) 2021 Teddy van Jerry