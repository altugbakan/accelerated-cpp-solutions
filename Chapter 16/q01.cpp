#include <iostream>
#include <string>

int main()
{
    char q = 34;
    std::string arr[] = {
        "#include <iostream>",
        "#include <string>",
        "",
        "int main()",
        "{",
        "    char q = 34",
        "    std::string arr[] = {",
        "        ",
        "    };",
        "    ",
        "    for (int i = 0; i < 7; ++i)",
        "        std::cout << arr[i] << std::endl;",
        "    for (int i = 0; i < 17; ++i)",
        "        std::cout << arr[7] << q << arr[i] << q << ',' << std::endl;",
        "    for (int i = 8; i < 17; ++i)",
        "        std::cout << arr[i] << std::endl;",
        "}",
    };

    for (int i = 0; i < 7; ++i)
        std::cout << arr[i] << std::endl;
    for (int i = 0; i < 17; ++i)
        std::cout << arr[7] << q << arr[i] << q << ',' << std::endl;
    for (int i = 8; i < 17; ++i)
        std::cout << arr[i] << std::endl;
}