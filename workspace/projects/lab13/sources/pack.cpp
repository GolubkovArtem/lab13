#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;

struct Email {
    std::string nickname;
    std::string server;
};

struct Person {
    std::string  first_name;
    std::string  last_name;
    Email        email;
    size_t       age;
    std::string  phone;
};

int main(int argc, char* argv[])
{
    Person person;
    std::cout << "Enter data to fields of the Person structure.\n"
        << "First name :\n";
    std::string str;
    json j_son;
    std::getline(std::cin, str);
    person.first_name = str;
    j_son["First name"] = str;
    std::cout << "Last name :\n";
    std::getline(std::cin, str);
    person.last_name = str;
    j_son["Last name"] = str;
    std::cout << "Email nickname :\n";
    std::getline(std::cin, str);
    std::string buf_nick = str;
    person.email.nickname = str;
    std::cout << "Email server :\n";
    std::getline(std::cin, str);
    person.email.server = str;
    buf_nick += "@" + str;
    j_son["Email"] = buf_nick;
    std::cout << "Phone(optional) :\n";
    std::getline(std::cin, str);
    if (!str.empty())
    {
        person.phone = str;
        j_son["Phone"] = str;
    }
    std::cout << "Age(optional) :\n";
    size_t age;
    while (std::cin.peek() != '\n')
    {
        std::cin >> age;
        person.age = age;
        j_son["Age"] = age;
        break;
    }
    std::ofstream out(argv[1]);
    out << j_son;
    return 0;
}
