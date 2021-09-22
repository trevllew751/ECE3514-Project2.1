#include "catch.hpp"
#include "LinkedList.hpp"

TEST_CASE( "Test construction" )
{
	INFO( "Hint: Checking basic construction" );
	LinkedList<int> ll;
	REQUIRE( ll.isEmpty() );
	REQUIRE( ll.getLength() == 0 );
}
