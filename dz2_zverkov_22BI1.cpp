#include <iostream>
#include <cmath>
#include <random>
#include <map>

using namespace std;

template <typename T>
T readValue(string msg){
    T value;
    cout << msg << endl;
    cin >> value;
    return value;
}

void leave(){
    exit(0);
}


//1
void trapArea(){
    double a = readValue<double>("Введите первое основание");
    double b = readValue<double>("Введите второе основание");
    double h = readValue<double>("Введите высоту");

    cout << "Площадь трапеции: " << ((a+b)*h*0.5) << endl;
}

//2
void circleLenghtArea(){
    double r = readValue<double>("Введите радиус");

    cout << "Длина окружности: " << (r * M_PI * 2) << endl;
    cout << "Площадь окружности: " << (r * M_PI * r) << endl;
}

//3
void triangleHypoArea(){
    double a = readValue<double>("Введите 1й катет");
    double b = readValue<double>("Введите 2й катет");

    cout << "Гипотенуза: " << sqrt((a * a) + (b * b)) << endl;
    cout << "Площадь: " << a * b * 0.5 << endl;
}

//4
void sumOfDigits(){
    string a = readValue<string>("Введите число");

    int sum = 0;
    for (char i : a){
        sum += i - '0';
    }

    cout << "Сумма цифр: " << sum << endl;
}

//5
void decToPolar() {
    double x = readValue<double>("Координата x");
    double y = readValue<double>("Координата y");

    cout << "Полярный радиус: " << sqrt(x*x + y*y) << endl;
    cout << "Полярный угол: " << atan(y / x) << endl;
}

//6
void polarToDec() {
    double r = readValue<double>("Полярный радиус");
    double angle = readValue<double>("Полярный угол:");

    cout << "Координата x: " << r * cos(angle) << endl;
    cout << "Координата y: " << r * sin(angle) << endl;
}

//7
void roots(){
    double a = readValue<double>("Введите коэффициент a");
    double b = readValue<double>("Введите коэффициент b");
    double c = readValue<double>("Введите коэффициент c");

    double disc = b * b - 4 * a * c;
    if(disc >= 0) {
        cout << "Корни уравнения: " << (-b - sqrt(disc)) / (2 * a) << " и " << (-b + sqrt(disc)) / (2 * a) << endl;
    } else {
        cout << "Корней нет" << endl;
    }
}

//8
void medianOfMedian(){
    double a = readValue<double>("Введите сторону a");
    double b = readValue<double>("Введите сторону b");
    double c = readValue<double>("Введите сторону c");

    double ma = 0.5 * sqrt(2*(b*b + c*c) - a*a);
    double mb = 0.5 * sqrt(2*(a*a + c*c) - b*b);
    double mc = 0.5 * sqrt(2*(b*b + a*a) - c*c);

    double m1 = 0.5 * sqrt(2*(mb*mb + ma*ma) - mc*mc);
    double m2 = 0.5 * sqrt(2*(ma*ma + mc*mc) - mb*mb);
    double m3 = 0.5 * sqrt(2*(mb*mb + ma*ma) - mc*mc);

    cout << "Медианы треугольника, сторонами которого являются медианы введённого треугольника";
    cout << "(ma: " << ma << ", mb: " << mb << ", mc: " << mc << "):\n";
    cout << m1 << " " << m2 << " " << m3 << endl;
}

//9
void myTime(){
    int k = readValue<int>("Введите секунды");

    cout << "С начала суток прошло: " << k / 3600 << " часов " << (k / 60) % 60 << " минут " << (k/3600) << " секунд" << endl;
}

//10
void equalSides(){
    double a = readValue<double>("Введите сторону a");
    double b = readValue<double>("Введите сторону b");
    double c = readValue<double>("Введите сторону c");

    cout << (((a == b) || (b == c) || (c == a)) ? "Треугольник равнобедренный" : "Треугольник не равнобедренный") << endl;
}

//11
void discount(){
    double k = readValue<double>("Введите стоимость");

    cout << "Итоговая цена: " << ((k > 1000) ? k * 0.9 : k) << endl;
}

