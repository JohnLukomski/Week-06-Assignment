//***************************************
//	Week 06 Assignment
// 
//	Author: John Lukomski
//	Date: 07/01/22
//***************************************

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//declare constant variables
const int NUM_OF_COLUMNS = 5,
NUM_OF_ROWS = 10,
NAME_SPACING = 15,
SCORE_SPACING = 10,
NAME_TITLE_SPACING = NAME_SPACING - 2,
SCORE_TITLE_SPACING = SCORE_SPACING * NUM_OF_COLUMNS;

//prototypes of the functions
bool GetBowlingData(string bNames[], int bScores[][NUM_OF_COLUMNS], ifstream& inData);
int GetAverageScore(int bScores[][NUM_OF_COLUMNS],int currRow);
void PrettyPrintResults(int bScores[][NUM_OF_COLUMNS], string bNames[], int avgBScores[]);

int main()
{
	//declare variables
	ifstream inFile;
	int bowlingScores[NUM_OF_ROWS][NUM_OF_COLUMNS], 
		avgBowlingScores[NUM_OF_ROWS];
	string bowlingNames[NUM_OF_ROWS];
	bool successful;

	//open input file
	inFile.open("BowlingScores.txt");

	//call GetBowlingData and assign the returning bool value to the variable successful
	successful = GetBowlingData(bowlingNames, bowlingScores, inFile);
	//test if the input is valid
	if (successful == true)
	{
		//assign every value returned by GetAverageScore to its appropriate component of avgBowlingScores
		for (int i = 0; i < NUM_OF_ROWS; i++)
		{
			avgBowlingScores[i]=GetAverageScore(bowlingScores, i);
		}
		//call the function PrettyPrintResults
		PrettyPrintResults(bowlingScores, bowlingNames, avgBowlingScores);
	}
	//if the input isn't valid, terminate the program
	else
	{
		cout << "Input Failure" << endl;
		system("pause");
		return 1;
	}
	//close the open input file
	inFile.close();

	system("pause");
	return 0;
}

//function to input the name and scores from the input file to the appropriate arrays
bool GetBowlingData(string bNames[], int bScores[][NUM_OF_COLUMNS], ifstream& inData)
{
		for (int i = 0; i < NUM_OF_ROWS; i++)
		{
			//input the bowlers' names into bNames
			inData >> bNames[i];
			for (int j = 0; j < NUM_OF_COLUMNS; j++)
			{
				//input the bowlers' scores into bScores
				inData >> bScores[i][j];
			}
		}
		//test if the data inputed correctly
	if (inData)
		return true;
	else
		return false;

}

//function to calculate the average of the bowlers' scores and input them
int GetAverageScore(int bScores[][NUM_OF_COLUMNS], int currRow)
{
	//declare local variables
	double sumScores = 0.0;
	int avgScores = 0;

	{
		for (int j = 0; j < NUM_OF_COLUMNS; j++)
		{
			//add each score to the total sum of each individual bowler
			sumScores += bScores[currRow][j];
		}
		//round the average score up or down (adding 0.5 will result in the appropriate integer truncating)
		avgScores = (sumScores / NUM_OF_COLUMNS) + 0.5;
		
		return avgScores;
	}

}

//function to output the data in the three arrays to the screen in an organized format
void PrettyPrintResults(int bScores[][NUM_OF_COLUMNS], string bNames[], int avgBScores[])
{
	//display the catagories with the correct spacing
	cout << left << setw(NAME_TITLE_SPACING) << "Name:" << setw(SCORE_TITLE_SPACING) << "Scores:" << "Average:" << endl;

	//display the name, scores, and score average spaced under their appropriate catagory
	for (int i = 0; i < NUM_OF_ROWS; i++)
	{
		cout << left << setw(NAME_SPACING) << bNames[i];
		for (int j = 0; j < NUM_OF_COLUMNS; j++)
		{
			cout << setw(SCORE_SPACING) << bScores[i][j];
		}
		cout << avgBScores[i] << endl;
	}
}


/*Code I Didn't Use:

//		FIRST_POS = 0,

//		cout << bNames[i] << endl;

//		cout << bScores[i][j]<< "      ";

//		cout << endl;

//		cout << "Row number " << currRow << " column number " << j << " and sum =  " << sumScores << " " << endl;

//		cout << "average =  "<< sumScores / NUM_OF_COLUMNS<<endl;

*/