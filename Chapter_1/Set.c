/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <cterrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 19:40:17 by cterrill          #+#    #+#             */
/*   Updated: 2017/07/14 19:40:17 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

#if ! defined MANY || MANY < 1
#define MANY 10
#endif

static int heap [MANY];

// New Object
void * new (const void * type, ...)
{
	int * p; /* & heap[1..] */

	p = heap + 1;
	while (p < heap + MANY)
	{
		if (!*p)
			break;
		++p;
	}
	assert(p < heap + MANY);
	*p = MANY;
	return (p);
}

// Delete Object
void delete (void * _item)
{
	int *item;

	item = _item;
	if (item)
	{
		assert(item > heap && item < heap + MANY);
		* item = 0;
	}
}


void * add(void * _set, const void * _element)
{
	int *set;
	const int * element;

	set = _set;
	element = _element;
	assert(set > heap && set < heap + MANY);
	assert(* set == MANY);
	assert(element > heap && element < heap + MANY);
	if (* element == MANY)
		* (int *) element = set - heap;
	else
	assert(* element == set - heap);
	return (void *) element;
}

void * find (const void * _set, const void * _element)
{
	const int * set = _set;
	const int * element = _element;
	assert(set > heap && set < heap + MANY);
	assert(* set == MANY);
	assert(element > heap && element < heap + MANY);
	assert(* element);
	return * element == set - heap ? (void *) element : 0;
}

int contains (const void * _set, const void * _element)
{
	return find(_set, _element) != 0;
}

void * drop (void * _set, const void * _element)
{
	int * element = find(_set, _element);
	if (element)
		* element = MANY;
	return element;
}

int differ (const void * a, const void * b)
{
	return a != b;
}