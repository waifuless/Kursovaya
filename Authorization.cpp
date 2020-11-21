#include "Authorization.h"

static std::string salt = "2dVg7WYC";

bool Authorization::isUserExist(const char* fileName) {
    std::fstream file(fileName);
    if (!file.is_open()) std::cout<<std::endl<< "Файл не открылся\n";
    else if (file.peek() != EOF) return true; // если первый символ конец файла
    return false;
}


bool Authorization::createAccount(const char* fileName) {
    std::ofstream file(fileName, std::ios::app);
    if (!file.is_open()) {
        std::cout << std::endl << "Файл не открылся\n";
        return false;
        }
    std::string login;
    std::string password;
    std::string password2;

    char c;

    std::cout << std::endl << "Введите логин : ";
    std::cin >> login;

    do {
        password.clear();
        password2.clear();
        std::cout << std::endl << "Введите пароль(минимум 6 символов) : ";
        while ((c = _getch()) != '\r')
        {
            password.push_back(c);
            _putch('*');
        }
        if (password.size() < 6) {
            std::cout << std::endl << "Пароль должен содержать минимум 6 символов ";
            continue;
        }
        std::cout << std::endl << "Введите пароль еще раз : ";
        while ((c = _getch()) != '\r')
        {
            password2.push_back(c);
            _putch('*');
        }
        if (password != password2) {
            std::cout << std::endl << "Пароли не совпадают ";
        }
    } while (password != password2);

    file << login << std::endl << sha256(password+salt)<<std::endl;
    std::cout << std::endl;
    if (file.is_open()) {
        file.close();
    }
    return true;
}

bool Authorization::singIn(const char* fileName) {
    std::string login;
    std::string password;
    std::string readLogin;
    std::string readPassword;
    int choice;
    bool resultOfAuthorization = false;
    char c;
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << std::endl << "Файл не открылся\n";
        return false;
    }
    if (file.eof()) {
        std::cout << std::endl << "Файл пуст :";
        return false;
    }
    while (resultOfAuthorization!=true) {
        //if (!file.is_open()) file.open(fileName);
        login.clear();
        password.clear();
        std::cout << std::endl << "Введите логин : ";
        std::cin >> login;
        std::cout << std::endl << "Введите пароль : ";
        while ((c = _getch()) != '\r')
        {
            password.push_back(c);
            _putch('*');
        }
        file.clear();
        file.seekg(0, file.beg);
        //std::cout << file.tellg();
        while (!file.eof()) {
            file >> readLogin;
            file >> readPassword;
            if (login == readLogin && sha256(password + salt) == readPassword) {
                resultOfAuthorization = true;
                break;
            }
            //std::cout <<std::endl<< file.tellg();
        }
        if (resultOfAuthorization != true) {
            std::cout << std::endl << "Логин или пароль не совпали";
            std::cout << std::endl << "1) Продолжить ввод";
            std::cout << std::endl << "2) Прекратить ввод"<<std::endl;
            std::cin >> choice;
            if (choice == 2) break;
        }
        //file.close(); //
    }
    if (file.is_open()) {
        file.close();
    }
    return resultOfAuthorization;
}