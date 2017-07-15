/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterrill <cterrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 19:34:35 by cterrill          #+#    #+#             */
/*   Updated: 2017/07/14 19:34:35 by cterrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SET_H
#define SET_H

const void * Set;
void * new (const void *type, ...);
void delete (void * _item);
void * add (void * set, const void * element);
void * find (const void * set, const void * element);
void * drop (void * set, const void * element);
int contains (const void * set, const void * element);

#endif