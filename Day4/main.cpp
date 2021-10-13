#include "workshop.hpp"


/* class Date {

private:
int year;
int month;
int day;

};
 */


int Record::number_of_instances_ = 0;
int main() {
    Workshop ws;

    ws.AddCustomer("kalle");
    ws.AddCustomer("Nisse");

    ws.PrintCustomers();
    ws.AddRecord("ABC123");
    //ws.AddRecord("ABC123", ws.parts_.engine, ws.services_.basic);
    
    return 0;
}