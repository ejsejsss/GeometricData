#include <iostream>
#include <utility>
#include <vector>
#include <fstream>
#include "cube.hpp"
#include "Parallelepiped.hpp"

void menu();

std::string read_file(std::ifstream &in);

void cube(std::ifstream &in);

void parallelepiped(std::ifstream &in);

void check_case(int, std::ifstream &in);

int main() {
    int num_menu(0);
    while (num_menu != 6) {
        std::ifstream in;
        in.exceptions(std::ifstream::badbit | std::ifstream::failbit);
        try {
            menu();
            std::cout << "Выберите пункт меню >> ";
            std::cin >> num_menu;
            check_case(num_menu, in);

            std::cout << "----------------------" << std::endl;
            in.close();
        }
        catch(const std::string& error_msg) {
            std::cerr << "Ошибка: " << error_msg << std::endl;
        }
        catch (const std::ifstream::failure& e) {
            std::cerr << "Ошибка открытия/чтения файла: " << e.what() << std::endl;
        }
        catch (const std::exception &ex) {
            std::cerr << "Ошибка: " << ex.what() << std::endl;
        }
    }
    return EXIT_SUCCESS;
}

void menu() {
    std::cout << "---------Меню---------" << std::endl;
    std::cout
            << "1. Куб" << std::endl
            << "2. Пирамида" << std::endl
            << "3. Параллелепипед" << std::endl
            << "4. Призма" << std::endl
            << "5. Усеченная пирамида" << std::endl
            << "6. Выход" << std::endl
            << std::endl;
}

void check_case(int num, std::ifstream &in) {
    switch (num) {
        case 1:
            cube(in);
            break;
        case 3:
            parallelepiped(in);
            break;
        case 6:
            exit(EXIT_SUCCESS);
        default:
            throw std::string("Неправильный выбор меню");
    }
}

std::string read_file(std::ifstream &in) {
    std::string path;
    std::cout << "Введите название файла >> ";
    std::cin >> path;
    in.open(path);
    return path;
}

void cube(std::ifstream &in) {
    auto name = read_file(in);
    Cube cube(std::move(name));
    in >> cube;

    std::cout << "Вершины: " << std::endl;
    int i = 0;
    for (auto v: cube.getVertexes()) {
        std::cout << v << ' ';
        i++;
        if (i == 4 || i == 8) std::cout << std::endl;
    }
    std::cout << "Объем - " << cube.volume() << std::endl;
    std::cout << "Площадь - " << cube.area() << std::endl;
}

void parallelepiped(std::ifstream &in) {
    auto name = read_file(in);
    Parallelepiped p(std::move(name));
    in >> p;

    std::cout << "Вершины: " << std::endl;
    int i = 0;
    for (auto v: p.getVertexes()) {
        std::cout << v << ' ';
        i++;
        if (i == 4 || i == 8) std::cout << std::endl;
    }
    std::cout << "Объем - " << p.volume() << std::endl;
    std::cout << "Площадь - " << p.area() << std::endl;
}
