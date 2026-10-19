#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "classes.h"
using namespace std;

void main()
{
    setlocale(LC_ALL, "Ukrainian");
    srand((unsigned)time(0));

    Student students[5];
    students[0].SetData("Шевченко", "Ольга", 3, "Комп'ютерна Iнженерiя", "КI-24");
    students[1].SetData("Бондар", "Марiя", 4, "Iнженерiя ПЗ", "IПЗ-23", 500);
    students[2].SetData("Андрiйчук", "Iрина", 2, "Кiбербезпека", "КБ-25");
    students[3].SetData("Коваль", "Андрiй", 2, "Системний аналiз", "СА-25", 200);
    students[4].SetData("Петрук", "Максим", 3, "Iнженерiя ПЗ", "IПЗ-24");

    Voucher* vouchers = new Voucher[5];
    vouchers[0].SetVoucher("Буковель", "Готель", "Автобус", 4500, "Гiрськолижний тур", 350);
    vouchers[1].SetVoucher("Одеса", "Гуртожиток", "Поїзд", 2200, "Вiдпочинок на морi");
    vouchers[2].SetVoucher("Львiв", "Готель", "Автобус", 3000, "Екскурсiйний тур", 200);
    vouchers[3].SetVoucher("Карпати", "Гуртожиток", "Поїзд", 1800, "Похiдний тур");
    vouchers[4].SetVoucher("Київ", "Готель", "Лiтак", 5000, "Культурна програма", 400);

    cout << "Усi путiвки" << endl;
    for (int i = 0; i < 5; i++)
    {
        vouchers[i].ShowVoucher();
        cout << endl;
    }

    cout << endl << "Усi студенти (до покупки путiвок)" << endl;
    for (int i = 0; i < 5; i++)
    {
        students[i].ShowStudent();
        cout << endl;
    }

    Student* p_student = &students[0];
    cout << endl << "Робота через покажчик на студента:" << endl;
    p_student->ApplyScholarship(1000);
    p_student->ShowStudent();

    cout << endl << "Купiвля путiвок (взаємодiя двох об'єктiв)" << endl;
    students[0].BuyVoucher(vouchers[0]);
    students[1].BuyVoucher(vouchers[1].GetDiscounted(10));
    vouchers[2].ApplyGroupDiscount(15);
    students[2].BuyVoucher(vouchers[2]);

    cout << endl << "Студенти пiсля покупки путiвок" << endl;
    for (int i = 0; i < 3; i++)
    {
        students[i].ShowStudent();
        cout << endl;
    }

    cout << endl << "Порiвняння вартостi путiвок (vouchers[0] дешевша за vouchers[3]?): "
        << (vouchers[0].CompareCost(vouchers[3]) ? "так" : "нi") << endl;

    Student student_copy = students[0].GetCopy();
    cout << "Копiя студента: ";
    student_copy.ShowStudent();

    ofstream out_file("students.dat", ios::binary);
    for (int i = 0; i < 5; i++)
        students[i].WriteToFile(out_file);
    out_file.close();

    cout << endl << "Студенти, прочитанi з файлу students.dat" << endl;
    ifstream in_file("students.dat", ios::binary);
    for (int i = 0; i < 5; i++)
    {
        Student temp;
        temp.ReadFromFile(in_file);
        temp.ShowStudent();
        cout << endl;
    }
    in_file.close();

    ofstream out_file2("vouchers.dat", ios::binary);
    for (int i = 0; i < 5; i++)
        vouchers[i].WriteToFile(out_file2);
    out_file2.close();

    cout << endl << "Генерацiя i сортування випадкових курсiв" << endl;
    students[0].SortRandomCourses();

    delete[] vouchers;

    cin.get();
}