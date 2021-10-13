#ifndef PAYMENT_HPP_
#define PAYMENT_HPP_

enum class PaymentMethod {
    kCash,
    kCredit,
    kApp
};

class Payment {
public:
Payment(PaymentMethod method, int amount) : method_(method), amount_(amount) {}
    PaymentMethod method_;
    int amount_;
};

#endif