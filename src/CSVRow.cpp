/*
 * CSVRow.cpp
 *
 *  Created on: 20 janv. 2014
 *      Author: dosimont
 */

#include "CSVRow.h"


istream& operator>>(istream& str,CSVRow& data) {
    data.readNextRow(str);
    return str;
}

const string& CSVRow::operator [](size_t index) const {
	return m_data[index];
}

size_t CSVRow::size() const {
	return m_data.size();
}

void CSVRow::readNextRow(istream& str) {
    string         line;
    getline(str,line);

    stringstream   lineStream(line);
    string         cell;

    m_data.clear();
    while(getline(lineStream,cell, separator)) {
        m_data.push_back(cell);
    }
}

CSVRow::CSVRow(char separator) : separator(separator){
}
