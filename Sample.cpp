/*
 * File: Sample.cpp
 * Project: TVJ_Queue
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

#include <iostream>
#include "TVJ_Queue.h"

int main()
{
	tvj::queue<int> test;

	test.push(3);
	std::cout << test.size() << ' ' << test.front() << std::endl;
	for (int i = 100; i != 200; i += 10) test.push(i);
	std::cout << test.size() << ' ' << test.back() << std::endl;
	while (test.back() != 120) test.pop();
	std::cout << test.size() << ' ' << test.back() << std::endl;
	test.clear();
	std::cout << test.size() << std::endl;
	return 0;
}

// ALL RIGHTS RESERVED (C) 2021 Teddy van Jerry