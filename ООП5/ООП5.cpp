// абстрактные классы + домашка

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <chrono>
// абстактные классы, это классы в которых объекты создавать нельзя


// ромбовидное наследование занятие от 19.10.2023

class Transport {
public:
    Transport() = default;
    Transport(std::string newName, int counter) : Name(newName), passengerCounter(counter){}

    void setName(std::string newName) {
        Name = newName;
    }

    virtual void MakeSound() = 0;
    virtual void Move() = 0;

    std::string getName() {
        return Name;
    }


    std::string Name;
    int passengerCounter;


    virtual ~Transport(){}
    
};

class DvS : virtual public Transport {
public:
    DvS() = default;


    void MakeSound() override {
        std::cout << "ВИиииию, Виииииууу, Виююююююю" << "\n";
    }

    int cylinders;
    int Power;
};

class El_engine: virtual public Transport {
public:
    El_engine() = default;


    void MakeSound() override {
        std::cout << "ТУУУУУУУУУУУ" << "\n";
    }

    int el_h_Power;

};

class Human_power : virtual public Transport {
public:
    Human_power() = default;

    void MakeSound() override {
        std::cout << "топот ног и тяжёлое дыхание человека" << "\n";
    }

    int hum_power;

};





class Gibrid_car : public DvS, public El_engine  {
public:
    Gibrid_car() = default;
    Gibrid_car(int new_power, int new_el_h_power, std::string NewName, int pasCounter,int cilinders_count) :
        Transport(NewName, pasCounter), DvS(), El_engine(){
        el_h_Power = new_el_h_power;
        Power = new_power;
        cylinders = cilinders_count;

    }

    void MakeSound() override {
        DvS::MakeSound();
        El_engine::MakeSound();
    }

    void Move() override {
        std::cout << "звук кручения колёс электромашины - едет" << "\n";
    }
};



class Car : virtual public DvS {
public:
    Car() = default;
    Car(int new_power,std::string NewName, int pasCounter, int cylinders_count) :Transport(NewName, pasCounter), DvS(){
        Power = new_power;
        cylinders = cylinders_count;
    }

    void MakeSound() override {
        DvS::MakeSound();
    }
    void Move() override {
        std::cout << "звук кручения колёс машины - едет" << "\n";
    }

};


class Riksha : virtual public Human_power { //повозка из Индии
public:
    Riksha() = default;
    Riksha(std::string newName, int new_power, int pas_count) :Transport(newName, pas_count), Human_power() {
        hum_power = new_power;
    }

    void MakeSound() override {
        Human_power::MakeSound();
    }
    void Move() override {
        std::cout << "звук кручения колёс повозки  - едет" << "\n";
    }




};






class A{
public:
    A() = default;
    A(int newId, std::string newName) :
        id(newId),
        name(newName) {}


    int id;
    std::string name;


    virtual ~A(){} // виртуальный деструктор обязателен
};

class B : virtual  public A {
public:
    B() = default;
    std::string model;

};

class C : virtual public A {
public:
    C() = default;
    C(int newId, std::string newName, int psc) :
        A(newId, newName),
        passcode(psc) {}


    int passcode;
};

class E : public B, public C{ // множественное наследование
public:
    E() = default;
    E(int id, int passcode, std::string name, std::string model) :
        A(id, name),C(), B(){
        this->model = model;
        this->passcode = passcode;

    }
}; 

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    //A objA;
    //B objB;
    //C objC;
    //E objE;
    //objA.id;

    //objB.model;
    //objB.name="321ytrewq";

    //objC.passcode = 5678;
    //objC.name = "qwerty123";

    //objE.model;
    //objE.passcode;
    //objE.B::id = 9; // у класса B есть id и в классе С есть id -> 
    //               //при наследовании двух классов мы наследуем два разных поля id-> нужно указывать, к какому поля id мы обращаемся
    //               // решение проблемы - виртуальное наследование

    //objE.id = 9;
    std::vector<Transport*> auto_park;
    auto_park.push_back(new Car{500, "bmw 5", 3, 8});
    auto_park.push_back(new Riksha{ "Рикша", 50, 2 });
    auto_park.push_back(new Gibrid_car{400, 150, "Mercedes EQS", 3, 6 });
    for (auto& el : auto_park) {
                std::cout << el->Name << "\n";
                el->MakeSound();
                el->Move();
                
            }


    return 0;
}
//_______________________________________

class Beast {
public:
    Beast(int new_Age): age(new_Age){}
    virtual void Feed() = 0; 

   
    virtual void move() = 0; // отсутствие реализации, неполный тип -> компилятор в афиге -> объекты этого класса создавать нельзя
    virtual void Sound() = 0;

    std::string GetName() const{
        return name;
    }

    std::string GetFood() const {
        return Food;
    }

    void SetName(std::string newName) {
        name = newName;
    }
    void SetFood(std::string newFood) {
        Food = newFood;
    }



    virtual ~Beast(){}

private:
    int age;
    std::string name;
    std::string Food;
};

class Dog : public Beast {
public:
    Dog(int new_Age) :Beast(new_Age){
        this->SetName("пёсиииииль");
        this->SetFood("корм");
    }

    void Feed() override {
        std::cout << this->GetName() << "сьел " << this->GetFood() << "\n";
    }
    void Sound() override {
        std::cout << " woof "<< "\n";
    }

    void  move() override {
        std::cout << " топ топ топ " << "\n";
    }

};


class Fish : public Beast {
public:

    //std::string Get;

    Fish(int new_Age) :Beast(new_Age) {
        this->SetName("а я рыба я рыба я рыба");
        this->SetFood("водоросль");
    }
    void Feed() override {
        std::cout << this->GetName() << "сьел " << this->GetFood() << "\n";
    }

    void Sound() override {
        std::cout << "буль буль буль"<<"\n";
    }

    void  move() override {
        std::cout << "плавает, буль буль буль " << "\n";
    }

private:
    std::string foodForFish;

};

class Bird: public Beast{
public:

    Bird(int new_Age) :Beast(new_Age) {
        this->SetName("птицаааааааааааа");
        this->SetFood("рыбка");
    }
    void Feed() override {
        std::cout << this->GetName() << "\t" << " сьел " << this->GetFood() << "\n";
    }
    void Sound() override {
        std::cout << "aaaar aaaaar"<<"\n";
    }

    void  move() override {
        std::cout << " летает " << "\n";
    }



};
// реализовать наследников (пользоваться будем указателем на beast)
// создать зоопарк 


//class A {
//    void M00() {}
//};
//
//class B : public A {
//
//};
//
//class C : public A {
//
//};
//
//class Linked {
//public:
//
//    virtual A* GetA() {
//        return new A;
//    }
//
//};
//
//class Derived : public Linked {
//    A* GetA() override {
//        return new B;
//    }
//};
//
//class Derived_2 : public Linked {
//    A* GetA() override {
//        return new C;
//    }
//    
//};


//int main2()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    setlocale(LC_ALL, "ru");
//
//    int age = 1;
//    std::string eda{ "едаааа" };
//    std::vector<Beast*> zoo;
//    zoo.push_back(new Bird{ age });
//    zoo.push_back(new Dog{ age });
//    zoo.push_back(new Fish{ age });
//
//    for (auto& el : zoo) {
//        std::cout << el->GetName() << "\n";
//        el->Sound();
//        el->move();
//        el->Feed();
//    }
//    using std::chrono::seconds;
//   //std::this_thread::sleep_for(seconds(5));
//
//    return 0;
//}

