#pragma once
#include <iostream>
#include <locale>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "Record.h"
template <class T>
	class SortForClasses
{
	static void swap(T& a, T& b);
	static void compare_swap(T& a, T& b, int(*pf_compare)(T& a, T& b));
public:
	static void selection_sort(T* a, int left, int right, int (*pfun_compare)(T& a, T& b));

};

template <class T>
void SortForClasses<T>::selection_sort(T* a, int left, int right, int(*pf_compare)(T& a, T& b))
{
    for (int i = left + 1; i < right; i++)
        for (int j = i; j > left; j--)
            compare_swap(a[j - 1], a[j], pf_compare);
}

template <class T>
void SortForClasses<T>::compare_swap(T& a, T& b, int(*pf_compare)(T& a, T& b))
{
    if (pf_compare(a, b) > 0)
        swap(a, b);
}

template <class T>
void SortForClasses<T>::swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

	namespace RecordCompare {
		int compare_fullName_ASC(Record& a, Record& b);
		int compare_cardNumber_ASC(Record& a, Record& b);
		int compare_date_ASC(Record& a, Record& b);  //реализации сравнения
		int compare_time_ASC(Record& a, Record& b);
		int compare_doctorName_ASC(Record& a, Record& b);
		int compare_doctorOffice_ASC(Record& a, Record& b);
		int compare_fullName_DESC(Record& a, Record& b);
		int compare_cardNumber_DESC(Record& a, Record& b);
		int compare_date_DESC(Record& a, Record& b);  //реализации сравнения
		int compare_time_DESC(Record& a, Record& b);
		int compare_doctorName_DESC(Record& a, Record& b);
		int compare_doctorOffice_DESC(Record& a, Record& b);
	}

