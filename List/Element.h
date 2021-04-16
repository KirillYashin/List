#pragma once

template <class T>
class Element
{
protected:
	T data;
	Element <T>* next;
public:
	Element(T new_data = 0, Element <T>* new_next = 0);
	Element(Element<T>& el);
	void SetData(T el);
	void SetNext(Element <T>* new_next);
	T GetData();
	Element* GetNext();
};

template <class T>
Element<T>::Element(T new_data, Element<T>* new_next)
{
	data = new_data;
	next = new_next;
}

template <class T>
Element<T>::Element(Element<T>& el)
{
	data = el.data;
	next = el.next;
}

template <class T>
void Element<T>::SetData(T el)
{
	data = el;
}

template <class T>
void Element<T>::SetNext(Element<T>* new_next)
{
	next = new_next;
}

template <class T>
T Element<T>::GetData()
{
	return data;
}

template <class T>
Element<T>* Element<T>::GetNext()
{
	return next;
}

