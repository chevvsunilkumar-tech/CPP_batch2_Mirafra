#include <iostream>
#include <memory>

using namespace std;

enum error {
    engin_error = 101,
    power_supply_error,
    speed_error=120,
    lock_error,
    safety_error=90
};


class Error_bst
{
private:
 struct Node {
    int error_id;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node(int value) : error_id(value) {}
};

    std::unique_ptr<Node> root;

public:
    void error_generate(int value)
    {
        error_generate_Impl(root, value);
    }

    bool search(int value) const
    {
        return searchImpl(root.get(), value);
    }

    void error_solved(int value)
    {
        error_solved_Impl(root, value);
    }

    void inorder() const
    {
        inorderImpl(root.get());
        cout << "\n";
    }

private:
    void error_generate_Impl(std::unique_ptr<Node>& node, int id)
    {
        if (!node)
        {
            node = std::make_unique<Node>(id);
            return;
        }

        if (id < node->error_id)
            error_generate_Impl(node->left, id);
        else if (id > node->error_id)
            error_generate_Impl(node->right, id);
    }

    bool searchImpl(const Node* node, int id) const
    {
        if (!node) return false;
        if (id == node->error_id)
            return true;
        else if (id < node->error_id)
            return searchImpl(node->left.get(), id);
        else
            return searchImpl(node->right.get(), id);
    }

    void error_solved_Impl(std::unique_ptr<Node>& node, int id)
    {
        if (!node)
            return;

        if (id < node->error_id)
            error_solved_Impl(node->left, id);
        else if (id > node->error_id)
            error_solved_Impl(node->right, id);
        else
        {
            if (!node->left && !node->right)
            {
                node.reset();
            }
            else if (!node->left)
            {
                node = std::move(node->right);
            }
            else if (!node->right)
            {
                node = std::move(node->left);
            }
            else
            {
                Node* minNode = node->right.get();
                while (minNode->left)
                    minNode = minNode->left.get();

                node->error_id = minNode->error_id;
                error_solved_Impl(node->right, minNode->error_id);
            }
        }
    }

    void inorderImpl(const Node* node) const
    {
        if (!node) return;
        inorderImpl(node->left.get());
        cout << node->error_id << " ";
        inorderImpl(node->right.get());
    }
};

int main()
{
    Error_bst tata_car;

    tata_car.error_generate(engin_error);
    tata_car.error_generate(power_supply_error);
    tata_car.error_generate(speed_error);
    tata_car.error_generate(lock_error);
    tata_car.error_generate(safety_error);

    cout << "all errors inserted: ";
    tata_car.inorder();

    tata_car.error_solved(speed_error);
    tata_car.error_solved(lock_error);

    cout << "after solving 2 errors: ";
    tata_car.inorder();

    if (tata_car.search(engin_error))
        cout << "engin_error found\n";
    if (tata_car.search(speed_error))
        cout << "speed_error found\n";

    return 0;
}

