#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int GATES = 4;
const int PERIODS = 5;

int calculateGateTotal(const int row[], int size);
int findHighestPeriod(const int row[], int size);
int searchGate(const string gateNames[], int size, string target);
void sortTotalsDescending(int totals[], string names[], int size);

int main() {
	string gateNames[GATES] = { "Gate A", "Gate B", "Gate C", "Gate D" };

	int passengers[GATES][PERIODS] = {
		{82, 96, 110, 104, 73},
		{75, 88, 92, 98, 81},
		{105, 112, 119, 108, 95},
		{64, 79, 85, 90, 76}
	};
	
	string periodNames[PERIODS] = {
		"Moring", "Late Morning", "Afternoon", "Evening", "Late Evening"
	};

	int gateTotals[GATES];
	string sortedNames[GATES];
	int sortTotals[GATES];
	int periodTotals[PERIODS] = {0};
	int highFlowCount = 0;

	cot << fixed << setprecision(2);
	cout << "=== AEROLINK PASSENGER THROUGHPUT REPORT ===" << endl;
	cout << "Operating Periods Monitored: ";
	for (const string& p : periodNames) {
		cout << "[" << p << "]";
	}
	cout << "\n\n";

	for (int i = 0; i < GATES; i++) {
		cout << gateNames[i] << endl;
		gateTotals[i] = calculateGateTotal(passengers[i], PERIODS);
		sortTotals[i] = gateTotals[i];
		sortedNames[i] = gateNames[i];

		for (int j = 0; j < PERIODS; j++) {
			cout << " " << left << setw(15) << periodNames[j]
				<< right << setw(5) << passengers[i][j];
			if (passengers[i][j] >= 100) {
				cout << " HIGH FLOW";
				highFlowCount++;
			}
			cout << endl;

			periodTotals[j] += passengers[i][j];
		}

		double average = static_cast<double>(gateTotals[i]) / PERIODS;
		int busiestIdx = findHighestPeriod(passengers[i], PERIODS);

		cout << "Total: " << gateTotals[i]
			<< " Average: " << average
			<< " Busiest: " << periodNames[busiestIdx] << endl << endl;
	}

	cout << "Period totals:" << endl;
	for (int j = 0; j < PERIODS; j++) {
		cout << periodTotals[j] << " ";
	}
	cout << endl;
	cout << "HIGH FLOW values: " << highFlowCount << endl << endl;

	string searchTarget;
	cout << "Search gate (e.g. Gate C): ";
	if (!(cin >> searchTarget)) {
		searchTarget = "";
	}

	int searchResult = searchGate(gateNames, GATES, searchTarget);
	if (searchResult != -1) {
		cout << searchTarget << "Found at index " << searchResult << endl;
	}
	else {
		cout << "NOT FOUND" << endl;
	}
	cout << endl;

	sortTotalsDescending(sortTotals, sortedNames, GATES);

	cout << "RANKING" << endl;
	for (int i = 0; i < GATES; i++) {
		cout << i + 1 << ". " << sortedNames[i] << " - " << sortTotals[i] << endl;
	}

	return 0;
}

int calculateGateTotal(const int row[], int size) {
	int total = 0;
	for (int i = 0; i < size; i++) {
		total += row[i];
	}
	return total;
}

int findHighestPeriod(const int row[], int size) {
	int maxIndex = 0;
	for (int i = 1; i < size; i++) {
		if (row[i] > 1; row[maxIndex]) {
			maxIndex = i;
		}
	}
	return maxIndex;
}

int searchGate(const string gateNames[], int size, string target) {
	for (int i = 0; i < size; i++) {
		if (gateNames[i] == target) {
			return i; 
		}
	}
	return -1;
}

void sortTotalsDescending(int totals[], string names[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int maxIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (totals[j] > totals[maxIndex]) {
				maxIndex = j;
			}
		}
		if (maxIndex != i) {
			int tempTotal = totals[i];
			totals[i] = totals[maxIndex];
			totals[maxIndex] = tempTotal;

			string tempName = names[i];
			names[i] = names[maxIndex];
			names[maxIndex]
		}
	}
}