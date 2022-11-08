/*
 * Unit testing for the Appointment class for final CS 2400 project
 */
//#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_MAIN  // Catch supplies a main program
#include "catch.hpp"
#include "../dictionary.h"

const int MAX_SCORE = 70;
static int score = 0;

TEST_CASE("Testing  Dictionary Class") {
    SECTION("Default Constructors") {
        Dictionary d;
        REQUIRE(0 == d.size());
    }
    SECTION("Insert & at") {
        Dictionary d;
        d.put("Name", "Bob");
        d.put("email", "bob@gmail.com");
        d.put("address", "12 Main St.");
        d.put("raNk", "Captain");
        d.put("Name", "Robert");

        REQUIRE("Robert" == d.get("Name"));
        REQUIRE("bob@gmail.com" == d.get("EMAIL"));
        REQUIRE("Captain" == d.get("RANK"));
        REQUIRE("12 Main St." == d.get("Address"));
        REQUIRE("NOT_FOUND" == d.get("SSN"));
        d.put("rank", "General");
        REQUIRE("General" == d.get("RANK"));
        score += 15;
    }
    SECTION("Size") {
        Dictionary d;
        d.put("Name", "Bob");
        d.put("email", "bob@gmail.com");
        d.put("email", "bob@gmail.com");
        d.put("email", "bob@gmail.com");
        d.put("address", "12 Main St.");
        d.put("raNk", "Captain");
        d.put("raNk", "Captain");
        d.put("raNk", "Captain");

        REQUIRE(4 == d.size());
        score += 5;
    }
    
    SECTION("Keys"){
        Dictionary d;
        vector<string> k1 = d.keys();
        REQUIRE(0 == k1.size());


        d.put("Name", "Bob");
        d.put("Name", "Bob");
        d.put("email", "bob@gmail.com");
        d.put("address", "12 Main St.");
        d.put("raNk", "Captain");
        d.put("raNk", "Captain");
        d.put("raNk", "Captain");

        vector<string> k = d.keys();
        REQUIRE(k[0] == "address");
        REQUIRE(k[1] == "email");
        REQUIRE(k[2] == "Name");
        REQUIRE(k[3] == "raNk");
        REQUIRE(4 == k.size());
        score += 10;

    }
    
    SECTION("Values"){
        Dictionary d;
        vector<string> v1 = d.keys();
        REQUIRE(0 == v1.size());

        d.put("Name", "Bob");
        d.put("email", "bob@gmail.com");
        d.put("address", "12 Main St.");
        d.put("raNk", "Captain");

        vector<string> v = d.values();
        REQUIRE(v[0] == "12 Main St.");
        REQUIRE(v[1] == "bob@gmail.com");
        REQUIRE(v[2] == "Bob");
        REQUIRE(v[3] == "Captain");
        REQUIRE(4 == v.size());
        score += 10;

    }
    
    SECTION("hasKeys"){
        Dictionary d;
        d.put("Name", "Bob");
        d.put("email", "bob@gmail.com");
        d.put("address", "12 Main St.");
        d.put("raNk", "Captain");
     
        REQUIRE(true == d.hasKey("EMAIL"));
        REQUIRE(false == d.hasKey("emails"));
        REQUIRE(false == d.hasKey(""));
        REQUIRE(true == d.hasKey("rank"));

        score += 5;

    }

    SECTION("hasValue"){
        Dictionary d;
        d.put("Name", "Bob");
        d.put("email", "bob@gmail.com");
        d.put("address", "12 Main St.");
        d.put("raNk", "Captain");
     
        REQUIRE(true == d.hasValue("12 Main St."));
        REQUIRE(false == d.hasValue("none"));
        REQUIRE(false == d.hasValue(""));
        REQUIRE(true == d.hasValue("bob@gmail.com"));
        score += 5;

    }

   SECTION("RemoveKey"){
        Dictionary d;
        d.put("Name", "Bob");
        d.put("email", "bob@gmail.com");
        d.put("address", "12 Main St.");
        d.put("raNk", "Captain");
        d.removeKey("email");

        vector<string> k = d.keys();
        REQUIRE(k[0] == "address");
        REQUIRE(k[1] == "Name");
        REQUIRE(k[2] == "raNk");
        REQUIRE(3 == k.size());
        d.removeKey("rank");
        vector<string> k2 = d.keys();
        REQUIRE(2 == k2.size());

        score += 10;
   }

   SECTION("RemoveValues"){
        Dictionary d;

        d.put("Name", "Bob");
        d.put("email", "bob@gmail.com");
        d.put("address", "12 Main St.");
        d.put("raNk", "Captain");
        d.put("rank2", "Captain");
        d.put("email2", "Captain");
        
        d.removeValues("Captain");
        vector<string> k = d.keys();
        REQUIRE(k[0] == "address");
        REQUIRE(k[1] == "email");
        REQUIRE(k[2] == "Name");
        REQUIRE(3 == k.size());
       
        vector<string> v = d.values();
        REQUIRE(v[0] == "12 Main St.");
        REQUIRE(v[1] == "bob@gmail.com");
        REQUIRE(v[2] == "Bob");
        REQUIRE(3 == v.size());
        score += 10;
   }


    SECTION("Score"){
        cout << "\033[1;35m" << "\n==========================================" << endl;
        cout << "\033[1;33m" <<  " Score: " << score << "/" << MAX_SCORE << "\033[1;35m" << endl;
        // << " (passed " << testsPassed <<  " out of " << NUM_TESTS << " tests)" << "\033[0m" << endl;
        cout << "==========================================\n" << "\033[0m" << endl;
    }
}

