
template<typename T>
MutantStack<T>::MutantStack()
{
}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> &other)
{
	this->c = other.c;	
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack<T> &other)
{
	this->c = other.c;	
	return *this;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return this->c.end();
}
