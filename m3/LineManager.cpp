////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////5 / 22 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "Utilities.h"
#include "Station.h"
#include "Workstation.h"
#include "LineManager.h"
using namespace sdds;
using namespace std;
LineManager::LineManager(const string& file, const vector<Workstation*>& stations) {
	Utilities util;
	string line;
	ifstream File(file);
	if (!File.is_open()) {
		throw "Unable to open the file.";
	}
	do
	{
		getline(File, line);
		size_t position = 0;
		bool more = true;
		string curS, nexS;
		Workstation* curW = nullptr;
		Workstation* nexW = nullptr;
		curS = util.extractToken(line, position, more);
		if (more) {
			nexS = util.extractToken(line, position, more);
		}
		for_each(stations.begin(), stations.end(), [&curW, &nexW, curS, nexS](Workstation* ws) {
			if (ws->getItemName() == curS) {
				curW = ws;
			}
			else if (ws->getItemName() == nexS) {
				nexW = ws;
			}
			});
		if (!m_activeLine.size()) {
			m_firstStation = curW;
		}
		curW->setNextStation(nexW);
		m_activeLine.push_back(curW);
	} while (!File.eof());
	File.close();
}
void LineManager::reorderStations() {
	vector<Workstation*> newS;
	Workstation* lastS = nullptr;
	size_t count = 0;
	do {
		for (size_t i = 0; i < m_activeLine.size(); i++) {
			if (m_activeLine[i]->getNextStation() == lastS) {
				lastS = m_activeLine[i];
				newS.push_back(m_activeLine[i]);
				count++;
				break;
			}
		}
	} while (count < m_activeLine.size());
	reverse(newS.begin(), newS.end());
	m_firstStation = newS[0];
	m_activeLine = newS;
}
bool LineManager::run(ostream& os) {
	bool empty = true;
    static int count = 0;
    count++;
	os << "Line Manager Iteration: " << count << endl;
	if (!g_pending.empty()) {
		(*m_firstStation) += move(g_pending.front());
		g_pending.pop_front();
	}
	for (size_t i = 0; i < m_activeLine.size(); i++) {
		m_activeLine[i]->fill(os);
	}
	for (size_t i = 0; i < m_activeLine.size(); i++) {
		m_activeLine[i]->attemptToMoveOrder();
	}
	for (size_t i = 0; i < m_activeLine.size(); i++) {
		if (!m_activeLine[i]->isEmpty()) {
			empty = false;
			break;
		}
	}
    return empty;
}
void LineManager::display(ostream& os) const {
	for (size_t i = 0; i < m_activeLine.size(); i++) {
		m_activeLine[i]->display(os);
	}
}