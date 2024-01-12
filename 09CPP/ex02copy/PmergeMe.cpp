/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:44 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/12 14:12:16 by pnopjira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/************************************************
 *              getter & setter                 *
 ************************************************/

template <typename Container>
void PmergeMe<Container>::putElapsedTime(double time){
	this->_elapsedTime = time;
}

template <typename Container>
double PmergeMe<Container>::getElapsedTime() const{
	return (this->_elapsedTime);
}

/************************************************
 *         Constructor&Deconstructor            *
 ************************************************/

template <typename Container>
PmergeMe<Container>::PmergeMe(std::vector<std::string> arg) : _data(), _elapsedTime(-1) {
	for (size_t i = 0; i < arg.size(); i++){
		std::stringstream ss(arg[i]);
		size_t tmp;
		ss >> tmp;
		this->_data.push_back(tmp);
	}
}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &other) {
    _data = other._data;
}


template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

/************************************************
 *               Operator function              *
 ************************************************/

template<typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &other) {
    if (this != &other) {
        _elapsedTime = other._elapsedTime;
		if (this->_data.size() != 0)
			this->_data.clear();
		for (size_t i = 0; i < other._data.size(); i++){
			this->_data.push_back(other._data.at(i));
		}
    }
    return *this;
}

/************************************************
 *               Member function                *
 ************************************************/

template <typename Container>
void PmergeMe<Container>::sort() {

    std::clock_t start_time = std::clock();

	_tmergeSort(this->_data, 0, this->_data.size() - 1);

    this->putElapsedTime((double)(clock() - start_time) / CLOCKS_PER_SEC);
}

template<typename Container>
void PmergeMe<Container>::print_data() const {
	for(int i = 0; i < 5; i++){
		if (i == 4 && _data.size() > 5){
			std::cout << "[...]";
			break;
		} else
			std::cout << _data.at(i) << " ";
	}
    std::cout << std::endl;
}

template<typename Container>
void PmergeMe<Container>::benchmark() const {
    std::cout
            <<	"Time to process a range of " << _data.size()
            << " elements with std::[" << typeid(Container).name()<< "]"
            << " : " << std::fixed << std::setprecision(5) << getElapsedTime() << " us"
            << std::endl;
}

template<typename Container>
void	PmergeMe<Container>::_tmergeSort(Container & arr, int start, int end) {
	if (start < end) {
		int mid = start + (end - start) / 2;
		_tmergeSort(arr, start, mid);
		_tmergeSort(arr, mid + 1, end);
		_tmerge(arr, start, mid, end);
	}
}

template<typename Container>
void	PmergeMe<Container>::_tmerge(Container & arr, int start, int mid, int end) {
	Container temp(end - start + 1);
	int i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end) {
		temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
	}

	while (i <= mid) {
		temp[k++] = arr[i++];
	}

	while (j <= end) {
		temp[k++] = arr[j++];
	}
	std::copy(temp.begin(), temp.end(), arr.begin() + start);
}

// Explicit
template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;