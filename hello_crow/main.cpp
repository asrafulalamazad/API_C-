#include "crow_all.h"
using namespace std;

int main(int argc,char* argv[]){
    crow::SimpleApp app;

    CROW_ROUTE(app,"/")
        ([](){
            return "<div><h1> <i>knock,knock</i> <b>frog</b> </h1></div>";
        });
    
    char* port = getenv("PORT");
    uint16_t newPort = static_cast<uint16_t>(port !=NULL ? stoi(port) : 18080);
    cout << "PORT =" << newPort << endl;
    app.port(newPort).multithreaded().run(); 
}