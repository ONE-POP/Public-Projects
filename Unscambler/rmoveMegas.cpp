#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>


using namespace std;



void removeMegas(string fileName) {
    // // custom compare function that compares the number in the pair 
    // struct compareByFirst {
    //     bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
    //         return a.first > b.first;
    //     }
    // };

    // // intilaize the priority queue
    // priority_queue<pair<int, string>, vector<pair<int, string>>, compareByFirst> pq;

    // read from the txt file and store the word pair into the pq (min)
    ifstream file(fileName + ".txt"); 
    if (file.is_open()) { 
        string name;


        ofstream outputFile("OnlyUniquePokemon.txt");

        if (outputFile.is_open()) {
            while (file >> name) {
                // if a variant the DO NOT add it to the list
                if (!name.front() == '(') {
                    outputFile << name << endl;
                }
            }
            outputFile.close();
            cout << "Only megas have been successfully written to OnlyUniquePokemon.txt" << endl;
        } else {
            cout << "Error creating txt file" << endl;
            return;
        }

        file.close(); // Close file
    } else {
        std::cerr << "Unable to open file" << std::endl; 
    }

    return;
}






int main() {


    removeMegas("PokemonList");


    return 1;
}