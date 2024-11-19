#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/file_io.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

// Hilfsfunktion zum Erstellen einer Testdatei mit detaillierter Fehlerausgabe
void create_test_file(const std::string& file_path, const std::string& content) {
    std::cout << "Erstelle Testdatei: " << file_path << std::endl;
    std::ofstream file(file_path);
    if (!file) {
        std::cerr << "Fehler: Die Datei konnte nicht erstellt werden: " << file_path << std::endl;
    } else {
        file << content;
        file.close();
        std::cout << "Datei erfolgreich erstellt: " << file_path << std::endl;
    }
}

// Test für die Funktion read_file
TEST_CASE("Testing read_file function") {
    std::string test_file = "test_read_file.txt";  // Verwende einfachen Dateinamen
    std::string content = "Dies ist ein Testinhalt.";
    create_test_file(test_file, content);

    std::cout << "Lese Datei mit read_file: " << test_file << std::endl;
    std::string result = read_file(test_file);

    CHECK(result == content);  // Überprüfe, ob der Inhalt korrekt gelesen wurde
}

// Test für die Funktion write_file
TEST_CASE("Testing write_file function") {
    std::vector<std::string> words = {"Hallo", "Welt", "Test"};
    std::string test_file = "test_write_file.txt";  // Verwende einfachen Dateinamen

    std::cout << "Schreibe Wörter in die Datei: " << test_file << std::endl;
    write_file(test_file, words);

    std::ifstream file(test_file);
    if (!file) {
        std::cerr << "Fehler: Die Datei konnte nicht geöffnet werden: " << test_file << std::endl;
        return;
    }
    
    std::string line;
    std::vector<std::string> result;

    while (std::getline(file, line)) {
        result.push_back(line);
    }
    file.close();

    CHECK(result == words);  // Überprüfe, ob der Inhalt korrekt ist
}
