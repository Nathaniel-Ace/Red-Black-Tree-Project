#include "red_black_tree.hpp"

// Einfügen eines neuen Knotens
std::shared_ptr<Node> RedBlackTree::insert(const std::shared_ptr<Node>& root, const std::string& key) {
    if (!root) {
        // Neuer Knoten wird immer rot erstellt
        return std::make_shared<Node>(key, Color::Red);
    }

    if (key < root->key) {
        auto new_left = insert(root->left, key);
        return balance(std::make_shared<Node>(root->key, root->color, new_left, root->right));
    } else if (key > root->key) {
        auto new_right = insert(root->right, key);
        return balance(std::make_shared<Node>(root->key, root->color, root->left, new_right));
    }

    // Schlüssel bereits vorhanden, Rückgabe des aktuellen Knotens
    return root;
}

// Balanciere den Baum nach Red-Black-Regeln
std::shared_ptr<Node> RedBlackTree::balance(const std::shared_ptr<Node>& node) {
    if (!node) return nullptr;

    if (node->color == Color::Black) {
        // Überprüfe Balancierungsregeln
        if (node->right && node->right->color == Color::Red) {
            return rotate_left(node);
        }
        if (node->left && node->left->color == Color::Red && node->left->left && node->left->left->color == Color::Red) {
            return rotate_right(node);
        }
        if (node->left && node->left->color == Color::Red && node->right && node->right->color == Color::Red) {
            return std::make_shared<Node>(node->key, Color::Red,
                                          make_black(node->left), make_black(node->right));
        }
    }

    return node;
}

// Linksdrehung
std::shared_ptr<Node> RedBlackTree::rotate_left(const std::shared_ptr<Node>& node) {
    auto new_root = node->right;
    return std::make_shared<Node>(new_root->key, node->color, 
                                   std::make_shared<Node>(node->key, Color::Red, node->left, new_root->left), 
                                   new_root->right);
}

// Rechtsdrehung
std::shared_ptr<Node> RedBlackTree::rotate_right(const std::shared_ptr<Node>& node) {
    auto new_root = node->left;
    return std::make_shared<Node>(new_root->key, node->color, 
                                   new_root->left, 
                                   std::make_shared<Node>(node->key, Color::Red, new_root->right, node->right));
}

// Knoten schwarz machen
std::shared_ptr<Node> RedBlackTree::make_black(const std::shared_ptr<Node>& node) {
    if (!node) return nullptr;
    return std::make_shared<Node>(node->key, Color::Black, node->left, node->right);
}

// In-Order-Traversierung
std::vector<std::string> RedBlackTree::in_order(const std::shared_ptr<Node>& root) const {
    if (!root) return {};

    auto left = in_order(root->left);
    left.push_back(root->key);
    auto right = in_order(root->right);
    left.insert(left.end(), right.begin(), right.end());

    return left;
}
