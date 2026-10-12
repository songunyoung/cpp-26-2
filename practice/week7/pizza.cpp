int main(){
    Circle pizza1,pizza2;


    pizza1.radius =100;
    pizza1.color = "blue";
    cout << "피자의 면적=" << pizza1.CalcArea() << "\n";

    pizza1.radius = 200;
    pizza1.color = "white";
    cout << "피자의 면적=" << pizza2.CalcArea() << "\n";
    return 0;
}

