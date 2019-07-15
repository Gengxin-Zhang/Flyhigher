/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Logger.h"
#include "../main/systems/Engine.h"
#include <iostream>
#include <ctime>
using std::cout, std::endl, std::time, std::localtime;

/**
 * Logger implementation
 */
//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

Logger::Logger(const string file) {
    out = ofstream(file);
}

Logger::~Logger() {

}

void Logger::out_time() {
    char str[20];
    time_t now = time(0);
    tm *ltm = localtime(&now);
    strftime(str, 26, "%Y-%m-%d %H:%M:%S", ltm);
    out<<str;
    cout<<str;
}

void Logger::debug(const string str, const long num) {
    if(Engine::isDebugMode()){
        out<<"[debug][";
        cout<<RED<<"[debug][";
        out_time();
        out<<"]"<<str<<num<<endl;
        cout<<"]"<<str<<num<<endl;
    }
}

void Logger::debug(const string str, const int num) {
    if(Engine::isDebugMode()){
        out<<"[debug][";
        cout<<RED<<"[debug][";
        out_time();
        out<<"]"<<str<<num<<endl;
        cout<<"]"<<str<<num<<endl;
    }
}

void Logger::debug(const string str) {
    if(Engine::isDebugMode()){
        out<<"[debug][";
        cout<<RED<<"[debug][";
        out_time();
        out<<"]"<<str<<endl;
        cout<<"]"<<str<<endl;
    }
}

void Logger::debug(const string str, const bool flag) {
    if(Engine::isDebugMode()){
        out<<"[debug][";
        cout<<RED<<"[debug][";
        out_time();
        out<<"]"<<str<<flag<<endl;
        cout<<"]"<<str<<flag<<endl;
    }
}

void Logger::infomation(const string str, const long num) {
    out<<"[info][";
    cout<<WHITE<<"[info][";
    out_time();
    out<<"]"<<str<<num<<endl;
    cout<<"]"<<str<<num<<endl;
}

void Logger::infomation(const string str, const int num) {
    out<<"[info][";
    cout<<WHITE<<"[info][";
    out_time();
    out<<"]"<<str<<num<<endl;
    cout<<"]"<<str<<num<<endl;
}

void Logger::infomation(const string str) {
    out<<"[info][";
    cout<<WHITE<<"[info][";
    out_time();
    out<<"]"<<str<<endl;
    cout<<"]"<<str<<endl;
}

void Logger::infomation(const string str, const bool flag) {
    out<<"[info][";
    cout<<WHITE<<"[info][";
    out_time();
    out<<"]"<<str<<flag<<endl;
    cout<<"]"<<str<<flag<<endl;
}

void Logger::warning(const string str, const long num) {
    out<<"[warn][";
    cout<<YELLOW<<"[warn][";
    out_time();
    out<<"]"<<str<<num<<endl;
    cout<<"]"<<str<<num<<endl;
}

void Logger::warning(const string str) {
    out<<"[warn][";
    cout<<YELLOW<<"[warn][";
    out_time();
    out<<"]"<<str<<endl;
    cout<<"]"<<str<<endl;
}

void Logger::warning(const string str, const bool flag) {
    out<<"[warn][";
    cout<<YELLOW<<"[warn][";
    out_time();
    out<<"]"<<str<<flag<<endl;
    cout<<"]"<<str<<flag<<endl;
}

void Logger::severe(const string str, const long num) {
    out<<"[severe][";
    cout<<BOLDRED<<"[severe][";
    out_time();
    out<<"]"<<str<<num<<endl;
    cout<<"]"<<str<<num<<endl;
}

void Logger::severe(const string str, const int num) {
    out<<"[severe][";
    cout<<BOLDRED<<"[severe][";
    out_time();
    out<<"]"<<str<<num<<endl;
    cout<<"]"<<str<<num<<endl;
}

void Logger::severe(const string str) {
    out<<"[severe][";
    cout<<BOLDRED<<"[severe][";
    out_time();
    out<<"]"<<str<<endl;
    cout<<"]"<<str<<endl;
}

void Logger::severe(const string str, const bool flag) {
    out<<"[severe][";
    cout<<BOLDRED<<"[severe][";
    out_time();
    out<<"]"<<str<<flag<<endl;
    cout<<"]"<<str<<flag<<endl;
}

