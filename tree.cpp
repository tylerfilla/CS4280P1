/*
 * Tyler Filla
 * CS4280 - P1
 */

#include "tree.h"

p1::tree::tree() : m_root(nullptr)
{
    m_root = new node {};
}

p1::tree::~tree()
{
    // Do a postorder traversal over all nodes and delete them
    visit_node_postorder(m_root, [](tree::node* node, unsigned int depth)
    { delete node; });
}

void p1::tree::add_word(const std::string& word)
{
    // If root is empty, add word to it
    if (m_root->m_words.size() == 0)
    {
        m_root->m_length = word.length();
        m_root->m_words.insert(word);
        return;
    }

    // Search for a position in the tree for the word
    // Insert the word at this position
    search(m_root, word.length(), [&](tree::node* node, tree::node* parent, bool side)
    {
        // If no node for this word was found
        if (node == nullptr)
        {
            // Create new node for the word
            node = new tree::node {};
            node->m_length = word.length();
            node->m_words.insert(word);

            // Add node to tree
            // A value of true for side indicates the node should be placed to the right
            if (side)
            {
                parent->m_child_right = node;
            }
            else
            {
                parent->m_child_left = node;
            }
        }
        else
        {
            // A node was found, so just add the word to it
            if (node->m_length == 0 || node->m_length == word.length())
            {
                node->m_length = word.length();
                node->m_words.insert(word);
            }
        }
    });
}
