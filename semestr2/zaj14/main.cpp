#include <iostream>

template<typename T>
class Vector {
private:
    // wskaźnik na elementy
    T* items;
    std::size_t capacity;
    std::size_t current_size;

public:
    Vector() : items(nullptr), capacity(0), current_size(0) {}

    T& operator[](std::size_t index);

    std::size_t size() const;

    void push_back(const T& value);
};

template<typename T>
T& Vector<T>::operator[](std::size_t index) {
        return items[index];
    }

template<typename T>
std::size_t Vector<T>::size() const {
        return current_size;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
        if (current_size == capacity) {
            // zwiększanie capacity w przypadku za małej wielkości wektora aby wstawić nowy element
            std::size_t new_capacity = capacity == 0 ? 1 : 2 * capacity;
            T* new_items = new T[new_capacity];
            // przepisywanie elementów w nowej kolejności
            for (std::size_t i = 0; i < current_size; ++i) {
                new_items[i] = items[i];
            }
            // zwalnianie pamięci z poprzedniej alokacji elementów
            delete[] items;
            items = new_items;
            capacity = new_capacity;
        }
        // inkrementacja informacji o wielkości
        items[current_size++] = value;
    }


int main() {
    Vector<std::string> vector;
    std::string e;
    
    while (std::cin >> e) {
        vector.push_back(e);
    }

    for (std::size_t i = 0; i < vector.size(); ++i) {
        std::cout << vector[i] << " ";
    }
    
    std::cout << std::endl;

    return 0;
}
