#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

void program0()
{
    int stHour, stMin, lesDur, breakDur, lesCount;

    std::cout << "Enter start hours: ";
    std::cin >> stHour;
    std::cout << "Enter start minutes: ";
    std::cin >> stMin;
    std::cout << "Enter lesson duration (in minutes): ";
    std::cin >> lesDur;
    std::cout << "Enter break duration (in minutes): ";
    std::cin >> breakDur;
    std::cout << "Enter count of lessons: ";
    std::cin >> lesCount;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    // проверки на ввод
    if (stHour > 23 || stHour < 0)
    {
        std::cout << "Incorrect input start hours!";
        return;
    }
    if (stMin > 59 || stMin < 0)
    {
        std::cout << "Incorrect input start minutes!";
        return;
    }
    if (lesDur < 0)
    {
        std::cout << "Incorrect inputclesson duration!";
        return;
    }
    if (breakDur < 0)
    {
        std::cout << "Incorrect input braek duration!";
        return;
    }
    if (lesCount < 0)
    {
        std::cout << "Incorrect input count of lessons!";
        return;
    }

    for (int i = 0; i < lesCount; ++i)
    {
        int endHour = stHour;
        int endMin = stMin + lesDur;

        while (endMin >= 60)
        {
            endHour += 1;
            endMin -= 60;
        }
        if (endHour >= 24)
        {
            endHour -= 24;
        }

        std::cout << i + 1 << ". ";
        if (stHour < 10) std::cout << "0";
        std::cout << stHour << ":";
        if (stMin < 10) std::cout << "0";
        std::cout << stMin << " - ";
        if (endHour < 10) std::cout << "0";
        std::cout << endHour << ":";
        if (endMin < 10) std::cout << "0";
        std::cout << endMin << std::endl;

        stHour = endHour;
        stMin = endMin + breakDur;

        while (stMin >= 60)
        {
            stHour += 1;
            stMin -= 60;
        }
    }
}

void program1()
{
    int n, flag;
    std::cout << "Output all simple numerals less n.\nEnter natural n:  ";
    std::cin >> n;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (n < 1)
    {
        std::cout << "Enter NATURAL n!";
        return;
    }

    if (n == 2 || n == 1)
    {
        std::cout << "No required numbers.";
        return;
    }

    for (int i = 2; i < n; i++)
    {
        flag = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            std::cout << i << " ";
        }
    }
}

void program2()
{
    int n;
    double x, s = 0;

    std::cout << "Enter N: ";
    std::cin >> n;
    std::cout << "Enter X: ";
    std::cin >> x;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    if (n <= 0)
    {
        std::cout << "N should be > 0\n";
        return;
    }

    for (int i = 1; i < n + 1; i++)
    {
        long f = 1;
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            f *= j;
        }
        double a = pow(x, (2 * i - 1)) / f;
        if (i % 2 == 0) a = -a;

        s += a;
    }
    std::cout << "Sum = " << s << '\n';
}

void program3()
{
    int k;
    std::cout << "Enter k: ";
    std::cin >> k;

    // проверка, что были введены числа
    if (std::cin.fail()) // извлечение не производилось
    {
        std::cout << "\nInput error!!!";
        // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
        std::cin.clear();
        // очищаем недопустимый ввод из потока
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    long long int t1 = 0, t2 = 1, nextTerm = 0;

    for (int i = 1; i <= k; ++i) {
        if (i == 1) {
            std::cout << t1 << ", ";
            continue;
        }
        if (i == 2) {
            std::cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        std::cout << nextTerm << ", ";
    }
}

void program4()
{
    int number = rand() % 1000 + 1;
    int guess;
    int attempts = 10;
    int count = 0;

    std::cout << "Guess the number from 1 to 1000. You have 10 attempts.\n";

    for (int i = 0; i < attempts; i++) 
    {
        std::cout << "Attempt " << i + 1 << std::endl;
        std::cout << "Enter your number: ";
        std::cin >> guess;

        // проверка, что были введены числа
        if (std::cin.fail()) // извлечение не производилось
        {
            std::cout << "\nInput error!!!";
            // сбрасываем биты состояния обратно в goodbit, чтобы мы могли использовать ignore()
            std::cin.clear();
            // очищаем недопустимый ввод из потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        if (guess < 1 || guess > 1000)
        {
            std::cout << "Your number is out of range!";
            return;
        }

        if (guess == number) 
        {
            std::cout << "You're right!\n";
            return;
        }
        else if (guess < number) 
        {
            std::cout << "The hidden number is bibber.\n";
            count++;
        }
        else 
        {
            std::cout << "The hidden number is less.\n";
            count++;
        }
    }

    if (count > 9)
    {
    std::cout << "Mission failed! Hidden number:  " << number << ".\n";
    return;
    }


}




int main()
{
    bool answer;

    //program0(); //31 [
    //program1(); //32 [
    //program2(); //33 [
    //program3(); //34 [
    //program4(); //35 [ 


    std::cout << "\nOne more? (1 - yes, 0 - no): ";
    std::cin >> answer;

    if (answer)
    {
        main();
    }
    return 0;
}
