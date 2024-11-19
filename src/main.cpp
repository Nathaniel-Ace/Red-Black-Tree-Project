#include "file_io.hpp"
#include <vector>
#include <string>

int main() {
    // Lesen der Eingabedatei
    std::string text = read_file("../data/war_and_peace.txt");

    // Beispiel: Wörter sortieren und in eine Datei schreiben
    std::vector<std::string> sorted_words = {"Welt", "Hallo", "Test"};
    write_file("../data/output.txt", sorted_words);

    return 0;
}
