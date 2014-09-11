/*
 * CSVIterator.h
 *
 *  Created on: 20 juin 2013
 *      Author: dosimont
 */

#include "CSVIterator.h"


        CSVIterator::CSVIterator(std::istream& str, char separator)  :m_str(str.good()?&str:NULL), separator(separator), m_row(CSVRow(separator)) { ++(*this); }
        CSVIterator::CSVIterator()                   :m_str(NULL),separator(0) {}

        // Pre Increment
        CSVIterator& CSVIterator::operator++()               {if (m_str) { (*m_str) >> m_row;m_str = m_str->good()?m_str:NULL;}return *this;}
        // Post increment
        CSVIterator CSVIterator::operator++(int)             {CSVIterator    tmp(*this);++(*this);return tmp;}
        CSVRow const& CSVIterator::operator*()   const       {return m_row;}
        CSVRow const* CSVIterator::operator->()  const       {return &m_row;}

        bool CSVIterator::operator==(CSVIterator const& rhs) {return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL)));}
        bool CSVIterator::operator!=(CSVIterator const& rhs) {return !((*this) == rhs);}

