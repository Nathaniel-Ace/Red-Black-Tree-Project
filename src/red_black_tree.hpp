#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <memory>
#include <string>
#include <vector>

// Enum für die Farben der Knoten
enum class Color { Red, Black };

// Definition eines Knotens
struct Node {
    std::string key;
    Color color;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(std::string k, Color c, std::shared_ptr<Node> l = nullptr, std::shared_ptr<Node> r = nullptr)
        : key(std::move(k)), color(c), left(l), right(r) {}
};

// Red-Black-Tree Klasse
class RedBlackTree {
public:
    // Füge ein Wort in den Baum ein und gebe den neuen Baum zurück
    std::shared_ptr<Node> insert(const std::shared_ptr<Node>& root, const std::string& key);

    // In-Order-Traversierung, um die Wörter sortiert zu erhalten
    std::vector<std::string> in_order(const std::shared_ptr<Node>& root) const;

private:
    // Hilfsfunktionen für das Einfügen und Balancieren
    std::shared_ptr<Node> balance(const std::shared_ptr<Node>& node);
    std::shared_ptr<Node> rotate_left(const std::shared_ptr<Node>& node);
    std::shared_ptr<Node> rotate_right(const std::shared_ptr<Node>& node);
    std::shared_ptr<Node> make_black(const std::shared_ptr<Node>& node);
};

#endif // RED_BLACK_TREE_HPP
