/* 
 * Lab11.cpp
 *
 * CS 121 Sec 03 - Bruce Bolden
 * Gabe Gibler
 * 2015 Apr 16
 *
 * Using binary search trees to create a TV show database; 
 * and retrieve and display info from it in various ways
 *
 */

#define TEST_OUTPUT

#include"utility.h"
std::string hr = "* * * * * * * * * *";

#include"linkedlist.h"
//#include"bstree.h"

int main( int argc, char *argv[] )
{
	std::string filename = "";
	std::string title, genre, source;
	int i, released, ended;
	linkedlist actors;

	div(hr);
	std::cout << "TV Shows" << std::endl;
	div(hr);
	
  if( argc > 1 ) {
		filename = argv[1];
		
	  if ( filename != "" ) {
	  	// Open file
			std::ifstream infile;
			infile.open(filename.c_str());
				
				if ( infile.is_open() ) {
				// Start separating out pieces of each entry
					std::string tmp, y;
					int segment = 1;
					
					while ( std::getline( infile, tmp ) ) {
						std::stringstream line1;

						switch ( segment ) {
							case 1:
								line1 << tmp;
								std::getline( line1, title, '(' );
								std::getline( line1, y, '-' );
								released = atoi( y.c_str() );
								std::getline( line1, y, ')' );
								ended = atoi( y.c_str() );
								segment++;
								break;
							case 2:
								genre = tmp;
								segment++;
								break;
							case 3:
								source = tmp;
								segment++;
								break;
							case 4:
								while ( tmp != "" ) {
									actors.add( tmp );
									std::getline( infile, tmp );
								}
								segment = 1;
								break;
							case 5:
								segment = 1;
							default:
								break;
						}
						#ifdef TEST_OUTPUT
						std::cout << "Results: " << title << "\n" << released << "-" << ended << "\n" << genre << "\n" << source << "\n";
						while ( actors.size() > 0 ) {
							std::cout << actors.last() << "\n";
							actors.remove( actors.last() );
						} 
						std::cout << std::endl;
						#endif 
					} // Looping through all entries
					infile.close();
					
					// Now, insert node of data into tree.
					// Then, customize a print function to verify data is getting added successfully.
					// Test.
					// Then, customize a print function for each desired result.
					
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
