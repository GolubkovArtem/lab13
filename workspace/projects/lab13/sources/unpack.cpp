#include <iostream>
#include <fstream>

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

std::ostream & print (std::ostream & out, json & j_son)
{
    out << "person:"
        << "\n   firstname: " << j_son.at("First name").get<std::string>()
        << "\n   lastname: " << j_son.at("Last name").get<std::string>()
        << "\n   email: " << j_son.at("Email").get<std::string>();
    if (j_son.find("Age") != j_son.end())
    {
        out << "\n   age: " << j_son.at("Age").get<size_t>();
    }
    if (j_son.find("Phone") != j_son.end())
    {
        out << "\n   phone: " << j_son.at("Phone").get<std::string>();
    }
    return out;
}

int main(int argc, char * argv[])
{
    std::ifstream file(argv[1]);
    json j_son;
    file >> j_son;
    print(std::cout, j_son);
    return 0;
}
