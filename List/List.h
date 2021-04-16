#pragma once 
#include "Element.h"
#include "../Exception/Exception.h"
#include <iostream>

template <class T>
class List
{
protected:
    Element<T>* begin;
    int count;

public:
    List();
    List(List<T>& lst);
    virtual ~List();
    int GetSize();
    void Push(int pos, T elem);
    void PushBegin(T el);
    void PushEnd(T el);
    T Get(int pos);
    T GetBegin();
    T GetEnd();
    bool IsFull();
    bool IsEmpty();
    void Print();
};

template <class T>
List<T>::List()
{
    begin = 0;
    count = 0;
}

template <class T>
List<T>::List(List<T>& lst)
{
    count = lst.count;
    Element<T>* temp = lst.begin;
    Element<T>* copy;
    if (lst.begin == 0)
        begin = 0;
    else
    {
        begin = new Element<T>(*lst.begin);
        copy = begin;
        while (temp->GetNext() != 0)
        {
            copy->SetNext(new Element<T>(*(temp->GetNext())));
            temp = temp->GetNext();
            copy = copy->GetNext();
        }
    }
}

template <class T>
List<T>::~List()
{
    while (begin != 0)
    {
        Element<T>* temp = begin;
        begin = begin->GetNext();
        delete temp;
    }
}

template<class T>
int List<T>::GetSize()
{
    return count;
}

template<class T>
void List<T>::Push(int pos, T elem)
{
    pos--;
    if (this->IsFull())
        throw Exception("List is full");
    if (pos < 1 || pos > count - 1)
        throw Exception("Wrong index");
    else
    {
        int i = 0;
        Element<T>* temp = begin;
        while (i != pos - 1)
        {
            temp = temp->GetNext();
            i++;
        }
        Element<T>* push = new Element<T>(elem, temp->GetNext());
        temp->SetNext(push);
        count++;
    }
}

template <class T>
void List<T>::PushBegin(T el)
{
    if (this->IsFull())
        throw Exception("List if full");
    Element<T>* temp = new Element<T>(el, begin);
    begin = temp;
    count++;
}

template <class T>
void List<T>::PushEnd(T el)
{
    if (this->IsFull())
        throw Exception("List is full");
    if (begin != 0)
    {
        Element<T>* temp = begin;
        while (temp->GetNext() != 0) {
            temp = temp->GetNext();
        }
        temp->SetNext(new Element <T>(el, 0));
    }
    else {
        begin = new Element<T>(el, 0);
    }
    count++;
}

template<class T>
T List<T>::Get(int pos)
{
    if (this->IsEmpty())
        throw Exception("List is empty");
    if (pos < 1 || pos > count - 1)
        throw Exception("Wrong index");
    else
    {
        int i = 0;
        count--;
        Element<T>* temp = begin;
        Element<T>* del = begin->GetNext();
        while (i != pos - 1)
        {
            temp = del;
            del = del->GetNext();
            i++;
        }
        T ans = del->GetData();
        temp->SetNext(del->GetNext());
        delete del;
        return ans;
    }
}

template <class T>
T List<T>::GetBegin()
{
    if (IsEmpty())
        throw Exception("List is empty");
    else
    {
        Element<T>* del = begin;
        T temp = begin->Element<T>::GetData();
        begin = begin->Element<T>::GetNext();
        delete del;
        count--;
        return temp;
    }
}

template <class T>
T List<T>::GetEnd()
{
    if (IsEmpty())
        throw Exception("List is empty");
    else
    {
        count--;
        Element<T>* temp = begin;
        Element<T>* del = begin->GetNext();
        if (del == 0)
        {
            T ans = temp->Element<T>::GetData();
            delete temp;
            begin = 0;
            return ans;
        }
        else
        {
            while (del->GetNext() != 0)
            {
                temp = del;
                del = del->GetNext();
            }
            T ans = del->GetData();
            delete del;
            temp->SetNext(0);
            return ans;
        }
    }
}

template <class T>
bool List<T>::IsFull()
{
    Element<T>* temp = new Element<T>();
    if (temp == NULL)
        return 1;
    else
    {
        delete temp;
        return 0;
    }
   return  1;
}

template <class T>
bool List<T>::IsEmpty()
{
    if (begin == 0)
        return 1;
    return 0;
}

template<class T>
inline void List<T>::Print()
{
    if (begin == 0)
        throw Exception("List is empty");
    else
    {
        Element<T>* temp = begin;
        while (temp->GetNext() != 0)
        {
            std::cout << temp->GetData() << " ";
            temp = temp->GetNext();
        }
        std::cout << temp->GetData() << " ";
    }
}
