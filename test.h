//
//  test.h
//  Pro
//
//  Created by Andrew Wilson on 6/21/20.
//  Copyright © 2020 Andrew Wilson. All rights reserved.
//

#ifndef test_h
#define test_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

typedef struct timespec timespec;

#pragma region // Test Macros

#define TEST_FUNC static int 

#define TEST( test_func )          \
	printf("Testing: %s\r\n", #test_func);  \
	result = test_func();                   \
	printf("\tresult: %d, %s\r\n\r\n", result, ( result == EXIT_SUCCESS ) ? "SUCCESS" : "FAILURE" );

#define TEST_ASSERT( boolean ) \
	if ( !( boolean ) ) { \
		printf( "\tFAILED ASSERT: %s\r\n", #boolean ); \
		return EXIT_FAILURE; \
	}

#define TEST_ASSERT_EQ( comp1, comp2 ) \
	if ( comp1 != comp2 ) { \
		printf( "\tFAILED EQ ASSERT: %s != %s\r\n", #comp1, #comp2 ); \
		return EXIT_FAILURE; \
	}

#define TEST_ASSERT_NOT_EQ( comp1, comp2 ) \
	if ( comp1 == comp2 ) { \
		printf( "\tFAILED NOT EQ ASSERT: %s == %s\r\n", #comp1, #comp2 ); \
		return EXIT_FAILURE; \
	}

#define TEST_BENCH( bench_func, iterations ) \
	timespec start, end; \
	printf( "Benchmarking: %s\r\n", #bench_func ) \
	clock_gettime( CLOCK_REALTIME, &start ); \
	for ( int i = 0; i < iterations; i++ )\
		bench_func(); \
	clock_gettime( CLOCK_REALTIME, &end ); \
	printf( "" )


#pragma endregion // Test Macros

TEST_FUNC test_()
{
	return EXIT_SUCCESS;
}

void test()
{
    int result = 0;
}


#endif /* test_h */
