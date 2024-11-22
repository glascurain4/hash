/* quadratic.h
Gabriel Lascurain Flores
*/

#ifndef QUADRATIC_H_
#define QUADRATIC_H_

#include <string>
#include <sstream>
#include <iostream>

template <class Key, class Value>
class Quadratic {
private:
	unsigned int (*hashFunc)(const Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf(const Key) const;

public:
	Quadratic(unsigned int, Key, unsigned int (*)(const Key));
	bool full() const;
	bool put(Key, Value);
	Value get(const Key) const;
	std::string toString() const;
};

template <class Key, class Value>
Quadratic<Key, Value>::Quadratic(unsigned int sze, Key init, unsigned int (*f)(const Key)) 
	: size(sze), initialValue(init), hashFunc(f), count(0) {

	keys = new Key[size];
	if (!keys) {
		std::cerr << "Error: Memory allocation failed for keys" << std::endl;
		return;
	}

	values = new Value[size];
	if (!values) {
		std::cerr << "Error: Memory allocation failed for values" << std::endl;
		delete[] keys;
		return;
	}

	for (unsigned int i = 0; i < size; ++i) {
		keys[i] = initialValue;
		values[i] = Value();
	}
}

template <class Key, class Value>
bool Quadratic<Key, Value>::full() const {
	return (count >= size);
}

template <class Key, class Value>
long Quadratic<Key, Value>::indexOf(const Key k) const {
	unsigned int start = hashFunc(k) % size;
	unsigned int i = start;

	do {
		if (keys[i] == k) return i;
		i = (i + 1) % size;
	} while (i != start);

	return -1;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::put(Key k, Value v) {
	if (full()) {
		std::cerr << "Error: Hash table is full" << std::endl;
		return false;
	}

	long pos = indexOf(k);
	if (pos != -1) {
		values[pos] = v;
		return true;
	}

	unsigned int start = hashFunc(k) % size;
	unsigned int attempt = 0;
	unsigned int i;

	do {
		i = (start + attempt * attempt) % size;
		if (keys[i] == initialValue) {
			keys[i] = k;
			values[i] = v;
			++count;
			return true;
		}
		++attempt;
	} while (attempt < size);

	return false;
}

template <class Key, class Value>
Value Quadratic<Key, Value>::get(const Key k) const {
	long pos = indexOf(k);
	if (pos != -1) return values[pos];
	
	std::cerr << "Error: Key not found" << std::endl;
	return Value();
}

template <class Key, class Value>
std::string Quadratic<Key, Value>::toString() const {
	std::stringstream aux;

	for (unsigned int i = 0; i < size; ++i) {
		if (keys[i] != initialValue) {
			aux << "(" << i << " " << keys[i] << " : " << values[i] << ") ";
		}
	}

	return aux.str();
}

#endif
