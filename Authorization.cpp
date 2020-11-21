#include "Authorization.h"

static std::string salt = "2dVg7WYC";

bool Authorization::isUserExist(const char* fileName) {
    std::fstream file(fileName);
    if (!file.is_open()) std::cout<<std::endl<< "���� �� ��������\n";
    else if (file.peek() != EOF) return true; // ���� ������ ������ ����� �����
    return false;
}


bool Authorization::createAccount(const char* fileName) {
    std::ofstream file(fileName, std::ios::app);
    if (!file.is_open()) {
        std::cout << std::endl << "���� �� ��������\n";
        return false;
        }
    std::string login;
    std::string password;
    std::string password2;

    char c;

    std::cout << std::endl << "������� ����� : ";
    std::cin >> login;

    do {
        password.clear();
        password2.clear();
        std::cout << std::endl << "������� ������(������� 6 ��������) : ";
        while ((c = _getch()) != '\r')
        {
            password.push_back(c);
            _putch('*');
        }
        if (password.size() < 6) {
            std::cout << std::endl << "������ ������ ��������� ������� 6 �������� ";
            continue;
        }
        std::cout << std::endl << "������� ������ ��� ��� : ";
        while ((c = _getch()) != '\r')
        {
            password2.push_back(c);
            _putch('*');
        }
        if (password != password2) {
            std::cout << std::endl << "������ �� ��������� ";
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
        std::cout << std::endl << "���� �� ��������\n";
        return false;
    }
    if (file.eof()) {
        std::cout << std::endl << "���� ���� :";
        return false;
    }
    while (resultOfAuthorization!=true) {
        //if (!file.is_open()) file.open(fileName);
        login.clear();
        password.clear();
        std::cout << std::endl << "������� ����� : ";
        std::cin >> login;
        std::cout << std::endl << "������� ������ : ";
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
            std::cout << std::endl << "����� ��� ������ �� �������";
            std::cout << std::endl << "1) ���������� ����";
            std::cout << std::endl << "2) ���������� ����"<<std::endl;
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