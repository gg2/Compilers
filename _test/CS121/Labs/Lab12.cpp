/* 
 * Lab 12
 *
 * CS 121 Sec 03 - Bolden
 * Gabe Gibler
 * 2015 Apr 20
 *
 */
 
//#define TEST_OUTPUT

#include"utility.h"
std::string hr = "* * * * * * * * * *";
#include"hash.h"

int main( int argc, char *argv[] )
{

	std::string filename = "";

	div(hr);
	std::cout << "Lab 12, Hash Table Dictionary" << std::endl;
	div(hr);
	
  if( argc > 1 ) {
		filename = argv[1];
		
	  if ( filename != "" ) 
	  {
	  	// Open file
			std::ifstream infile;
			infile.open(filename.c_str());
				
				if ( infile.is_open() ) 
				{
				// Start separating out pieces of each entry
					std::string tmp;
					
					while ( std::getline( infile, tmp ) ) {
						
						#ifdef TEST_OUTPUT
						std::cout << "Results: " << tmp << std::endl;
						#endif
						Insert( const_cast<char*>(tmp.c_str()) );
					} // Looping through all entries
					#ifdef TEST_OUTPUT
						std::cout << std::endl;
						PrintHashTable();
					#endif
					infile.close();
					
					PrintBucketCount();
					
					// Segment for searching for words in hash table
					std::cout << "Search for words in the list?";
					while ( confirm() ) 
					{
						std::cin.ignore();
						
						std::string SearchTerm;
						NListPtr SearchResult = NULL;
						std::cout << "Enter a word to search for: " << std::flush;

						std::getline( std::cin, SearchTerm );
						
						std::cout << "Searching ... \n";
						SearchResult = Lookup( const_cast<char*>(SearchTerm.c_str()) );
						
						if (SearchResult != NULL)
							std::cout << "Found: " << SearchResult->word << " \n" << std::endl;
						else
							std::cout << SearchTerm << " was not found in the list. \n" << std::endl;	

						std::cout << "Continue?";
					}
				} else {
				  // The file could not be opened
			  	std::cout << "File " << filename << " could not be opened.\n" << std::endl;
				} // File successfully opened and processed or not
	  } else {
	  	std::cout << "Filename may not be blank.\n" << std::endl;
	  } // Filename blank or not
  } else {
  	std::cout << "Filename must be provided at the command line.\n" << std::endl;
  } // Filename provided or not
  
	// Exit program
	div(hr);
	return 0;
}
