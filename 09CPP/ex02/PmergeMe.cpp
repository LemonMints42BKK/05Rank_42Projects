/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnopjira <65420071@kmitl.ac.th>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:27:44 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/12 12:57:42 by pnopjira         ###   ########.fr       */
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
PmergeMe<Container>::PmergeMe(std::vector<std::string> arg) : _data(), _last(-1), _elapsedTime(-1) {
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
        //_data = other._data;
        _last = other._last;
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

    pair_vector pairs = generate_pairs(_data);
    int_vector insertionIndexes = generate_indexes(_data.size());

    if (pairs.size() == 0) {
        _data.push_back(_last);
        this->putElapsedTime((double)(clock() - start_time) / CLOCKS_PER_SEC);
        return;
    }

    sort_pairs(pairs);

    _data.clear();

    _data.push_back(pairs[0].second);

    for (size_type i = 0; i < pairs.size(); i++) {
        _data.push_back(pairs[i].first);
    }

    for (size_t i = 0; i < insertionIndexes.size(); i++)
    {
        if (size_t(insertionIndexes[i] - 1) >= pairs.size()) {
            continue;
        }

        int index = binary_search(pairs[insertionIndexes[i] - 1].second);
        _data.insert(_data.begin() + index, pairs[insertionIndexes[i] - 1].second);
    }

    if (_last != -1) {
        int index = binary_search(_last);
        _data.insert(_data.begin() + index, _last);
    }

    this->putElapsedTime((double)(clock() - start_time) / CLOCKS_PER_SEC);
}

template <typename Container>
typename PmergeMe<Container>::pair_vector PmergeMe<Container>::generate_pairs(Container &data) {
    pair_vector pairs;

    // If the size of the data is odd, we need to store the last element
    if (data.size() % 2 != 0) {
        _last = data.back();
        data.pop_back();
    }

    for (size_type i = 0; i < data.size(); i += 2) {

        // If the first element is greater than the second, swap them
        if (data[i] < data[i + 1]) {
            std::swap(data[i], data[i + 1]);
        }

        pairs.push_back(std::make_pair(data[i], data[i + 1]));
    }

    return pairs;
}

template <typename Container>
void PmergeMe<Container>::sort_pairs(pair_vector &pairs) {
    if (pairs.size() <= 1) {
        return; // Base case: Nothing to sort
    }

    // Divide the vector into two halves
    size_type middle = pairs.size() / 2;
    pair_vector leftHalf(pairs.begin(), pairs.begin() + middle);
    pair_vector rightHalf(pairs.begin() + middle, pairs.end());

    // Recursively sort the two halves
    sort_pairs(leftHalf);
    sort_pairs(rightHalf);

    // Merge the sorted halves
    size_type leftIdx = 0;
    size_type rightIdx = 0;
    size_type idx = 0;

    while (leftIdx < leftHalf.size() && rightIdx < rightHalf.size()) {
        pairs[idx++] = leftHalf[leftIdx].first < rightHalf[rightIdx].first ? leftHalf[leftIdx++] : rightHalf[rightIdx++];
    }

    while (leftIdx < leftHalf.size()) {
        pairs[idx++] = leftHalf[leftIdx++];
    }

    while (rightIdx < rightHalf.size()) {
        pairs[idx++] = rightHalf[rightIdx++];
    }
}

template <typename Container>
int PmergeMe<Container>::binary_search(int target) {
    int left = 0;
    int right = _data.size() - 1;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (_data[middle] == target) {
            return middle;
        } else if (_data[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return left;
}

template <typename Container>
int_vector PmergeMe<Container>::generate_indexes(size_t size) {
    int_vector indexes;
    int jacobsthalSequence[size + 1];

    jacobsthalSequence[0] = 0;
    jacobsthalSequence[1] = 1;
    int lastJacobsthalNumber = 2;

    for (size_t i = 2; indexes.size() < size; i++)
    {
        // Generate the next Jacobsthal number
        jacobsthalSequence[i] = jacobsthalSequence[i - 1] + 2 * jacobsthalSequence[i - 2];

        // Push the jacobsthal number
        i != 2 ? indexes.push_back(jacobsthalSequence[i]) : (void)0;

        // Push back the indexes between the last Jacobsthal number and the current one
        for (int j = jacobsthalSequence[i] - 1; j > lastJacobsthalNumber; j--)
            indexes.push_back(j);

        // Update the last Jacobsthal number
        lastJacobsthalNumber = jacobsthalSequence[i];
    }
    return (indexes);
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

// Explicit
template class PmergeMe< std::vector<int> >;
template class PmergeMe< std::deque<int> >;