//12
void weight(){
    double weight = readValue<double>("Введите вес");
    double height = readValue<double>("Введите рост");

    double ideal = height - 100;

    string output;

    if (weight == ideal) {
        output = "Ваш вес идеален";
    } else if(weight > ideal) {
        output = "надо похудеть";
    } else {
        output = "надо потолстеть";
    }

    cout << output << endl;;
}

//13
void multiplicationTest(){
    random_device dev;
    mt19937 gen(dev());
    uniform_int_distribution<> dist(1,9);

    int a = dist(gen);
    int b = dist(gen);

    int result = readValue<int>("Сколько будет " + to_string(a) + " умножить на " + to_string(b) + "?");

    cout << ((result == a * b) ? "Правильно" : "Неправильно") << endl;
}

//14
void cost(){
    int per = 10; //ну типа цена за час

    int day = readValue<int>("Введите день недели");
    int hours = readValue<int>("Введите длительность");

    cout << "Стоимость переговоров: " << hours * per * ((day / 6 == 1) ? 0.8 : 1) << endl;
}

//15
const pair<string, string> months[] = {
    make_pair("Январь", "Зима"),
    make_pair("Февраль", "Зима"),
    make_pair("Март", "Весна"),
    make_pair("Апрель", "Весна"),
    make_pair("Май", "Весна"),
    make_pair("Июнь", "Лето"),
    make_pair("Июль", "Лето"),
    make_pair("Август", "Лето"),
    make_pair("Сентябрь", "Осень"),
    make_pair("Октябрь", "Осень"),
    make_pair("Ноябрь", "Осень"),
    make_pair("Декабрь", "Зима"),
    };

void month(){
    int i = readValue<int>("Введите номер месяца") - 1;
    cout << "Название: " << months[i].first << ", сезон: " << months[i].second << endl;
}

//16
void happyNumber(){
    string n = readValue<string>("Введите число");

    bool ans = ((n[0] - '0') + (n[1] - '0') + (n[2] - '0')) == ((n[3] - '0') + (n[4] - '0') + (n[5] - '0'));
    cout << (ans ? "Да" : "Нет") << endl;
}

//17
void money() {
    int n = readValue<int>("Введите число копеек");
    int l = n % 10;
    string output;

    if (n >= 11 && n <= 19) {
        output = " копеек";
    }
    else if (l == 1) {
        output = " копейка";
    }
    else if (l == 2 || l == 3 || l == 4) {
        output = " копейки";
    }
    else {
        output = " копеек";
    }

    cout << n << output << endl;
}

//18
void palindrome(){
    string n = readValue<string>("Введите число");

    bool ans = (n[0] == n[3] && n[1] == n[2]);
    cout << (ans ? "палиндром" : "не палиндром") << endl;
}

//19
void task19(){
    string a = readValue<string>("Введите число");
    int b = readValue<int>("Введите b");

    int sum = 0;
    int mult = 1;
    for (char i : a){
        sum += i - '0';
        mult *= i - '0';
    }

    cout << "19.1: " << ((mult > b) ? "да" : "нет") << "; 19.2: " << ((sum % 7 == 0) ? "да" : "нет") << endl;
}

//20
void rectangles(){
    double a = readValue<double>("Введите a");
    double b = readValue<double>("Введите b");
    double c = readValue<double>("Введите c");
    double d = readValue<double>("Введите d");

    cout << ((a * b < c * d) ? "можно" : "нельзя") << endl;
}

int main() {
    void (*funcptr[])() = {leave, trapArea, circleLenghtArea, triangleHypoArea, sumOfDigits, decToPolar, polarToDec,
    roots, medianOfMedian, myTime, equalSides, discount, weight, multiplicationTest, cost, month, happyNumber, money, palindrome, task19, rectangles};
    int choice;

    while(true){
        cout << "Enter the number of the task you'd like to check (from 1 to 20)\nEnter 0 to exit" << endl;
        cin >> choice;
        
        funcptr[choice]();

        cout << endl;
    }
    

    return 0;
}
