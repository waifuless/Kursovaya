#include "SortForClasses.h"

int RecordCompare::compare_fullName_ASC(Record& a, Record& b) {  //функции для сравнения объектов при сортировке
    int i = 0;
    if (a.getFullName() < b.getFullName())
        i = -1;
    else if (a.getFullName() > b.getFullName())
        i = 1;
    return i;
}

int RecordCompare::compare_cardNumber_ASC(Record& a, Record& b) {
    int i = 0;
    if (a.getCardNumber() < b.getCardNumber())
        i = -1;
    else if (a.getCardNumber() > b.getCardNumber())
        i = 1;
    return i;
}

int RecordCompare::compare_date_ASC(Record& a, Record& b) {
    int i = 0;
    if (a.getDate() < b.getDate())
        i = -1;
    else if (a.getDate() > b.getDate())
        i = 1;
    return i;
}

int RecordCompare::compare_time_ASC(Record& a, Record& b) {
    int i = 0;
    if (a.getTime() < b.getTime())
        i = -1;
    else if (a.getTime() > b.getTime())
        i = 1;
    return i;
}

int RecordCompare::compare_doctorName_ASC(Record& a, Record& b) {
    int i = 0;
    if (a.getDoctorName() < b.getDoctorName())
        i = -1;
    else if (a.getDoctorName() > b.getDoctorName())
        i = 1;
    return i;
}

int RecordCompare::compare_doctorOffice_ASC(Record& a, Record& b) {
    int i = 0;
    if (a.getDoctorOffice() < b.getDoctorOffice())
        i = -1;
    else if (a.getDoctorOffice() > b.getDoctorOffice())
        i = 1;
    return i;
}

int RecordCompare::compare_fullName_DESC(Record& a, Record& b) {
    return - compare_fullName_ASC(a, b);
}

int RecordCompare::compare_cardNumber_DESC(Record& a, Record& b) {
    return - compare_cardNumber_ASC(a, b);
}

int RecordCompare::compare_date_DESC(Record& a, Record& b) {
    return -compare_date_ASC(a, b);
}

int RecordCompare::compare_time_DESC(Record& a, Record& b) {
    return -compare_time_ASC(a, b);
}

int RecordCompare::compare_doctorName_DESC(Record& a, Record& b) {
    return -compare_doctorName_ASC(a, b);
}

int RecordCompare::compare_doctorOffice_DESC(Record& a, Record& b) {
    return -compare_doctorOffice_ASC(a, b);
}


