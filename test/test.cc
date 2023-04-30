#include <stdio.h>
// Taken from http://www.geeksforgeeks.org/iterative-quick-sort/
// A utility function to swap two elements
void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

class A{
    A(){
        int a =1;
    }

    ~A(){
        int b =1;
    }
};

static bool test_lambda = [](){
    int a = 1;
    return true;
}();
 
/* This function is same in both iterative and recursive*/
int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);

    int j;
    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}

/* A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
    int* stack = new int[ h - l + 1 ];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];
 
        // Set pivot element at its correct position in sorted array
        int p = partition( arr, l, h );
 
        // If there are elements on left side of pivot, then push left
        // side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }
 
        // If there are elements on right side of pivot, then push right
        // side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}

void foo(int a, int b, int c, int d) {
    int e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    if(a > 0) {
        b = b + a;
        if(b > 10) {
            c = c - 1;
            if(c < 0) {
                d = d * 2;
            }
            else {
                d = d * 3;
            }
        }
        else {
            d = d + 1;
        }
    }
    else {
        b = b - 1;
        if(b < 5) {
            c = c + 2;
            if(c > 10) {
                d = d / 2;
            }
            else {
                d = d / 3;
            }
        }
        else {
            d = d - 1;
        }
    }

    for(e = 0; e < a; e++) {
        for(f = 0; f < b; f++) {
            if(e % 2 == 0) {
                if(f % 2 == 0) {
                    g = g + 1;
                }
                else {
                    h = h + 1;
                }
            }
            else {
                if(f % 2 == 0) {
                    i = i + 1;
                }
                else {
                    j = j + 1;
                }
            }
        }
    }

    while(k < c) {
        if(k % 2 == 0) {
            l = l + 1;
        }
        else {
            m = m + 1;
        }
        k++;
    }

    do {
        if(n % 2 == 0) {
            o = o + 1;
        }
        else {
            p = p + 1;
        }
        n++;
    } while(n < d);

    switch(q) {
        case 0:
            r = r + 1;
            break;
        case 1:
            s = s + 1;
            break;
        case 2:
            t = t + 1;
            break;
        case 3:
            u = u + 1;
            break;
        case 4:
            v = v + 1;
            break;
        case 5:
            w = w + 1;
            break;
        default:
            x = x + 1;
            break;
    }

    if(y == 0) {
        z = z + 1;
    }
    else if(y == 1) {
        z = z - 1;
    }
    else if(y == 2) {
        z = z * 2;
    }
    else if(y == 3) {
        z = z / 2;
    }
    else if(y == 4) {
        z = z % 2;
    }
    else {
        z = z + 2;
    }
}
void foo1(){
    int cnt = 0;
    for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
        for(int i = 0; i < 5; i++){
        cnt++;
    }
    // 50 block
    printf("%d",cnt);
}



int main(){
    int arr[] = {5,2,3,1,4};
    quickSortIterative(arr,0,4);
    foo(5,1,2,7);
    foo(1,2,3,4);
    foo(4,3,2,1);
    foo1();
    printf("ok");

    return 0;
}
