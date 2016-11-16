#pragma once
#include <iostream>
#include <map>

//Purpose: Associate a generic key and value
//Author: Arnas
//Version: 1.0
//Bugs: None known
//TODO: none
template <class T> class GenericMap {
public:
	GenericMap();
	~GenericMap();

	void add(std::string key, T value);
	void remove(std::string key);
	bool contains(std::string key);
	T get(std::string key);
	std::map<std::string, T> map;
private:

};


template<class T>
inline GenericMap<T>::GenericMap()
{
}

template<class T>
inline GenericMap<T>::~GenericMap()
{
}

template<class T>
inline void GenericMap<T>::add(std::string key, T value)
{
	map[key] = value;
}

template<class T>
inline void GenericMap<T>::remove(std::string key)
{
	map.erase(key);
}

template<class T>
inline bool GenericMap<T>::contains(std::string key)
{
	for (auto iter : map) {
		if (iter.first == key) {
			return true;
		}
	}
	return false;
}

template<class T>
inline T GenericMap<T>::get(std::string key)
{

	//return map.find(key)->second;
	return (T)map[key];
}

