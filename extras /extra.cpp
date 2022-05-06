#include
#include
#include
#include
#include

using namespace std;

#define STUD_NAMES 5
#define STUD_GRADES 6

void sumStudentGrades(int grades[STUD_NAMES][STUD_GRADES], int sumArray[STUD_NAMES]);
void averageStudentGrades(int sumArray[STUD_NAMES], double average[STUD_NAMES]);
void getLetterGrade(double average[STUD_NAMES], char letterGrade[STUD_NAMES]);
void sortByName(string names[STUD_NAMES], int grades[STUD_NAMES][STUD_GRADES], int sumArray[STUD_NAMES], double average[STUD_NAMES], char letterGrade[STUD_NAMES]);
int searchStudent(string names[STUD_NAMES], int grades[STUD_NAMES][STUD_GRADES], int sumArray[STUD_NAMES], double average[STUD_NAMES], char letterGrade[STUD_NAMES]);

int main()
{
// declare a variables to hold file names
string nameFile = "stname.txt";
string gradesFile = "grades.txt";
string outFile = "out.txt";

// declare an arrays
string names[STUD_NAMES];
int grades[STUD_NAMES][STUD_GRADES];

// open files
ifstream inputfile;
inputfile.open(nameFile);

//Any error, print an error message and exit
if (!inputfile) {
cout << nameFile << " could not be opened. " << endl;
return 0;
}

//get the names in the stname.txt input file
int nameCount = 0;
string line;
while (getline(inputfile, line, '\n')) { //get the text line
names[nameCount] = line;
nameCount++;
}
inputfile.close();

inputfile.open(gradesFile);

//Any error, print an error message and exit
if (!inputfile) {
cout << gradesFile << " could not be opened. " << endl;
return 0;
}


// read the grades from the file grades.txt
for (int stud = 0; stud < STUD_NAMES; stud++) {
    for (int grad = 0; grad < STUD_GRADES; grad++) {
        inputfile >> grades[stud][grad];
    }
}
inputfile.close();

// Create output file stream
ofstream outputFile;
outputFile.open(outFile);

// declare an array to hold sum of the grades
int sumArray[STUD_NAMES];
// call function and find the sum of each student in the array
sumStudentGrades(grades, sumArray);

// declare an to hold average of each student
double average[STUD_NAMES];
// call function and store the results
averageStudentGrades(sumArray, average);
// declare an to hold letter grade of each student
char letterGrade[STUD_NAMES];
// call function and store the results
getLetterGrade(average, letterGrade);

// display students name, their grade, sum, average and letter grade into a fine
cout << fixed << setprecision(2);
for (int stud = 0; stud < STUD_NAMES; stud++) {
    cout << names[stud] << "\t";
    outputFile << names[stud] << " ";
    for (int grad = 0; grad < STUD_GRADES; grad++) {
        cout << grades[stud][grad] << " ";
        outputFile << grades[stud][grad] << " ";
    }
    cout << sumArray[stud] << "\t" << average[stud] << "\t" << letterGrade[stud] << endl;
    outputFile << sumArray[stud] << "\t" << average[stud] << "\t" << letterGrade[stud] << endl;

}

// sort the arrays by names
sortByName(names, grades, sumArray, average, letterGrade);


// print after sorting
cout << endl << "AFTER SORTING" << endl;
outputFile << endl << "AFTER SORTING" << endl;

for (int stud = 0; stud < STUD_NAMES; stud++) {
    cout << names[stud] << "\t";
    outputFile << names[stud] << " ";
    for (int grad = 0; grad < STUD_GRADES; grad++) {
    cout << grades[stud][grad] << " ";
    outputFile << grades[stud][grad] << " ";
    }
    cout << sumArray[stud] << "\t" << average[stud] << "\t" << letterGrade[stud] << endl;
    outputFile << sumArray[stud] << "\t" << average[stud] << "\t" << letterGrade[stud] << endl;

}

cout << endl;
outputFile << endl;

int foundIndex = searchStudent(names, grades, sumArray, average, letterGrade);

if (foundIndex != -1) {
cout << names[foundIndex] << "\t";
outputFile << "Search For " << names[foundIndex] << " Found" << endl;
outputFile << names[foundIndex] << "\t";
for (int grad = 0; grad < STUD_GRADES; grad++) {
cout << grades[foundIndex][grad] << " ";
outputFile << grades[foundIndex][grad] << " ";
}
cout << sumArray[foundIndex] << "\t" << average[foundIndex] << "\t" << letterGrade[foundIndex] << endl;
outputFile << sumArray[foundIndex] << "\t" << average[foundIndex] << "\t" << letterGrade[foundIndex] << endl;

}
else {
cout << "Searched Student NOT FOUND!!!" << endl;
outputFile << "Searched Student NOT FOUND!!!" << endl;
}

outputFile.close();

return 0;
}


