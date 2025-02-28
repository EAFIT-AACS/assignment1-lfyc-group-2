// Include necessary libraries
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

// Define the DFA class
class DFA {
public:
    int numStates;  // Number of states in the DFA
    set<char> alphabet;  // Set of alphabet symbols
    vector<int> finalStates;  // List of final states
    vector<map<char, int>> transitionTable;  // Transition table storing transitions for each state

    // Constructor to initialize DFA with given parameters
    DFA(int states, set<char> alpha, vector<int> finals, vector<map<char, int>> table)
        : numStates(states), alphabet(alpha), finalStates(finals), transitionTable(table) {}

    // Function to minimize the DFA using Kozen's algorithm
    vector<pair<int, int>> findEquivalentStates() {
        // Step 1: Initialize the state comparison table with 'false' values (all states are initially assumed to be equivalent)
        vector<vector<bool>> stateComparisonTable(numStates, vector<bool>(numStates, false));

        // Step 2: Mark pairs of states where one is final and the other is not
        for (int p = 0; p < numStates; ++p) {
            for (int q = 0; q < numStates; ++q) {
                if ((find(finalStates.begin(), finalStates.end(), p) != finalStates.end()) !=
                    (find(finalStates.begin(), finalStates.end(), q) != finalStates.end())) {
                    stateComparisonTable[p][q] = true;  // Mark as different since one is a final state and the other is not
                }
            }
        }

        // Step 3: Iteratively refine the table by checking transitions
        bool changed;
        do {
            changed = false;
            for (int p = 0; p < numStates; ++p) {
                for (int q = 0; q < numStates; ++q) {
                    if (!stateComparisonTable[p][q]) {  // If the states are not already marked as different
                        for (char symbol : alphabet) {
                            int pNext = transitionTable[p][symbol];  // Get next state for p with given symbol
                            int qNext = transitionTable[q][symbol];  // Get next state for q with given symbol
                            if (stateComparisonTable[pNext][qNext]) {  // If destinations are already marked as different
                                stateComparisonTable[p][q] = true;  // Mark this pair as different
                                changed = true;  // Indicate that the table has changed
                                break;
                            }
                        }
                    }
                }
            }
        } while (changed);  // Repeat until no more changes occur

        // Step 4: Collect equivalent state pairs (pairs not marked as different)
        vector<pair<int, int>> equivalentStates;
        for (int p = 0; p < numStates; ++p) {
            for (int q = p + 1; q < numStates; ++q) {
                if (!stateComparisonTable[p][q]) {
                    equivalentStates.emplace_back(p, q);  // Store equivalent states
                }
            }
        }

        return equivalentStates;
    }
};

int main() {
    // Open the input file containing multiple DFA definitions
    ifstream file("file.txt");
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    
    int cases;
    file >> cases;  // Read the number of test cases (DFAs to process)
    cout << "Number of automata to minimize: " << cases << endl;
    cout << "Equivalent state pairs:" << endl;
    
    for (int i = 1; i <= cases; ++i) {
        int numStates;
        file >> numStates;  // Read number of states in the DFA
        
        set<char> alphabet;
        string alpha;
        file >> ws; getline(file, alpha);  // Read alphabet as a space-separated string
        stringstream alphaStream(alpha);
        char symbol;
        while (alphaStream >> symbol) {
            alphabet.insert(symbol);  // Store each character as a symbol in the alphabet set
        }

        vector<int> finalStates;
        string finals;
        getline(file, finals);  // Read final states as a space-separated string
        stringstream ss(finals);
        int temp;
        while (ss >> temp) finalStates.push_back(temp);  // Convert each number to an integer and store
        
        vector<map<char, int>> transitionTable(numStates);  // Initialize transition table
        for (int i = 0; i < numStates; ++i) {
            string line;
            getline(file, line);  // Read each transition row from the file
            stringstream lineStream(line);
            int state, nextState;
            lineStream >> state;  // Read the current state
            for (char symbol : alphabet) {
                if (!(lineStream >> nextState)) break;  // Read the next state for the current symbol
                transitionTable[state][symbol] = nextState;  // Store transition in the table
            }
        }
        
        // Create DFA object and find equivalent states
        DFA dfa(numStates, alphabet, finalStates, transitionTable);
        vector<pair<int, int>> equivalentStates = dfa.findEquivalentStates();
        
        // Print equivalent states for the current automaton
        cout << "Automaton " << i << ": ";
        for (auto &[p, q] : equivalentStates) {
            cout << "(" << p << ", " << q << ") ";
        }
        cout << endl;
    }
    file.close();  // Close the file after reading all cases
    return 0;
}