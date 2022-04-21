class vehicle {
    public:
        string colour;
    virtual void print(){
        cout<<"vehicle"<<endl;
    }
}
class car : public vehicle{
    public:
        int gears;
    void print(){
        cout<<"car"<<endl;
    }
}
int main (){
    vehicle v;
    car c;
    v.print();
    c.print();
    vehicle *v1=new vehicle;
    vehicle *v2;
    //v2 = &v1
    v2 = &c;
    v1->print();
    v2->print();
}

virtual void print()=0