// a function to find sum of each students grade and store it in array of sum
void sumStudentGrades(int grades[STUD_NAMES][STUD_GRADES], int sumArray[STUD_NAMES]) {
// iterate through the grades array and find the sum for each student
for (int stud = 0; stud < STUD_NAMES; stud++) {
sumArray[stud] = 0;
for (int grad = 0; grad < STUD_GRADES; grad++) {
sumArray[stud] += grades[stud][grad];
}
}
}

// another function to find average of each student, and stores it in array of average (type double)
void averageStudentGrades(int sumArray[STUD_NAMES], double average[STUD_NAMES]) {
average[0] = 0;
// iterate through the grades array and find the sum for each student
for (int stud = 0; stud < STUD_NAMES; stud++) {
average[stud] = (double)sumArray[stud] / (double)STUD_GRADES;
}
}

// another function to find letter grade for each student, stores it in array of letter grade(type character).
void getLetterGrade(double average[STUD_NAMES], char letterGrade[STUD_NAMES]) {
letterGrade[0] = 'F';
// iterate through the grades array and find the sum for each student
for (int stud = 0; stud < STUD_NAMES; stud++) {
if (average[stud] > 90) {
letterGrade[stud] = 'A';
}
else if (average[stud] > 80) {
letterGrade[stud] = 'B';
}
else if (average[stud] > 70) {
letterGrade[stud] = 'C';
}
else if (average[stud] > 50) {
letterGrade[stud] = 'D';
}
else {
letterGrade[stud] = 'F';
}
}
}

// sort array based on names
void sortByName(string names[STUD_NAMES], int grades[STUD_NAMES][STUD_GRADES], int sumArray[STUD_NAMES], double average[STUD_NAMES], char letterGrade[STUD_NAMES]) {
for (int i = 0; i < STUD_NAMES - 1; i++) {
for (int j = 0; j < STUD_NAMES - i - 1; j++) {
if (names[j] > names[j + 1]) {
// swap arr[j+1] and arr[j]
string ntemp = names[j];
names[j] = names[j + 1];
names[j + 1] = ntemp;

// sort grades array
int gtemp[STUD_GRADES];
for (int g = 0; g < STUD_GRADES; g++) {
gtemp[g] = grades[j][g];
}

for (int g = 0; g < STUD_GRADES; g++) {
grades[j][g] = grades[j + 1][g];
}

for (int g = 0; g < STUD_GRADES; g++) {
grades[j + 1][g] = gtemp[g];
}

int stemp = sumArray[j];
sumArray[j] = sumArray[j + 1];
sumArray[j + 1] = stemp;


double atemp = average[j];
average[j] = average[j + 1];
average[j + 1] = atemp;

char lTemp = letterGrade[j];
letterGrade[j] = letterGrade[j + 1];
letterGrade[j + 1] = lTemp;

}
}
}
}


// search for the student
int searchStudent(string names[STUD_NAMES], int grades[STUD_NAMES][STUD_GRADES], int sumArray[STUD_NAMES], double average[STUD_NAMES], char letterGrade[STUD_NAMES]) {
cout << "Enter name of the student to search: ";
string name;
getline(cin, name);

int foundIndex = -1;
for (int stud = 0; stud < STUD_NAMES; stud++) {
if (names[stud] == name) {
foundIndex = stud;
}
}
return foundIndex;

}