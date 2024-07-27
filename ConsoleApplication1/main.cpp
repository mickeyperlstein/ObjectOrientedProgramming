#define CATCH_CONFIG_MAIN

#include "survivor.h"
#include "tribe.h"

#include"catch2.hpp"

//void readTribe( Tribe& t );
//void readSurvivor( Survivor& s );

Survivor s = Survivor("Joe", 20, Survivor::IN_A_RELATIONSHIP);

TEST_CASE("Validity check") {
	auto  test_str = 
		"9879347834kldxhsadflkjh32986798345698543hksdhkjsdhfkjfesd~/";
	auto isok = 
		Survivor::isValidAlphanumericName(test_str);
	
	REQUIRE_FALSE(isok);



}


TEST_CASE("Test survivor minimal") {
	
	
	REQUIRE(20 == s.getAge());
	REQUIRE(strcmp( s.getName() , "Joe") == 0);
	REQUIRE(s.getStatus() == Survivor::IN_A_RELATIONSHIP);
	REQUIRE_FALSE(s.getStatus() == Survivor::MARRIED);

	
	REQUIRE_THROWS(s.setAge(200));



}

TEST_CASE("Tribes") {
	
	Tribe t = Tribe("The Hunters", 20);
	REQUIRE(t.getMaxSurvivors() == 20);
	t.addSurvivor(s);

	t.addSurvivor(Survivor("Joe", 19, Survivor::MARRIED));
	t.addSurvivor(Survivor("Hanna", 31, Survivor::SINGLE));
	t.addSurvivor(Survivor("Adam", 21, Survivor::IN_A_RELATIONSHIP));
	t.addSurvivor(Survivor("Efrat", 23, Survivor::MARRIED));
	t.addSurvivor(Survivor("Haim", 34, Survivor::SINGLE));
	t.addSurvivor(Survivor("Shawn", 25, Survivor::IN_A_RELATIONSHIP));
	t.addSurvivor(Survivor("Emily", 50, Survivor::SINGLE));

}
//void main()
//{
//
//	Tribe t1, t2;
//
//	t1.init( 20 );
//	t2.init( 20 );
//
//	cout << "Enter data for first tribe:\n";
//	readTribe( t1 );
//
//	cout << "Enter data for second tribe:\n";
//	readTribe( t2 );
//
//	t1.print();
//	t2.print();
//
//	int currentSurvivors = t1.getCurrentNumOfSurvivors();
//	for( int i = 0; i < currentSurvivors; i++ )
//		delete t1.getAllSurvivors()[i];
//
//	currentSurvivors = t2.getCurrentNumOfSurvivors();
//	for( int i = 0; i < currentSurvivors; i++ )
//		delete t2.getAllSurvivors()[i];
//
//	t1.free();
//	t2.free();
//
//	system( "pause" );
//}

void readSurvivor( Survivor& s )
{
	char name[Survivor::MAX_NAME_SIZE];
	cin.ignore(); // clean the buffer
	cout << "Enter your name: ";
	cin.getline( name, Survivor::MAX_NAME_SIZE );

	int age;
	cout << "Enter you age:  ";
	cin >> age;

	int statusNumber;
	cout << "Enter your status: \n 1.Single \n 2.Married \n 3.In A Relationship \n";
	cin >> statusNumber;

	s.init( name, age, ( Survivor::eFamilyStatus )statusNumber );
}
//
//void readTribe( Tribe& t )
//{
//	bool toContinue = true;
//	int indicator;
//
//	int maxSurvivors = t.getMaxSurvivors();
//	for( int i = 0; ( i < maxSurvivors ) && toContinue; i++ )
//	{
//		Survivor* s = new Survivor;
//		readSurvivor( *s );
//		t.addSurvivor( *s );
//
//		cout << "Continue? Press 1 for yes 2 for no \n";
//		cin >> indicator;
//
//		if( indicator == 2 )
//			toContinue = false;
//
//	}
//}

TEST_CASE("Survivor tests", "[survivor]") {
    Survivor s("Joe", 20, Survivor::IN_A_RELATIONSHIP);

    REQUIRE(s.getAge() == 20);
    REQUIRE(strcmp(s.getName(), "Joe") == 0);
    REQUIRE(s.getStatus() == Survivor::IN_A_RELATIONSHIP);
    REQUIRE_FALSE(s.getStatus() == Survivor::MARRIED);

    REQUIRE_THROWS(s.setAge(200));
    REQUIRE_NOTHROW(s.setAge(30));
    REQUIRE(s.getAge() == 30);

    REQUIRE(Survivor::isValidAlphanumericName("John123"));
    REQUIRE_FALSE(Survivor::isValidNameLen("John@33333fgdgfdghfhjfghjfghkjhgf123"));
    REQUIRE_FALSE(Survivor::isValidAlphanumericName("9879347834kldxhsadflkjh32986798345698543hksdhkjsdhfkjfesd~/"));
}

TEST_CASE("Tribe tests", "[tribe]") {
    const int MAX_SURVIVORS = 5;
    Survivor survivors[MAX_SURVIVORS] = {
        Survivor("Joe", 19, Survivor::MARRIED),
        Survivor("Hanna", 31, Survivor::SINGLE),
        Survivor("Adam", 21, Survivor::IN_A_RELATIONSHIP),
        Survivor("Efrat", 23, Survivor::MARRIED),
        Survivor("Haim", 34, Survivor::SINGLE)
    };
    const int numSurvivors = 5;

    SECTION("Tribe creation and population") {
        Tribe t("The Hunters", MAX_SURVIVORS);
        REQUIRE(t.getMaxSurvivors() == MAX_SURVIVORS);
        REQUIRE(t.getCurrentNumOfSurvivors() == 0);

        for (int i = 0; i < numSurvivors; ++i) {
            REQUIRE_NOTHROW(t.addSurvivor(survivors[i]));
            REQUIRE(t.getCurrentNumOfSurvivors() == i + 1);
        }

        REQUIRE_THROWS(t.addSurvivor(Survivor("Extra", 30, Survivor::SINGLE)));
    }

    SECTION("Survivor operations") {
        Tribe t("Test Tribe", MAX_SURVIVORS);
        for (int i = 0; i < numSurvivors; ++i) {
            t.addSurvivor(survivors[i]);
        }

       /* for (int i = 0; i < numSurvivors; ++i) {
            Survivor* found = t.findSurvivor(survivors[i].getName());
            REQUIRE(found != nullptr);
            REQUIRE(found->getAge() == survivors[i].getAge());
            REQUIRE(found->getStatus() == survivors[i].getStatus());
        }*/

       /* REQUIRE(t.findSurvivor("NonExistent") == nullptr);

        REQUIRE_NOTHROW(t.removeSurvivor("Hanna"));
        REQUIRE(t.getCurrentNumOfSurvivors() == numSurvivors - 1);
        REQUIRE_THROWS(t.removeSurvivor("NonExistent"));*/
    }
}