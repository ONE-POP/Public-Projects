#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <map>





using namespace std;

void removeMegas(string fileName) {
    ifstream file(fileName + ".txt"); 
    if (file.is_open()) { 


        ofstream outputFile("OnlyUniquePokemon.txt");

        if (outputFile.is_open()) {
            int i = 0;
            string namePrev = "";
            string nameCurr;
            string line;

            while (getline(file, line)) {
                // cout << "HERE: name = " << name << endl;

                // Create a stringstream from the line
                stringstream ss(line);
                string word;
                vector<string> words;

                // Parse each word separated by spaces
                while (ss >> word) {
                    words.push_back(word);
                }
                nameCurr = words.at(0);


                // if a variant then DO NOT add it to the list
                if (nameCurr != namePrev) {
                    ++ i;
                    outputFile << line << endl;
                    cout << "RAN HERE " << i << endl;
                    namePrev = nameCurr;
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
        cout << "Unable to open file" << endl; 
    }

    return;
}


long int uniqueNumber(string line) {

    map<char, int> dict;

    // Insert key-value pairs into the map
    dict['a'] = 2;
    dict['b'] = 3;
    dict['c'] = 5;
    dict['d'] = 7;
    dict['e'] = 11;
    dict['f'] = 13;
    dict['g'] = 17;
    dict['h'] = 19;
    dict['i'] = 23;
    dict['j'] = 29;
    dict['k'] = 31;
    dict['l'] = 37;
    dict['m'] = 37;
    dict['n'] = 41;
    dict['o'] = 43;
    dict['p'] = 47;
    dict['q'] = 53;
    dict['r'] = 59;
    dict['s'] = 61;
    dict['t'] = 67;
    dict['u'] = 71;
    dict['v'] = 73;
    dict['w'] = 79;
    dict['x'] = 83;
    dict['y'] = 89;
    dict['z'] = 97;
    dict[' '] = 101;
    dict['-'] = 103;
    dict['.'] = 107;
    dict['\''] = 109;
    dict[':'] = 113;
    dict['2'] = 127;

    char letter;
    long int number = 1;
    for (int i = 0; i < line.size(); ++ i) {
        letter = tolower(line.at(i));
        number *= dict[letter];
    }
    cout << "(" << line << ", " << number << ")" << endl;

    return number;
}



void makeSortedList(string fileName) {


    // custom compare function that compares the number in the pair 
    struct compareByFirst {
        bool operator()(const pair<long int, string>& a, const pair<long int, string>& b) const {
            return a.first > b.first;
        }
    };

    // intilaize the priority queue
    priority_queue<pair<long int, string>, vector<pair<long int, string>>, compareByFirst> pq;


    ifstream file(fileName + ".txt"); 
    if (file.is_open()) { 


        ofstream outputFile("SortedList.txt");

        if (outputFile.is_open()) {            
            string name;
            while (file >> name) {
                // cout << "HERE: name = " << name << endl;
                // cout << "here" << endl;
                pq.push(make_pair(uniqueNumber(name), name));
            }


            int size = pq.size();
            for (int i = 0; i < size; ++ i) {
                outputFile << pq.top().first << " " << pq.top().second << endl;
                pq.pop();
            }




            outputFile.close();
            cout << "Sorted List has been successfully written to SortedList.txt" << endl;
        } else {
            cout << "Error creating txt file" << endl;
            return;
        }

        file.close(); // Close file
    } else {
        cout << "Unable to open file" << endl; 
    }

    return;
}




void unscramble(string fileName){

    // set the vector
    vector<pair<int long, string>> vec;

    ifstream file(fileName + ".txt"); 
    long int number;
    string word;

    if (file.is_open()) { 
        while (file >> number) {
            file >> word;
            vec.push_back(make_pair(number, word));
            cout << vec.size() << endl;
        }
        cout << "ENDED HERE !!!! : (" << vec.at(vec.size() - 1).first << ", " << vec.at(vec.size() - 1).second << ")" << endl;
        file.close(); // Close file
    } else {
        cout << "Unable to open file" << endl; 
    }




    int again = 1;
    while (again) {
        cout << "Scrambled Word: ";
        string scrambled;
        cin >> scrambled;
        cout << endl;
        
        long int uniqueNum = uniqueNumber(scrambled);

        int start = 0;
        int end = vec.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long int currNum = vec.at(mid).first;
            cout << "Ran HERE: (" << currNum << ", " << uniqueNum << endl;

            if (currNum == uniqueNum) {
                cout << "Could Be: " << vec.at(mid).second << endl;

                // above
                int above = mid + 1;
                while (above != vec.size()) {
                    currNum = vec.at(above).first;
                    if (currNum == uniqueNum) {
                        cout << "Could Be: " << vec.at(above).second << endl;
                        ++ above;
                    } else {
                        break;
                    }
                }

                // below
                int below = mid - 1;
                while (below < 0) {
                    currNum = vec.at(below).first;
                    if (currNum == uniqueNum) {
                        cout << "Could Be: " << vec.at(below).second << endl;
                        -- below; 
                    } else {
                        break;
                    }
                }
                break;

            } else if (currNum < uniqueNum) {
                start = mid + 1;
                cout << "RAN curr < unique: (" << start << ", " << end << ")"<< endl;
            } else {
                end = mid - 1;
                cout << "RAN curr > unique: (" << start << ", " << end << ")"<< endl;
            }
        }
        string fin;
        cout << "!!! Finished !!!" << endl << endl << "Try Another? [y/n] : ";
        cin >> fin;
        cout << endl;
        
        if (fin == "y" || fin == "Y") {
            again = 1;
        } else {
            again = 0;
        }
    }


}






int main() {


    // removeMegas("PokemonList");

    // makeSortedList("OnlyUniquePokemonEditedNoSpaces");


    unscramble("SortedList");




    return 1;
}