#include "tokenizer.hpp"
#include <vector>
#include <string>
#include <cctype>

// Rekursive Funktion zur Verarbeitung des Textes
std::vector<std::string> tokenize_recursive(const std::string& text, size_t index, std::string current_word) {
    if (index == text.size()) {
        // Basisfall: Am Ende des Textes das letzte Wort hinzufügen, falls vorhanden
        if (!current_word.empty()) {
            return {current_word};
        }
        return {};
    }

    char current_char = text[index];

    if (std::isalpha(current_char)) {
        // Zeichen ist ein Buchstabe: Zum aktuellen Wort hinzufügen
        return tokenize_recursive(text, index + 1, current_word + static_cast<char>(std::tolower(current_char)));
    } else {
        // Zeichen ist kein Buchstabe
        if (!current_word.empty()) {
            // Wort abschließen und mit restlichen Tokens kombinieren
            auto rest_tokens = tokenize_recursive(text, index + 1, "");
            std::vector<std::string> tokens = {current_word};
            tokens.insert(tokens.end(), rest_tokens.begin(), rest_tokens.end());
            return tokens;
        } else {
            // Kein aktuelles Wort, überspringe das Zeichen
            return tokenize_recursive(text, index + 1, "");
        }
    }
}

// Hauptfunktion zur Tokenisierung: Ruft die rekursive Funktion auf
std::vector<std::string> tokenize(const std::string& text) {
    return tokenize_recursive(text, 0, "");
}
