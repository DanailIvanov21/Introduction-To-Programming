bool isPrime(int num) {
     int sqrtOfNum = sqrt(num);
     for (int j = 2; j <= sqrtOfNum; j++)
     {
         if (num % j == 0)
         {
             return false;
         }
     }
     return true;     
}

void printPrimeDivs(int num)
{
    if (num == 1)
        std::cout << 1;
    else if (num < 1)
        return;

    for (int i = 2; i <= num; i++)
    {
        if (num % i == 0 && isPrime(i))
        {
            std::cout << i << " ";
        }
    }
}
