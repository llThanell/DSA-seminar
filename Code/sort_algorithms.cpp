#include <iostream>
using namespace std;

void nhap(int a[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << "Nhap vao phan tu a[" << i << "] : ";
        cin >> a[i];
    }
}

void xuat(int a[], int n) 
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        /* Di chuyển các phần tử có giá trị lớn hơn giá trị 
       key về sau một vị trí so với vị trí ban đầu
       của nó */
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void bubbleSortVer1(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void bubbleSortVer2(int arr[], int n)
{
    // i phần tử cuối cùng đã được sắp xếp
    bool haveSwap = false;
    for (int i = 0; i < n-1; i++)
    {
        haveSwap = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                haveSwap = true; // Kiểm tra lần lặp này có swap không
            }
        }
        // Nếu không có swap nào được thực hiện => mảng đã sắp xếp. Không cần lặp thêm
        if(haveSwap == false)
        {
            break;
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void selectionSort(int arr[], int n){
    for (int i = 0; i < n; i++){
        int min = i;
        for (int j = i; j < n; j++){
            if (arr[j] < arr[min]) min = j; // Sau khi tìm được phần tử nhỏ thứ i thì đổi chỗ
        }
        swap(arr[min], arr[i]);
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l  + 1;
    int n2 =  r - m;
 
    /* Tạo các mảng tạm */
    int L[n1], R[n2];
 
    /* Copy dữ liệu sang các mảng tạm */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Gộp hai mảng tạm vừa rồi vào mảng arr*/
    i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    k = l; // IKhởi tạo chỉ số bắt đầu của mảng lưu kết quả
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    /* Copy các phần tử còn lại của mảng L vào arr nếu có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    /* Copy các phần tử còn lại của mảng R vào arr nếu có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
        int m = l+(r-l)/2;
 
        // Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void shellSort(int a[], int n)
{
	int interval, i, j, temp;
	for(interval = n/2; interval > 0; interval /= 2)
    {
		for(i = interval; i < n; i++)
        {
			temp = a[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval)
            {
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void heapify(int arr[], int n, int i)
{
  int root = i;
  int l = 2*i + 1;  // vị trí bên trái = 2*i + 1
  int r = 2*i + 2;  // vị trí bên phải = 2*i + 2
 
  // Nếu node con lớn hơn node cha
  if (l < n && arr[l] > arr[root])
    root = l;
 
  // Nếu node con lớn hơn phần tử lớn nhất
  if (r < n && arr[r] > arr[root])
    root = r;
 
  // Nếu phần tử gốc không phải là phần tử lớn nhất
  if (root != i)
  {
    swap(arr[i], arr[root]); //Hoán vị phần tử max và phần tử gốc
    heapify(arr, n, root); 
  }
}
 
void heapSort(int arr[], int n)
{
  for (int i = (n/2) - 1; i >= 0; i--)
    heapify(arr, n, i); //Đưa phần tử max lên gốc
 
  for (int i = n-1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0); //Lấy phần tử gốc là max ra khỏi cây.
  }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; 
    int i, count[10] = { 0 }; 

    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 

void radixSort(int arr[], int n) 
{ 
    int m = getMax(arr, n); 
    for (int exp = 1; m / exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
} 
//---------------------------------------------------------------------------------------------------------------------------------------------------
void shakerSort(int a[], int n)
{
    int l, r, k;
    r = n - 1;
    l = 0;
    k = 0;
    while (l < r)
    {
        for (int i = l; i < r; i++)
        {
            if (a[i] > a[i + 1])
            {
                k = i;
                swap(a[i], a[i + 1]); // đổi chỗ hai phần tử a[i] và a[i-1]
            }
        }
        r = k;
        for (int i = r; i > l; i--)
        {
            if (a[i] < a[i - 1])
            {
                k = i;
                swap(a[i], a[i - 1]); // đổi chỗ hai phần tử a[i] và a[i-1]
            }
        }
        l = k;
    }
    return;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void countingSort(int input[], int n)
{
 
    int output[n]; 
    int max = input[0];
    int min = input[0];
 
    for(int i = 1; i < n; i++)
    {
        if(input[i] > max)
            max = input[i];
        else if(input[i] < min)
            min = input[i]; 
    }
 
    int k = max - min + 1; 
 
    int count_array[k]; 
    fill_n(count_array, k, 0); 
 
    for(int i = 0; i < n; i++)
        count_array[input[i] - min]++; 

    for(int i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];

    for(int i = 0; i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }
 
    for(int i = 0; i < n; i++)
        input[i] = output[i]; 
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int binarySearch(int arr[], int item, int low, int high)
{
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;
    int mid = (low + high) / 2;
    if (item == arr[mid])
        return mid + 1;
    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);
    return binarySearch(arr, item, low, mid - 1);
}

void binaryInsertionSort(int arr[], int n)
{
    int i, loc, j, k, selected;
    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = arr[i];
        loc = binarySearch(arr, selected, 0, j);
        while (j >= loc)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void flashSort(int a[], int n)
{
	int min = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)
		l[i] = 0;
	for (int i = 1; i < n; i++){
		if (a[i] < min)
			min = a[i];
		if (a[i] > a[max])
			max = i;
	}
	if (a[max] == min)
		return;
	double c1 = (double)(m - 1) / (a[max] - min);
	for (int i = 0; i < n; i++){
		int k = int(c1 * (a[i] - min));
		++l[k];
	}
	for (int i = 1; i < m; i++)
		l[i] += l[i - 1];
	swap(a[max], a[0]);
	int nmove = 0;
	int j = 0;
	int k = m - 1;
	int t = 0;
	int flash;
	while (nmove < n - 1){
		while (j > l[k] - 1){
			j++;
			k = int(c1*(a[j] - min));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k]){
			k = int(c1* (flash - min));
			int hold = a[t = --l[k]];
			a[t] = flash;
			flash = hold;
			++nmove;
		}
	}
	delete[] l;
	insertionSort(a, n);
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int a[100];
    int n;
    cout << "\nNhap so luong phan tu n = ";
    do
    {
        cin >> n;
        if (n <= 0)
        {
            cout << "\nNhap lai n = ";
        }
    } while (n <= 0);
    nhap(a, n);
    cout << "\nMang vua nhap la: ";
    xuat(a, n);

    // Gọi các hàm xắp xếp
    selectionSort(a, n);
    // insertionSort(a, n);
    // bubbleSortVer1(a, n);
    // bubbleSortVer2(a, n);
    // mergeSort(a, 0, n-1);
    // quickSort(a, 0, n-1);
    // shellSort(a, n);
    // shakerSort(a, n);
    // flashSort(a, n);
    // heapSort(a, n);
    // radixSort(a, n);
    // binaryInsertionSort(a, n);
    // countingSort(a, n);

    cout << "\nmang da duoc sap xep la: ";
    xuat(a, n);
    return 0;
}