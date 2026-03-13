#include <iostream>
using namespace std;

int main() {

L0:
cin >> n;
x = 1;
i = 2;
i = 2;
L1:
L0:
T0 = i <= n;
if (T0) goto L1;
L3:
L1:
T1 = x * i;
x = T1;
T2 = i + 1;
i = T2;
goto L0;
L2:
goto L2;
L4:
L2:
cout << x << endl;
return 0;

}
