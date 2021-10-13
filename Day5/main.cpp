class Shape {
    
  public:
    Shape(const int &a, const int &p):area_(a),perimeter_(p){}
    virtual ~Shape() = 0;
  private:
    int area_;
    int perimeter_;
};
class Circle : public Shape {
  public:
    Circle(int &r) : Shape(3 * r * r, 2 * r *3) {}
    ~Circle() = default;

};
class Triangle : public Shape {
  public:
    Triangle(const int &w, const int &h) : Shape(w * h / 2, 3 * h) {}
    ~Triangle() = default;
};
class Square : public Shape {
  public:
    Square(const int &w, const int &h) : Shape(w * h, 2 * h + 2 * w) {}
    ~Square() = default;  
};
class Rectangle : public Shape {
  Rectangle(const int &w, const int &h) : Shape(w * h, 2 * h + 2 * w) {}
  ~Rectangle() = default;
  
};