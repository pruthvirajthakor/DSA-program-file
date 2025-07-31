// Write a program to calculate factorial of a given number using recursion function.

int fecto(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fecto(n - 1);
}

void main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (num < 0)
        cout << "Factorial is not defined for negative numbers.";
    else
        cout << "Factorial of " << num << " is: " << fecto(num);

}
