class Vector {
    double x_, y_;
public:
    Vector(double x = 0, double y = 0) {
        x_ = x; y_ = y;
    }
    void print(int precision = 2, bool newLine = true) {
        cout << setprecision(precision) << fixed << "(" << x_ << ", " << y_ << ")" << (newLine ? endl : "");
    }
};
