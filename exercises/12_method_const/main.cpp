#include "../exercise.h"

// READ: 有 cv 限定符的成员函数 <https://zh.cppreference.com/w/cpp/language/member_functions>

struct Fibonacci {
    int numbers[11];
    // TODO: 修改方法签名和实现，使测试通过
    const int get(int i) const{
        if (i < 0) {
            return 0;
        }
        if (i < 2) {
            return numbers[i];
        }
        int a = numbers[0], b = numbers[1], result = 0;
        for (int j = 2; j <= i; ++j) {
            result = a + b;
            a = b;
            b = result;
        }
        return result;
    }
};

int main(int argc, char **argv) {
    Fibonacci constexpr FIB{{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}};
    ASSERT(FIB.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << FIB.get(10) << std::endl;
    return 0;
}
