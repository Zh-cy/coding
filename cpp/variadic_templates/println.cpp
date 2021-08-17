#include <iostream>
#include <string>

template<typename T>
void println(T t)
{
	std::cout << t << std::endl;
}

template<typename T, typename ...U>
void println(T t, U ...u)
{
	std::cout << t << ", ";
	println(u...);
}

int main(void)
{
	println("213", 12, 2.0);

}
