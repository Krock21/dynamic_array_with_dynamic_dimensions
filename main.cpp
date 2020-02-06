#include <iostream>

/***
 * class used for identation
 */
class Printer {
public:
    static int indent;

    Printer() {
        indent += 2;
    }

    ~Printer() {
        indent -= 2;
    }

    void printIndent() {
        for (int i = 0; i < indent; ++i) {
            std::cout << " ";
        }
    }
};

int Printer::indent = 0;

// elements_type
typedef std::string elements_type;

void **initialize_array(int dimensions_count, elements_type &prefix, int elements = 2) {
    if (dimensions_count == 1) {
        void **ans;
        ans = (void **) new elements_type[elements];
        for (int i = 0; i < elements; ++i) {
            prefix.push_back('0' + i); // TODO get rid of dependency on elements_type
            *((elements_type *) ans + i) = prefix;
            prefix.pop_back(); // TODO get rid of dependency on elements_type
        }
        return ans;
    }
    void **arr = new void *[elements];
    for (int i = 0; i < elements; ++i) {
        prefix.push_back('0' + i); // TODO get rid of dependency on elements_type
        arr[i] = initialize_array(dimensions_count - 1, prefix, elements);
        prefix.pop_back(); // TODO get rid of dependency on elements_type
    }
    return arr;
}

void print_array(void **arr, int dimensions_count, int elements = 2) {
    Printer kek;
    std::cout << dimensions_count - 1 << ":\n";
    if (dimensions_count == 1) {
        kek.printIndent();
        for (int i = 0; i < elements; ++i) {
            std::cout << *(((elements_type *) arr) + i) << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = 0; i < elements; ++i) {
            kek.printIndent();
            print_array((void **) arr[i], dimensions_count - 1, elements);
        }
    }
}

int main() {
    int dimensions_count, elements_count;
    std::cout << "Write dimensions count and elements count in each dimension:\n";
    std::cin >> dimensions_count >> elements_count;
    elements_type prefix = "";
    void **arr = initialize_array(dimensions_count, prefix, elements_count);
    print_array(arr, dimensions_count, elements_count);
    return 0;
}