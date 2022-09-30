/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:32:13 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/09/28 09:23:52 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include "pair.hpp"

namespace ft{

	template <class key, class val> 
	struct Node {
		typedef typename pair<key, val>		value_type;
		typedef typename Node*				pointer;

		value_type	_info;

		pointer		left;
		pointer		right;
		pointer		parent;

		size_t hight;

		Node(const value_type& v): v(_info) {
			this->left = NULL;
			this->right = NULL;
			this->hight = 0;
		}
		Node(const pointer& p, const value_type& v): parent(p), v(_info) {
			this->left = NULL;
			this->right = NULL;
			this->hight = 0;
		}

		~Node();
	};
}

#endif