/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:33:37 by pnopjira          #+#    #+#             */
/*   Updated: 2023/12/28 08:41:41 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T> &	Array<T>::operator=(Array const &rhs){
	if (this != &rhs)
	{
		delete [] this->_arr;
		this->_n = rhs._n;
		this->_arr = new T [this->_n];
		for (unsigned int i = 0; i < this->_n; i++)
			this->_arr[i] = rhs._arr[i];
	}
	return *this;
}

template <typename T>
T &	Array<T>::operator[](unsigned int const & i){
	if (i >= this->_n)
		throw IndexOutOfLimit(); 
	return this->_arr[i];
}

template <typename T>
const unsigned int & Array<T>::size(void) const {
	return (this->_n);
}

template<typename T>
void	iter(T const *array,const unsigned int & len, void (*f)(T const &))
{
	unsigned int *l = const_cast<unsigned int *>(&len);
	for (unsigned int i = 0; i < *l; i++){
		f(array[i]);
		if (i != *l - 1){
			std::cout<< ", ";
		} else
			std::cout << std:: endl;
		
	}
}

template<typename T>
void	ft_print(T const &a)
{
		std::cout << a; 
}

template <typename U>
Array<U> numbers(U const &n)
{
	Array<U> arr(n);
	return (arr);
}

template <typename U>
Array<U> time(Array<U> &arr)
{
	clock_t start, end;
	start = clock();
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = rand();
	end = clock();
	std::cout << "Time taken to assign " << arr.size() << " elements: " << (double)(end - start) / CLOCKS_PER_SEC << "s" << std::endl;
}