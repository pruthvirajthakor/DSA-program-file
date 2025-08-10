// Write a program to calculate factorial of a given number using recursion function.

long factorial(int n)
{
    if (n <= 1)   // Base case
        return 1;
    else
        return n * factorial(n - 1);  
}

void main()
{
   
    int num;
    long fact;

    cout << "Enter a number: ";
    cin >> num;

    if (num < 0)
        cout << "Factorial is not defined for negative numbers.";
    else
    {
        fact = factorial(num);
        cout << "Factorial of " << num << " is: " << fact;
    }

   
}
