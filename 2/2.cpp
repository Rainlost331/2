#include <iostream>
#include <stack>
#include <set>
#include <cstdlib>
#include <ctime>
#include <locale>

using namespace std;

void fillStacks(stack<int>& stack1, stack<int>& stack2) {
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        stack1.push(rand() % 11);
        stack2.push(rand() % 11);
    }
    cout << "кольца заполенены рандомными числами" << endl;
}

void outputSeparately(stack<int> stack1, stack<int> stack2) {
    cout << "первое кольцо: ";
    while (!stack1.empty()) {
        cout << stack1.top() << " ";
        stack1.pop();
    }
    cout << endl;

    cout << "второе кольцо: ";
    while (!stack2.empty()) {
        cout << stack2.top() << " ";
        stack2.pop();
    }
    cout << endl;
}

void mergeStacks(stack<int> stack1, stack<int> stack2) {
    set<int> sortedSet;

    while (!stack1.empty()) {
        sortedSet.insert(stack1.top());
        stack1.pop();
    }

    while (!stack2.empty()) {
        sortedSet.insert(stack2.top());
        stack2.pop();
    }

    stack<int> mergedStack;
    for (auto it = sortedSet.rbegin(); it != sortedSet.rend(); it++) {
        mergedStack.push(*it);
    }

    cout << "обьеденное кольцо: ";
    while (!mergedStack.empty()) {
        cout << mergedStack.top() << " ";
        mergedStack.pop();
    }
    cout << endl;
};

int main() {
    setlocale(LC_ALL, "Ru");
    stack<int> stack1, stack2;

    while (true) {
        char key;
        cout << "выберите функцию - a - заполнение 10 рандомными числами " << endl;
        cout << "                   s - просмотреть кольца " << endl;
        cout << "                   v - обьеденнение колец " << endl;
        cout << "                   n - просмотреть обьеденное кольцо " << endl;
        cout << "                   0 - завершение " << endl;
        cin >> key;

        switch (key) {
        case 'a':
            fillStacks(stack1, stack2);
            break;

        case 's':
            outputSeparately(stack1, stack2);
            break;

        case 'v':
            mergeStacks(stack1, stack2);
            break;

        case 'n':
            mergeStacks(stack1, stack2);
            break;

        case '0':
            cout << "выход." << endl;
            return 0;

        default:
            cout << "инвалид" << endl;
            break;
        }
    }
    system("cls");
}