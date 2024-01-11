#include <iostream>

class Widget {
private:
    std::string name;
    struct Node {
        Widget* widget;
        Node* next;
    };
    Node* children;

public:
    Widget(std::string n) : name(n), children(nullptr) {}

    void add(Widget* child);

    void print(const std::string& prefix = "");

    ~Widget() {
        Node* current = children;
        while (current) {
            Node* next = current->next;
            delete current->widget;
            delete current;
            current = next;
        }
    }
};

class Button : public Widget {
public:
    Button(std::string n) : Widget(n) {}
};

class Edit : public Widget {
public:
    Edit(std::string n) : Widget(n) {}
};

void Widget::add(Widget* child) {
        Node* new_node = new Node{child, nullptr};
        if (!children) {
            children = new_node;
        } else {
            Node* current = children;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

void Widget::print(const std::string& prefix = ""){
        std::cout << prefix << name << std::endl;
        Node* current = children;
        while (current) {
            current->widget->print(prefix + name + " ");
            current = current->next;
        }
    }

int main() {
    Button *yes = new Button("yes");
    Button *no = new Button("no");
    Widget *panel = new Widget("panel");
    panel->add(yes);
    panel->add(no);
    Edit *edit = new Edit("edit");
    Widget *window = new Widget("window");
    window->add(panel);
    window->add(edit);
    window->print();
    delete window;
    return 0;
}
