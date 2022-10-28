#include <iostream>
using namespace std;

void input_array(int *&a, int &n)
{
    for (int i = 0; i < n; i++) {
        cout << "Nhap phan tu a[" << i << "]: ";
        cin >> *(a + i);
    }
}

void print_array(int *a, int n)
{
    cout << "Mang vua nhap la: ";
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " | ";
    }
}

int linearSearch(int *a, int n, int key){
    for (int i = 0; i < n; i++) {
        if (*(a+i) == key) return i+1;
        //Kiểm tra nếu phần tử đó có bằng phần tử cần tìm hay không nếu có trả về vị trí
    }
    return -1;
}

int binarySearch(int *a, int n, int key) 
{
  int r = n - 1; 
  int l = 0; 
  while (r >= l) {
    int mid = l + (r - l) / 2;
    if (*(a + mid) == key)
      return mid + 1;
    if (*(a + mid) > key)
      r = mid - 1;
    if (*(a + mid) < key)
      l = mid + 1;
  }
  return -1;
}

int main()
{
    int *a = new int[100];
    int n, x;
    cout << "\nNhap so luong phan tu n = ";
    do
    {
        cin >> n;
        if (n <= 0)
        {
            cout << "\nNhap lai n = ";
        }
    } while (n <= 0);
    input_array(a, n);
    cout << "\nMang vua nhap la: ";
    print_array(a, n);
    cout << "\nNhap so can tim: ";
    cin >> x;
    cout << "\nVi tri phan tu la: " << linearSearch(a, n, x);
    cout << "\nVi tri phan tu la: " << binarySearch(a, n, x);
    // Nhập mảng đã xắp xếp mới sử dụng binarySearch được
    return 0;
}