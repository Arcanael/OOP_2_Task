
#include <iostream>
using namespace std;








// 1 задание
class Person 
{
protected: // протектед для доступа фунции вывода на экран
    string name; 
    int age;
    char sex; 
    double weight;
public:
    void setName(string s)
    {
        name = s;
    }
    void setAge(int i)
    {
        age = i; 
    }
    void setSex(char c)
    {
        sex = c;
    }
    void setWeight(double d)
    {
        weight = d;
    }

    Person(string n, int a, char s, double w) :name(n), age(a), sex(s), weight(w) {}
    
};

static int num_of_ex_stud = 0;

class Student : public Person
{
private:
    int year_of_study;
public:
    void setYear(int i) 
    { 
        year_of_study = i; 
    }void increaseYear()
    {
        year_of_study++;
    }
    Student(int y, string n, int a, char s, double w): Person( n,  a,  s,  w), year_of_study(y)
    {
        num_of_ex_stud++;
    }
    friend void printStudent(Student& s); //прототип функции вывода на экран данных о студенте
};

void printStudent(Student &s)
{
    cout << "Данные запрашиваемого студента:\n"<<"Имя : "<<s.name<<" Возраст : " << s.age << " Пол : " << s.sex << " Вес : " << s.weight << " Год обучения : " << s.year_of_study<<endl;
}
///////////////////////////////////////////////////////////////////
// main 1 задания
///////////////////////////////////////////////////////////////////
int main()
{
    string NameStud;// переменная для поиска студента
    setlocale(LC_ALL, "Russian");

    Student Ron(1, "Ron", 19, 'M', 99);
    Student Anna(3, "Anna", 21, 'F', 52);

    cout << "Введите имя студента для вывода его данных на экран:\n Ron\n Anna \n";
    cin >> NameStud;
    // в зависимости от вводимого значения выводится на экран данные о студенте
    if (NameStud == "Ron")
    {
        printStudent(Ron);
    }
    if (NameStud == "Anna")
    {
        printStudent(Anna);
    }
}
///////////////////////////////////////////////////////////////////

// 2 задание
class Fruit
{
private:
    string name;
    string color;
public:
    string getName() { return name; }
    string getColor() { return color; }
    Fruit(string n = "", string c = "") :name(n), color(c){}
};

class Banana : public Fruit
{
public: Banana() : Fruit("banana","yellow") {}
};

class Apple : public Fruit
{
public: Apple() : Fruit("apple", "") {}
        Apple(string c) : Fruit("apple", c) {}
        Apple(string n , string c) : Fruit(n, c) {}
};

class GrannySmith : public Apple
{
public: GrannySmith() : Apple("Granny Smith apple", "green") {}
};

///////////////////////////////////////////////////////////////////
// main 2 задания
///////////////////////////////////////////////////////////////////


//int main()
//{ 
//    Apple a("red");
//    Banana b;
//    GrannySmith c;
//
//    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
//    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
//    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
//
//    return 0;
//}

///////////////////////////////////////////////////////////////////


//// blackjack
//класс Deck содержайщий 
//вектор deck в котором хранятся оставшиеся карты из колоды
//метод reset для обновления колоды 
//метод setdivader для установления планки в колоде ограничивающей ее размер
//метод shafl для перемешивания остатка колоды 
//
//класс Participant содержащий
//вектор hand в котором хранятся текущие карты в руке
//int chips количество доступных фишек
//метод show_all который показывает карты на руке их стоимость и суммарное значение
//метод calculate который считает суммарное значение карт в руке
//метод action который либо берет карту из колоды и добавляет в руку либо пасует
//
//класс Dealer : Participant содержайщий
//метод show_1 показывает первую карту диллера. всегда вызывается
//метод check_val_17 проверяет сумму карт в руке диллера и если она меньше 16 добирает карту. вызывается до тех пор пока сумма не будет равна или больше 17.
//
//
//класс Player : Participant содержайщий
//метод show_me показывает карыт и сумму для игрока
//методs set_stake устанавливает ставку на текущий раунд
//
//
//класс Game содержайщий
//метод decide_winner который определяет исход игры
//метод start_next_game который запускает следующую игру