/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miterator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalsuwai <aalsuwai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:07:48 by aalsuwai          #+#    #+#             */
/*   Updated: 2022/11/17 16:56:49 by aalsuwai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MITERATOR_HPP
# define MITERATOR_HPP

#include "map.hpp"

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Allocate = std::allocator< pair<const Key, T> > > class map;
	
	/* ---------------------- -- - Iterator - -- --------------------- */
	template < class Key, class T, class N, class Compare = std::less<Key> > class miterator {
	
	public:
		typedef N											_node;
		typedef N*											pointer;
		typedef N&											reference;
		typedef typename map< Key, T >::difference_type		difference_type;
		typedef Compare										key_compare;
		typedef Key											key_type;
		typedef T											mapped_type;



	private:
		pointer		_it;
		key_compare	comp;
		
	public:
		miterator(){}

		miterator(const miterator& it){
			this->_it = it._it;
		}

		miterator(pointer n){
			this->_it = n;
		}

		miterator& operator=(const miterator& it){
			if (this != &it)
				this->_it = it._it;
			return (*this);
		}

		mapped_type& operator*() const{
			return (this->_it->_info.second);}

		miterator& operator++(){
			// if (_it && !_it->right) {
			// 	while (!_it->parent || comp(_it->parent->_info.first, _it->_info.first))
			// 		_it = _it->parent;
			// 	std::cout << "_it->_info.first: " << _it->_info.first << std::endl;
			// 	std::cout << "_it->right: " << _it->right << std::endl;
			// 	std::cout << "_it->parent: " << _it->parent << std::endl;
			// 	throw std::out_of_range("\nError: ft::map::iterator: out of range");
			// }
			if (_it->right)
				getSuccessor();
			else
				findChosenParentPlus();
			return (*this);

			// if there is no right and (parent comp is true || parent is null) then throw error <went out of range> or something
			// if node have no right it go to parent and find the final one to return 
			// if node have right then get inorder successor 

			// if when you got to parent then comp is true got to parent again then check the new parent with old parent till you find one that comp is false and return it 
			// if when you go to parent then comp is false then return this parent
		}

		miterator operator++(int){
			miterator temp = *this;
			++(*this);
			return (temp);
		}

		miterator& operator--(){
			if (_it && !_it->left && (!_it->parent || !comp(_it->parent->_info.first, _it->_info.first)))
				throw std::out_of_range("\nError: ft::map::iterator: out of range");
			if (_it->left)
				getPredecessor(_it);
			else
				findChosenParentMinus(_it);
			
			return (*this);
		}

		miterator operator--(int){
			miterator temp = *this;
			--(*this);
			return (temp);
		}

		void	findChosenParentPlus() {
			//if parent is not null 
			// if parent is smaller than current one then go to parent 
			// if parent is bigger than current one then go to parent and return 
			if (!this->_it->parent)
				throw std::out_of_range("\nError: ft::map::iterator: out of range");
			if (this->_it->parent && comp(this->_it->parent->_info.first, this->_it->_info.first)) {
				this->_it = this->_it->parent;
				findChosenParentPlus();
			}
			else if (this->_it->parent && !comp(this->_it->parent->_info.first, this->_it->_info.first)) {
				this->_it = this->_it->parent;
				return ;
			}
		}

		void	findChosenParentMinus() {
			if (this->_it->parent && !comp(this->_it->parent->_info.first, this->_it->_info.first)) {
				this->_it = this->_it->parent;
				findChosenParentMinus();
			}
			else if (this->_it->parent && comp(this->_it->parent->_info.first, this->_it->_info.first)) {
				this->_it = this->_it->parent;
				return ;
			}
		}

		void getPredecessor(bool first_time = true) {
			if (first_time)
				this->_it = this->_it->left;
			
			if (!this->_it->right)
				return ;
			this->_it = this->_it->right;
			getSuccessor(false);
		}

		void	getSuccessor(bool first_time = true) {
			if (first_time)
				this->_it = this->_it->right;
			
			if (!this->_it->left)
				return ;
			this->_it = this->_it->left;
			getSuccessor(false);
		}
		
	};
}

#endif