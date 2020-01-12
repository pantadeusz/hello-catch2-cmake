#include <catch2/catch.hpp>

#include <db.hpp>
#include <map>
#include <memory>
#include <list>

using namespace std;
struct test_db {
  int id;
  string name;
};

ostream & operator<<(ostream &o, const test_db &d) {
    o<<"[" << d.id << ", " << d.name << "]";
    return o;
}

TEST_CASE("Basic database object operations", "[database_c][constructors]") {

  SECTION("The database object can be created") {

    REQUIRE_NOTHROW([]() { database_c<test_db> db; });
  }
  SECTION("Simple dependency injection works") {
    auto container = make_shared<map<int, test_db>>();
    database_c<test_db> db(container);
    REQUIRE_FALSE(db.get_container() == nullptr);
    REQUIRE(db.get_container() == container.get());
  }
}

TEST_CASE("Getting data from the database", "[database_c][get_all]") {
    auto container = make_shared<map<int, test_db>>();
    database_c<test_db> db(container);
    SECTION("simple get all is present") {
        REQUIRE_NOTHROW( db.get_all() );
    }
    SECTION("simple get all is present") {
        list<test_db> ret_list = db.get_all();
        REQUIRE(ret_list.size() == 0);
    }
    SECTION("simple get all is present") {
        (*container)[0] = {0,"testowy"};
        list<test_db> ret_list = db.get_all();
        REQUIRE(db.get_container() == container.get());
        REQUIRE(db.get_container()->size() ==1);
        REQUIRE(ret_list.size() == 1);
    }
}

SCENARIO("getting data from database","[database_c][bdd][get_all]") {
    auto container = make_shared<map<int, test_db>>();
    database_c<test_db> db(container);
    GIVEN("we have some data in database") {
        (*container)[0] = {0,"testowy"};
        (*container)[1] = {1,"Stefan"};
        (*container)[2] = {2,"testowy"};

        INFO((*container)[0]);
        WHEN("we get them from the database") {
            list<test_db> ret_list = db.get_all();

            THEN("the list should contain 3 elements") {
                CHECK(ret_list.size() == 3);
            }

            THEN("the list should contain element with the name Stefan") {
                test_db found;
                for (auto e:ret_list) {
                    if (e.name == "Stefan") found = e;
                }
                REQUIRE(found.name =="Stefan");
            }
        }
    }
}