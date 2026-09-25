/* N№24(N№4) Поле first — ціле додатнє число, номінал купюри; номінал може приймати
значення 1, 2, 5, 10, 20, 50, 100, 500, 1000. Поле second — ціле додатнє
число, кількість купюр даного номіналу.Реалізувати метод summa() —
обчислення грошової суми.
*/

#include <iostream>
#include "cash.h"
using namespace std;

int main()
{
    cash A;
    A.init(0, 0);
    A.Display();
    A.Read();
    A.Display();
    A.Sum();
}