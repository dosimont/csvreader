/*
 * CSVRow.h
 *
 *  Created on: 20 juin 2013
 *      Author: dosimont
 */

#ifndef CSVROW_H_
#define CSVROW_H_

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class CSVRow
{
    public:
        string const& operator[](size_t index) const;
        size_t size() const;
        void readNextRow(istream& str);
        CSVRow(char separator);

    private:
        vector<string>    m_data;
        char separator;
};

istream& operator>>(istream& str,CSVRow& data);


#endif /* CSVROW_H_ */
