#include "file_io.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

std::string read_file(const std::string& file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Fehler: Die Datei konnte nicht geöffnet werden: " << file_path << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); // Lesen des gesamten Datei-Inhalts in den Stringstream
    file.close();
    std::cout << "Datei erfolgreich gelesen: " << file_path << std::endl;
    return buffer.str(); // Rückgabe als std::string
}

void write_file(const std::string& file_path, const std::vector<std::string>& words) {
    std::ofstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Fehler: Die Datei konnte nicht geöffnet werden: " << file_path << std::endl;
        return;
    }

    for (const auto& word : words) {
        file << word << "\n"; // Jedes Wort auf eine neue Zeile schreiben
    }
    file.close();
}