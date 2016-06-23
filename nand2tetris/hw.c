#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "chips.h"

/*
Testing chip_DMux
-----------------
| in | sel | a | b |
|  0 |   0 | 0 | 0 |
|  0 |   1 | 0 | 0 |
|  1 |   0 | 1 | 0 |
|  1 |   1 | 0 | 1 |
*/

static void test_chip_DMux()
{
	pin in;
	pin sel;
	pin a;
	pin b;

	pin valid_a[] = { 0, 0, 1, 0 };
	pin valid_b[] = { 0, 0, 0, 1 };

	printf( "Testing chip_DMux - Verified\n" );
	printf( "----------------------------\n" );
	printf( "| in | sel | a | b |\n" );

	for ( in = 0; in <= 1; in++ ) {

		for( sel = 0; sel <= 1; sel++ ) {
				
				chip_DMux( in, sel, &a, &b );
				assert( a == valid_a[2 * in + sel] );
				assert( b == valid_b[2 * in + sel] );
				printf( "| %2u | %3u | %u | %u |\n", in, sel, a, b );
			}
	}

	printf("\n");
	
	return;
}
/*
Testing chip_Mux
----------------
| a | b | sel | out |
| 0 | 0 |   0 |   0 |
| 0 | 0 |   1 |   0 |
| 0 | 1 |   0 |   0 |
| 0 | 1 |   1 |   1 |
| 1 | 0 |   0 |   1 |
| 1 | 0 |   1 |   0 |
| 1 | 1 |   0 |   1 |
| 1 | 1 |   1 |   1 |
*/

static void test_chip_Mux()
{
	pin a;
	pin b;
	pin sel;
	pin out;

	pin valid_out[] = { 0, 0, 0, 1, 1, 0, 1, 1 };


	printf( "Testing chip_Mux - Verified\n" );
	printf( "---------------------------\n" );
	printf( "| a | b | sel | out |\n" );

	for ( a = 0; a <= 1; a++ ) {

		for( b = 0; b <= 1; b++ ) {

			for( sel = 0; sel <= 1; sel++ ) {
				
				chip_Mux( a, b, sel, &out );
				assert( out == valid_out[4 * a + 2 * b + sel] );
				printf( "| %u | %u | %3u | %3u |\n", a, b, sel, out );
			}
		}
	}

	printf("\n");

	return;
}

/*
Testing chip_Xor
----------------
| a | b | out |
| 0 | 0 |   0 |
| 0 | 1 |   1 |
| 1 | 0 |   1 |
| 1 | 1 |   0 |
*/

static void test_chip_Xor()
{
	pin a;
	pin b;
	pin out;
	
	pin valid_out[] = { 0, 1, 1, 0 };
	
	printf( "Testing chip_Xor - Verified\n" );
	printf( "---------------------------\n" );
	printf( "| a | b | out |\n" );

	for( a = 0; a <= 1; a++ ) {
	
		for( b = 0; b <= 1; b++) {
		
			chip_Xor( a, b, &out );
			assert( out == valid_out[ 2 * a + b ] );
			printf( "| %u | %u | %3u |\n", a, b, out );
		}
	}

	printf("\n");

	return;
}

/*
Testing chip_Or
---------------
| a | b | out |
| 0 | 0 |   0 |
| 0 | 1 |   1 |
| 1 | 0 |   1 |
| 1 | 1 |   1 |
*/

static void test_chip_Or()
{
	pin a;
	pin b;
	pin out;
	
	pin valid_out[] = { 0, 1, 1, 1 };

	printf( "Testing chip_Or - Verified\n" );
	printf( "--------------------------\n" );
	printf( "| a | b | out |\n" );

	for( a = 0; a <= 1; a++ ) {
	
		for( b = 0; b <= 1; b++) {
		
			chip_Or( a, b, &out );
			assert( out == valid_out[ 2 * a + b ] );
			printf( "| %u | %u | %3u |\n", a, b, out );
		}
	}

	printf("\n");

	return;
}


/*
Testing chip_Not
----------------
| in | out |
|  0 |   1 |
|  1 |   0 |
*/

static void test_chip_Not()
{
	pin in;
	pin out;

	pin valid_out[] = { 1, 0 };

	printf( "Testing chip_Not - Verified\n" );
	printf( "---------------------------\n" );
	printf( "| in | out |\n" );
	
	for( in = 0; in <= 1; in++ ) {
		
		chip_Not( in, &out );
		assert( out == valid_out[ in ] );
		printf( "| %2u | %3u |\n", in, out );
	}

	printf("\n");

	return;
}

/*
Testing chip_And
----------------
| a | b | out |
| 0 | 0 |   0 |
| 0 | 1 |   0 |
| 1 | 0 |   0 |
| 1 | 1 |   1 |
*/

static void test_chip_And()
{
	pin a;
	pin b;
	pin out;

	pin valid_out[] = { 0, 0, 0, 1 };
	
	printf( "Testing chip_And - Verified\n" );
	printf( "---------------------------\n" );
	printf( "| a | b | out |\n" );

	for( a = 0; a <= 1; a++ ) {
	
		for( b = 0; b <= 1; b++) {
		
			chip_And( a, b, &out );
			assert( out == valid_out[ 2 * a + b ] );
			printf( "| %u | %u | %3u |\n", a, b, out );
		}
	}

	printf("\n");

	return;
}

int main()
{
	printf("\n");

	test_chip_Not();
	test_chip_And();
	test_chip_Or();
	test_chip_Xor();
	test_chip_Mux();
	test_chip_DMux();

	return 0;
}
