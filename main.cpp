#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

string namesArray[99] = {""};
string numbersArray[99] = {""};
int arraySize = 0;

    //input Function
    void getData(){
        //Filling the arrays with the contact information
        cout<<"Please enter a contact name: "<<endl;
        cin.ignore();
        string line;
        getline(cin, line);
        namesArray[arraySize] = line;
        cout<<"Please enter a number for " << namesArray[arraySize]<< " :" <<endl;
        cin.ignore();
        getline(cin, line);
        numbersArray[arraySize] = line;
        arraySize++;
    }

    void loadData(){
        ifStream dataFile(s: "data.txt");
        if(dataFile.fail()){
            //file could not be opened
        }else{
            //Load Data
            string line;
            bool isName=true;
            while (getline(dataFile, line)){
                if(line != ""){
                    if(isName){
                        namesArray[arraySize] = line;
                        isName = false;
                    }else{
                        numbersArray[arraySize] = line;
                        isName = true;
                        arraySize++;
                    }
                }
            }
        }
    }

    void save(){
        ofstream myfile;
        myfile.open(s: "data.txt");
        fot (int i=0; i<arraySize; i++){
            myfile << namesArray[I] + "\n";
            myfile << numbersArray[I] + "\n";
        }
        myfile.closed();
    }

    //Sorting Acending order
    void sortAce(){
        string temp = "";
        int index = -1;
        int pass = -1;

        for (pass = 0; pass < arraySize; pass++){
            for (index = 0; index < arraySize -1 - pass; index++){
                if(numbersArray[index] > numbersArray[index +1]){
                    //swap the current number array ppsition with next in array
                    temp = numbersArray[index];
                    numbersArray[index] = numbersArray[index +1];
                    numbersArray[index + 1] + temp;

                    //swapping current name array positon with next in array
                    temp = namesArray[index];
                    namesArray[index] = namesArray[index +1];
                    namesArray[index + 1] + temp;
                }
            }
        }
    }

    void sortDec() {
        string temp = "";
        int index = -1;
        int pass = -1;

        for (pass = 0; pass < arraySize; pass++){
            for (index = 0; index < arraySize - 1 - pass; index++){
                if ( numbersArray[index] < numbersArray[index + 1] ){

                    //swap current number array position with next in array
                    temp = numbersArray[index];
                    numbersArray[index] = numbersArray[index + 1];
                    numbersArray[index + 1] = temp;

                    //swap current name array position with next in array
                    temp = namesArray[index];
                    namesArray[index] = namesArray[index + 1];
                    namesArray[index + 1] = temp;
            }
        }
    }
}

//printing
void print(){
        for (int i=0; i<arraySize; i++){
            cout<<setw(2)<<i+1<<". "<<"Name: "<<setw(2)<<namesArray[i]<<" | "<<"Number: "<<setw(2)
            <<numbersArray[i]<<endl;
        }
    }
    //searching
    void search(){
        string searchTerm ="";
        int foundName = 0;
        cout<<"Please enter a name to find number"<<endl;
        cin>>searchTerm;
        for (int i=0; i <<arraySize; i++){
            if(searchTerm == namesArray[i]){
                cout<<"Number: "<<numbersArray[i]<<endl;
                foundName = 1;
            }
        }
        //If no name is found
        if(!foundName){
            cout<<"The name you entered was not found. Sorry!"<<endl;
        }
    }

    //menu operations
    void menuSelect(int choice){
        switch (choice) {
            case 1: getData();
                break;
            case 2: sortAce();
                break;
            case 3: sortDec();
                break;
            case 4: print();
                break;
            case 5: search();
                break;
            case 6: save();
                break;
        }
    }
int main() {
    loadData();
    printMenu();
    return 0;
}


//PROJECT REQUIREMENTS
//The program is to store individual names and associated telephone numbers in parallel arrays.
//The program should input from the user 10 people’s names and their telephone numbers and add the data to the parallel arrays.
//When data input is finished, the program should sort both data arrays in ascending order based on telephone numbers maintaining the associations between names and telephone numbers.
//The program will print the list of users and their telephone numbers after sorting.
//After printing the list, the program will ask for a name to search for.
//The user will then enter a name.
//The program will then search for the name and print the name and the associated telephone number for that person.
//If the person is not in the array, the program will print that the user cannot be found.
