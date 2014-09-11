/*
 * CSVIterator.h
 *
 *  Created on: 20 juin 2013
 *      Author: dosimont
 */

#ifndef CSVITERATOR_H_
#define CSVITERATOR_H_

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "CSVRow.h"

using namespace std;

class CSVIterator
{
    public:
        typedef input_iterator_tag     iterator_category;
        typedef CSVRow                      value_type;
        typedef size_t                 difference_type;
        typedef CSVRow*                     pointer;
        typedef CSVRow&                     reference;

        CSVIterator(istream& str, char separator);
        CSVIterator();

        // Pre Increment
        CSVIterator& operator++();
        // Post increment
        CSVIterator operator++(int);
        CSVRow const& operator*()   const;
        CSVRow const* operator->()  const;

        bool operator==(CSVIterator const& rhs);
        bool operator!=(CSVIterator const& rhs);
    private:
        istream*       m_str;
        CSVRow         m_row;
        char separator;
};

#endif /* CSVITERATOR_H_ */
