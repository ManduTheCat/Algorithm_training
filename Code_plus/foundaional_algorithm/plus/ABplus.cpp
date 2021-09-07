// #include <iostream>

// int main()
// {
// 	// std::ios_base::sync_with_stdio(false);
// 	// std::cout.tie(NULL);
// 	// std::cin.tie(NULL);
// 	int case_num;
// 	int a;
// 	int b;
// 	int arr[100];
// 	int
// 	case_num = 0;
// 	while(std::cin >> a >> b)
// 	{
// 		arr[case_num] = a + b;
// 		case_num ++;
// 	}


// 	while(i < case_num)
// 	{
// 		std::cout << arr[i];
// 		i++
// 	}
// }

#include <iostream>
using namespace std;
int main() {

    int a, b, t;
	char c;

	cin >> t;
    while (cin >> a >> c >> b) {
        cout << a+b << '\n';
    }
    return 0;
}
