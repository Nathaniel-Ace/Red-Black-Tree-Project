#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/tokenizer.hpp"

TEST_CASE("Testing strictly functional tokenize function") {
    SUBCASE("Basic tokenization") {
        std::string text = "Dies ist ein Test.";
        auto tokens = tokenize(text);
        CHECK(tokens == std::vector<std::string>{"dies", "ist", "ein", "test"});
    }

    SUBCASE("Tokenization with punctuation and hyphens") {
        std::string text = "Hallo, Welt! Wie-geht's dir?";
        auto tokens = tokenize(text);
        CHECK(tokens == std::vector<std::string>{"hallo", "welt", "wie", "geht", "s", "dir"});
    }

    SUBCASE("Tokenization with numbers and symbols") {
        std::string text = "C++ ist toll, aber 123 ist eine Zahl!";
        auto tokens = tokenize(text);
        CHECK(tokens == std::vector<std::string>{"c", "ist", "toll", "aber", "ist", "eine", "zahl"});
    }

    SUBCASE("Empty input") {
        std::string text = "";
        auto tokens = tokenize(text);
        CHECK(tokens.empty());
    }
}
