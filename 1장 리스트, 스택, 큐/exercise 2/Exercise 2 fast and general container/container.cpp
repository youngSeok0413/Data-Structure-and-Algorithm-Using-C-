//코드 출처 : 코딩 테스트를 위한 자료 구조와 알고리즘 ( 저자 : 존 캐리 외 2인, 길벗 출판사)
//빠르고 범용적인 데이터 컨테이너 만들기

#include <array>
#include <iostream>
#include <type_traits>

template<typename ... Args>
auto build_array(Args&&... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args) >
{
	using commonType = typename std::common_type<Args...>::type;
	return { (std::forward<commonType>((Args&&)args)... };
}

int main() {
	auto data = build_array(1, 0u, 'f', false);

	for (auto i : data)
		std::cout << i << " ";

	std::cout << std::endl;
}
