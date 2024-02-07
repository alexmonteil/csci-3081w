#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Function converts a string to lowercase
string ToLowerCase(string inputString) {
    string outputString;
    for (char c : inputString) {
        outputString += tolower(c);
    }
    return outputString;
}

// Function calculates the mean average of a list of double
double CalculateListMean(vector<double> list) {
    double total;
    for (double num : list) {
        total += num;
    }

    return (total / list.size());
}

// Function displays summary of expenses to the console
void DisplaySummary(vector<string> participants, vector<double> expenses, double individualShare) {
    cout << "Expense Summary:\n";
    cout << setw(20) << "participant" << setw(20) << "amount" << setw(20) << "owes/owed\n";
    
    double difference;

    for (int i = 0; i < participants.size(); i++) {
        difference = expenses[i] - individualShare;
        cout << setw(20) << participants[i] <<
        setw(20) << "$" << fixed << setprecision(2) << expenses[i] << setw(15) << "$" << fixed << setprecision(2) << difference << "\n";
    }
}

int main() {
    
    // variables

    const string PARTICIPANT_PROMPT = "Enter participant name (or \'done\' to finish) ";
    const string EXPENSE_PROMPT = "Enter expense amount: ";
    const string EXIT_FLAG = "done";
    const string NEGATIVE_AMOUNT_PROMPT = "Expense must be positive, please enter a positive expense: ";
    string participantName;
    double expense;
    double individualShare;
    

    vector<string> participantList;
    vector<double> expenseList;

    // user input + error checking (only 2 decimal place, no negative expenses)

    while (true) {
        cout << PARTICIPANT_PROMPT;
        cin >> participantName;
        if (participantName == EXIT_FLAG || ToLowerCase(participantName) == EXIT_FLAG) {
            break;
        } 
        cout << EXPENSE_PROMPT;
        cin >> expense;
        while (expense < 0) {
            cout << NEGATIVE_AMOUNT_PROMPT;
            cin >> expense;
        }

        participantList.push_back(participantName);
        expenseList.push_back(expense);
    }


    // calculations

    individualShare = CalculateListMean(expenseList);

    // display information summary

    DisplaySummary(participantList, expenseList, individualShare);
    
    return 0;
}

