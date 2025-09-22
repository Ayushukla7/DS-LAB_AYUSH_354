#include <iostream>
using namespace std;
void traverse(int arr[], int n) {
 cout << "Array elements are: ";
 for (int i = 0; i < n; i++) {
 cout << arr[i] << " ";
 }
 cout << endl;
}
int insertElement(int arr[], int n, int x, int pos) {
 for (int i = n; i > pos; i--) {
 arr[i] = arr[i - 1];
 }
 arr[pos] = x;
 return n + 1;
}
int deleteElement(int arr[], int n, int pos) {
 if (pos >= n || pos < 0) {
 cout << "Invalid position!" << endl;
 return n;
 }
 for (int i = pos; i < n - 1; i++) {
 arr[i] = arr[i + 1];
 }
 return n - 1;
}
int main() {
 int arr[100], n, choice, pos, x;
 cout << "Enter number of elements: ";
 cin >> n;
 cout << "Enter " << n << " elements: ";
 for (int i = 0; i < n; i++) {
 cin >> arr[i];
 }
 do {
 cout << "\n Menu: \n1. Traverse \n2. Insert \n 3. Delete\n 4. Exit \n";
 cout << "Enter choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 traverse(arr, n);
 break;
 case 2:
 cout << "Enter element to insert: ";
 cin >> x;
 cout << "Enter position (0-based index): ";
 cin >> pos;
 if (pos < 0 || pos > n) {
 cout << "Invalid position!" << endl;
 } else {
 n = insertElement(arr, n, x, pos);
 cout << "After insertion: ";
 traverse(arr, n);
 }
 break;
 case 3:
 cout << "Enter position to delete (0-based index): ";
 cin >> pos;
 n = deleteElement(arr, n, pos);
 cout << "After deletion: ";
 traverse(arr, n);
 break;
 case 4:
 cout << "Exiting..." << endl;
 break;
 default:
 cout << "Invalid choice!" << endl;
 }
 } while (choice != 4);
 return 0;
}
