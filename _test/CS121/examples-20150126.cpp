struct IC_Entry {
	int iVal;
	char cVal;
}

const int MAX_IC_TABLE_SIZE = 10;
struct IC_Entry IC_Table[MAX_IC_TABLE_SIZE];

// init IC_Entry values in loop

char IntToChar( int i ) {
	return IC_Table[i].cVal;
}