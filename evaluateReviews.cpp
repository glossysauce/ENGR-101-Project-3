// Sophie Yang
// ricaroli 
// 042, 031
// <Date Submitted>

//------------------------------------------------------
// AUTOGRADER INFO -- IGNORE BUT DO NOT REMOVE 
// test_cases: true
// feedback('all')
// c269759b-5ea7-4702-bff4-ebc05443d45d
//------------------------------------------------------



// Add any #includes for C++ libraries here.
// We have already included iostream as an example.
#include <iostream>

// This #include adds all the function declarations (a.k.a. prototypes) from the
// reviews.h file, which means the compiler knows about them when it is compiling
// the main function below (e.g. it can verify the parameter types and return types
// of the function declarations match the way those functions are used in main() ).
// However, the #include does not add the actual code for the functions, which is
// in reviews.cpp. This means you need to compile with a g++ command including both
// .cpp source files. For this project, we will being using some features from C++11,
// which requires an additional flag. Compile with this command:
//     g++ --std=c++11 evaluateReviews.cpp reviews.cpp -o evaluateReviews
#include "reviews.h"

using namespace std;

const double SCORE_LIMIT_TRUTHFUL = 3;
const double SCORE_LIMIT_DECEPTIVE = -3;


int main(){
// open the file input stream

    // TODO: implement the main program
double highestScore = 0;
double lowestScore = 0;
int truthful = 3;
int deceptive = -3;

// Open a file input stream for the keywordWeights.txt file.*/
ifstream keyWordWeights_file("keyWordWeights.txt");
//check if the keyWordWeights file is open 
if(!keyWordWeights_file.is_open()){
    cout << "Error: keywordWeights.txt could not be opened." << endl;
    return 1;
}
//read the keywords and their weights into parallel vectors
vector<string> keywords;
vector<double> weights;
readKeywordWeights(keyWordWeights_file, keywords, weights);


/*3. For each hotel review,
    i. Create the filename (e.g. review00.txt) (Which Reviews library function would be helpful here?) 


    ii. Open a filestream to the file
    iii. Read each word of the review into a vector of string variables (Which Reviews library function would be helpful here?)
    iv. Calculate the review’s score (Which Reviews library function would be helpful here?)
    v. Determine the review’s category:
        - truthful: score > 3.0
        - deceptive: score < -3.0
        - uncategorized: otherwise
    vi. Track the review with the highest score and the review with the lowest score*/

    // create the file name 
    //using for loop since we need to go through like 100 reviews
    for(int i = 0; i < 100; i++){
        string reviewFileName = makeReviewFileName(i);
        //now open filestream for the file
        ifstream currentFile(reviewFileName);
        vector<string> reviewWords;
        readReview(currentFile, reviewWords);
    }



}
//for every file reviewed, rate if it is truthful, deceptive, or neither
for (size_t i = 0, i < keyWordWeights_file.size(); i++){
    if (reviewWeights(keyWordWeights_file, keywords, weights) > truthful){
        // set review rating as truthful
        if ((reviewWeights(fin, keywords, weights)) > highestScore){
            highestScore = score;
        }
    }
    else if (reviewWeights(fin, keywords, weights) < deceptive){
        // set review rating as deceptive
        if ((reviewWeights(fin, keywords, weights)) < lowestScore){
            lowestScore = score;
        }
    }
    else {
        // set review rating as uncategorized
    }
}

fin.close();
/*4. Write out a summary of the truthfulness and deceptiveness of the reviews to a file named report.txt*/
    
}



