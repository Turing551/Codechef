#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main( ){
    int cases, i, j, numWords, sum = 0;
    bool dup_found;
    vector<string> words;                // list of words
    vector<int> times;                   // list of times to type each word
    string newWord;                      // variable to store word until it is added to list
    vector<string>::iterator it;         // iterator for the word vector   
    cin >> cases;  
    while ( cases > 0 ){
        cin >> numWords;                 // get number of words in test case
        words.clear();                   // clear both lists and sum befor each test case
        times.clear();
        sum = 0;  
        for ( i = 0; i < numWords; ++i ){
			// get word and reset duplicate flag
            cin >> newWord;
			dup_found = false;
            
            // if the word has already been typed, new time = 1/2 the first time
            for ( int x = 0; x < ( int ) words.size() && !dup_found; ++x ){
                if ( words[x] == newWord ){
                    times.push_back ( times[ x ] / 2 );
                    dup_found = true;
                }
            }
            words.push_back ( newWord );       
            // if word has not already been typed calculate time taken to type word
            if ( !dup_found ){
				// adding time for first letter
                times.push_back ( 2 );              
				// adding time for remaining letters
                for ( j = 1; j < ( int ) words[i].length(); ++j ){
                    times[i] += 2;                 
                    if ( ( words[ i ][ j ] == 'd' || words[ i ][ j ] == 'f' )
                            && ( words[ i ][ j - 1 ] == 'd' || words[ i ][ j - 1 ] == 'f' ) )
                    {
                        times[i] += 2;
                    }
                    
                    else if ( ( words[ i ][ j ] == 'j' || words[ i ][ j ] == 'k' )
                              && ( words[ i ][ j - 1 ] == 'j' || words[ i ][ j - 1 ] == 'k' ) )
                    {
                        times[i] += 2;
                    }
                }
            }
            
        }   
        for ( int time : times ) {
            sum += time;
        }     
        cout << sum << endl;     
        --cases;
    }
}
