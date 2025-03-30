#include <iostream>
using namespace std;
 
class Time {
public:
    Time(int seconds = 0): seconds(seconds) {
    }
 
    Time operator-() const {          
        Time lhs(*this);             
        lhs.seconds -= 60;          
        return lhs;
    }
 
private:
    int seconds;
};
 
int main() {
    Time T(120);        
    Time timeDecrementation= -T;     
    cout << timeDecrementation << endl;
 
    return 0;
}