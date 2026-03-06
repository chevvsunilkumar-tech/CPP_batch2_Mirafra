#include <iostream>
#include <memory>
#include <optional>

using namespace std;

class temp_bst
{
    struct Node
    {
        int temp_id;
        float temp_reading;

        unique_ptr<Node> left;
        unique_ptr<Node> right;

        Node(int id, float reading)
            : temp_id(id), temp_reading(reading) {}

        // Compare by reading (BST ordered by reading)
        bool operator<(const Node& other) const
        {
            return temp_reading < other.temp_reading;
        }

        bool operator>(const Node& other) const
        {
            return temp_reading > other.temp_reading;
        }
    };

    unique_ptr<Node> root;

public:

    void insert_temp_data(int id, float reading)
    {
        insert_temp_data_Impl(root, id, reading);
    }

    optional<float> search(int id)
    {
        return search_Impl(root.get(), id);
    }

    optional<float> find_max()
    {
        return find_max_Impl(root);
    }

    optional<float> find_min()
    {
        return find_min_Impl(root);
    }

private:

    void insert_temp_data_Impl(unique_ptr<Node>& root, int id, float reading)
    {
        if (!root)
        {
            // Direct creation here (no temporary Node)
            root.reset(new Node(id, reading));
            return;
        }

        // Compare using operator overloading
        Node tempNode(id, reading);

        if (tempNode < *root)
            insert_temp_data_Impl(root->left, id, reading);
        else
            insert_temp_data_Impl(root->right, id, reading);
    }

    optional<float> search_Impl(Node* node, int id)
    {
        if (!node)
            return nullopt;

        if (node->temp_id == id)
            return node->temp_reading;

        if (auto left = search_Impl(node->left.get(), id))
            return left;

        return search_Impl(node->right.get(), id);
    }

    optional<float> find_max_Impl(const unique_ptr<Node>& root)
    {
        if (!root)
            return nullopt;

        Node* current = root.get();

        while (current->right)
            current = current->right.get();

        return current->temp_reading;
    }

    optional<float> find_min_Impl(const unique_ptr<Node>& root)
    {
        if (!root)
            return nullopt;

        Node* current = root.get();

        while (current->left)
            current = current->left.get();

        return current->temp_reading;
    }
};

int main()
{
    temp_bst tree;

    tree.insert_temp_data(1, 36.5);
    tree.insert_temp_data(2, 39.2);
    tree.insert_temp_data(3, 34.8);
    tree.insert_temp_data(4, 37.1);

    if (auto maxVal = tree.find_max())
        cout << "max temp: " << *maxVal << endl;

    if (auto minVal = tree.find_min())
        cout << "min temp: " << *minVal << endl;

    if (auto result = tree.search(3))
        cout << "finding id  3, temp =" << *result << endl;
    else
        cout << "id not found\n";

    return 0;
}

