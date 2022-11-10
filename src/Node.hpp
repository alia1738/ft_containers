/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:32:13 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/10 17:17:45 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

#include "pair.hpp"

namespace ft{

	template <class key, class val> 
	struct Node {
		typedef pair<key, val>		value_type;
		typedef Node*				pointer;

		value_type	_info;

		pointer		left;
		pointer		right;
		pointer		parent;

		std::size_t height;

		Node(){
			this->_info = NULL;
			this->parent = NULL;
			this->left = NULL;
			this->right = NULL;
			this->height = 0;
		}

		Node(const value_type& v): _info(v) {
			// _info->first = v.first;
			// _info->second = v.second;
			this->parent = NULL;
			this->left = NULL;
			this->right = NULL;
			this->height = 1;
		}
		Node(const pointer& p, const value_type& v) {
			_info = v;
			this->parent = p;
			this->left = NULL;
			this->right = NULL;
			this->height = 1;
		}

		void introduceChildToParent(const pointer c, bool r){
			if (r)
				this->right = c;
			else
				this->left = c;
		}

		~Node() {};
	};
}

#endif