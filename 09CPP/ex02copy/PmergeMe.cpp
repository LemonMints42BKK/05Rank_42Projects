/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:44 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/12 17:13:29 by pnopjira         ###   ########.fr       */
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

template <typename Container>
int PmergeMe<Container>::getThreshold() const{
	return (this->_threshold);
}
/************************************************
 *         Constructor&Deconstructor            *
 ************************************************/

template <typename Container>
PmergeMe<Container>::PmergeMe(std::vector<std::string> arg) : _data(), _elapsedTime(-1), _threshold(52) {
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
		_threshold = other._threshold;
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
	int start = 0;
	int end = this->_data.size() - 1;
	int k = getThreshold();
    std::clock_t start_time = std::clock();
	if (start - end <= k)
		_tinsertionSort(this->_data, start, end);
	else {
		_tmergeSort(this->_data, 0, this->_data.size() - 1);
	}
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
void	PmergeMe<Container>::_tinsertionSort(Container & arr, int left, int right){
	int i, j, key;
	for (i = left + 1; i <= right; i++){
		key = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > key){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
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

template <typename Container>
bool PmergeMe<Container>::isSorted() {
    typename Container::iterator begin = this->_data.begin();
	typename Container::iterator end = this->_data.end();
	if (begin == end)
        return true; // Empty range is sorted
    typename Container::iterator next = begin;
    ++next;

    while (next != end) {
        if (*next < *begin) {
            return false;  // If the next element is less than the current one, it's not sorted
        }
        ++begin;
        ++next;
    }
    return true;  // If we reach here, the range is sorted
}
// Explicit
template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;