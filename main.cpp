#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int row;
    int col;
    int data;
    Node *next;
};

void create_new_node(Node **p, int row_index, int col_index, int x) {
    Node *temp = *p;
    Node *r;

    if (temp == NULL) {
        temp = new Node();
        temp->row = row_index;
        temp->col = col_index;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }

    else {
        while (temp->next != NULL)
            temp = temp->next;

        r = new Node();
        r->row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}

void printList(Node *start) {
    Node *ptr = start;
    cout << "row_position:";
    while (ptr != NULL) {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "column_position:";

    ptr = start;
    while (ptr != NULL) {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "Value:";
    ptr = start;

    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void functionForTask(Node *start) {
    vector<int> mass_rows;
    Node *str = start;
    while (str != NULL) {
        mass_rows.push_back(str->row);
        str = str->next;
    }
    vector<int> uniqeArr;
    for (int i = 0; i < mass_rows.size(); i++) {
        int k = 0;
        for (int j = i; j < mass_rows.size(); j++) {
            if (mass_rows[i] == mass_rows[j]) {
                k++;
            }
        }
        if (k == 1) {
            uniqeArr.push_back(mass_rows[i]);
        }
    }
    sort(uniqeArr.begin(), uniqeArr.end());
    vector<double> answer(uniqeArr.size());
    for (int i = 0; i < uniqeArr.size(); i++) {
        for (Node *ptr = start; ptr != NULL; ptr = ptr->next) {
            if (uniqeArr[i] == ptr->row) {
                if (ptr->data % 2 == 0) {
                    answer[i] = answer[i] / ptr->data;
                } else {
                    if (answer[i] == 0) {
                        answer[i] = 1;
                    }
                    answer[i] = answer[i] * ptr->data;
                }
            }
        }
    }
    for (double n: answer) {
        cout << n << endl;
    }
}

int main() {

    Node *first = NULL;
    cout << "Write count of elements of sparse matrix:" << endl;
    int countElements;
    cin >> countElements;
    cout << "Write elements(row, column, value):" << endl;
    for (int i = 0; i < countElements; i++) {
        int row;
        int column;
        int value;
        cin >> row >> column >> value;
        create_new_node(&first, row, column, value);
    }
    functionForTask(first);
    return 0;
}